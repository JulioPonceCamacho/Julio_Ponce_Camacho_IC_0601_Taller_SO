#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

#Se recomienda utilizar el archivo gruposNOAgregados.csv para colocar los grupos a agregar, 
#ya que este script los elimina de ese archivo y los pasa a gruposAgregados.csv (Solo si se agrega el grupo correctamente)
file=$1
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con nombres de los grupos a ingresar..."
   echo ">>Se recomienda el archivo gruposNOAgregados.csv"
   exit 1
fi

# Del archivo con el listado de grupos a ingresar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo

#Variables para saber cuantos usuarios se agregaron correctamente y cuantos no
agregados=0
rechazados=0

	echo " "
	echo "...............CREACION DE GRUPOS..................."	
	echo " "
crearGrupo(){
	echo "<<=================================================>>"
	echo "------------------> Crear Grupo <-------------------"
	eval nombreGrupo="$1"
	echo "Nombre del grupo  = ${nombreGrupo}"
	echo " "
	#-p, --password PASSWORD
    #Note: This option is not recommended because the password (or encrypted password) will be visible by users listing the processes.
    #You should make sure the password respects the system's password policy.
	groupadd "${nombreGrupo}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] agregado correctamente..."
		echo "${nombreGrupo}" >> gruposAgregados.csv && sed -i "/${nombreGrupo}/d" gruposNOAgregados.csv
		agregados=$((agregados+1))
	else
		echo "Grupo [${nombreGrupo}] No se pudo agregar..."
		rechazados=$((rechazados+1))
	fi
	echo "<<=================================================>>"
	echo " "
}

while IFS=: read -r f1
do
	crearGrupo "\${f1}"	
done < ${file}
echo "->Grupos agregados correctamente= ${agregados}"
echo "->Grupos que no se pudieron agregar= ${rechazados}"
echo " "

exit 0
