#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

#Se recomienda utilizar el archivo gruposAgregados.csv para colocar los grupos a eliminar, 
#ya que este script los elimina de ese archivo y los pasa a gruposNOAgregados.csv (Solo si se elimina el grupo correctamente)
file=$1
if [ "${file}X" = "X" ];
then
   echo ">>Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   echo ">>Se recomienda el archivo gruposAgregados.csv"
   exit 1
fi

# Del archivo con el listado de grupos a ingresar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo
	echo "...........ELIMINACION DE GRUPOS............"
#Variables para saber cuantos usuarios se eliminan correctamente y cuantos no
eliminados=0
rechazados=0

eliminarGrupo(){
	echo "------------> Eliminar grupo <<------------"
	eval nombreGrupo="$1"
	echo " "
	echo "Nombre del grupo  = ${nombreGrupo}"
	existe=`cat /etc/group | grep -c ${nombreGrupo}`
	if [[ $existe -eq 1 ]]
	then
		informacion=`cat /etc/group | grep ${nombreGrupo}`
		echo "-Informacion del grupo en /etc/group"
		echo "  ${informacion}"
		groupdel "${nombreGrupo}"
		if [ $? -eq $SUCCESS ];
		then
			echo "${nombreGrupo}" >> gruposNOAgregados.csv && sed -i "/${nombreGrupo}/d" gruposAgregados.csv 
			echo "Grupo [${nombreGrupo}] eliminado correctamente..."
			eliminados=$((eliminados+1))
		else
		cont=cont+1
		echo "Grupo [${nombreGrupo}] No se pudo eliminar..."
		rechazados=$((rechazados+1))
		fi
	else
		echo " "
		echo "	<< El grupo [${nombreGrupo}] no existe, por lo cual no hay necesidad de esta accion >>"
		echo " " 
		rechazados=$((rechazados+1))
	fi
	echo " "
	echo "<----------------------------------------------->"
	echo " "
	existe=0
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}
echo "->Grupos eliminados correctamente= ${eliminados}"
echo "->Grupos que no se pudieron eliminar= ${rechazados}"
echo " "

exit 0
