#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

#Se recomienda utilizar el archivo userAgregados.csv para colocar los usuarios a eliminar, 
#ya que este script los elimina de ese archivo y los pasa a userNOAgregados.csv (Solo si se elimina el usuario correctamente)
file=$1
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a eliminar..."
   echo ">>Se recomienda el archivo userAgregados.csv"
   exit 1
fi
echo ">>>Estructura inicial del directorio /home:"
echo "Carpetas dentro de /home:"
ls -1 /home
echo " "

# Del archivo con el listado de usuarios a eliminar (userAgregados.csv):
# Este es el formato:
# ejemplo
#    |
#    f1
#$f1 = username
#O bien este script tambien acepta colocar toda la informacion completa del usuario como:
#ejemplo1:1234_JPC:575:0:B0-P.ABIERTAS JULIO PONCE:/home/ejemplo:/bin/bash
#   |
#  f1
#$f1 = username (Solo toma el nombre del usuario, por lo cual es importante que este bien colocado)

echo " "
echo "........................ELIMINACION DE USUARIOS........................."
echo " "
echo " "
#Variables para saber cuantos usuarios se agregaron correctamente y cuantos no
eliminados=0
rechazados=0

eliminarUsuario(){
	echo "----------------> Eliminar Usuario <---------------------"
	eval user="$1"
	f1=`echo $user | cut -d ':' -f 1`
	echo "-Nombre usuario = ${f1}"
	existe=`cat /etc/passwd | grep -c ${f1}`
	if [[ $existe -eq 1 ]]
	then
		echo "-Informacion general del usuario en /etc/passwd"
		info=`cat /etc/passwd | grep ${f1}` 
		echo " ${info}"
		echo " "
		userdel -r "${f1}"
		if [ $? -eq $SUCCESS ];
		then
			echo "		>> Usuario [${f1}] eliminado correctamente...<<"
			echo "${user}" >> userNOAgregados.csv && sed -i "/${f1}/d" userAgregados.csv
			eliminados=$((eliminados+1))
		else
			echo "		<<Usuario [${f1}] No se pudo eliminar...>>"
			rechazados=$((rechazados+1))
		fi
	else
		echo " "
		echo "		<< El usuario [${f1}] no existe, por lo cual no hay necesidad de esta acción...>> "
		echo " "
		rechazados=$((rechazados+1))
	fi
	 echo " "
         echo "<--------------------------------------------->"
         echo " "
	 existe=0
}

while IFS=: read -r f1
do
	eliminarUsuario "\${f1}"
done < ${file}

echo ">>>Estructura final directorio /home:"
echo "Carpetas dentro de /home:"
ls /home
echo "<<-------------------------------------------------->>"
echo "->Usuarios eliminados correctamente= ${eliminados}"
echo "->Usuarios que no se pudieron eliminar= ${rechazados}"
echo " "

exit 0
