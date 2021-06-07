#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo ">>>Porfavor, ejecutar con permisos root para ejecutar este script, gracias."
  exit $E_NOTROOT
fi  

#Se recomienda utilizar el archivo userNOAgregados.csv para colocar los usuarios, 
#ya que este script los elimina de ese archivo y los pasa a userAgregados.csv (Solo si se crea el usuario correctamente)
file=$1
if [ "${file}X" = "X" ];
then
   echo ">>>Debe indicar el archivo del listado con Nombres de los usuarios como parametro en el comando"
   echo ">>Se recomienda usar el archivo userNOAgregados.csv"
   exit 1
fi

# Del archivo con el listado de usuarios a ingresar (userNOAgregados.csv):
# Este es el formato:
# ejemplo1:1234_JPC:575:0:B0-P.ABIERTAS JULIO PONCE:/home/ejemplo:/bin/bash
#    |	     |       |  |             |                  |           |
#    f1     f2      f3  f4           f5                 f6          f7
#$f1 = nombreUsuario
#$f2 = password (Se cambiara al primer inicio de sesion)
#$f3 = User ID
#$f4 = Group ID (GID)
#$f5 = User ID Info
#$f6 = home directory
#$f7 = comand shell
echo " "
echo ".....................CREACION DE USUARIOS........................"
echo " "

echo ">>>Estructura inicial directorio /home:"
echo "Carpetas dentro de /home:"
ls -1 /home
#Variables para saber cuantos usuarios se agregaron correctamente y cuantos no
agregados=0
rechazados=0
echo " "
#La variable verificacion acumula el numero de errores al verificar los datos
verificacion=0
crearUsuario(){
	echo "--------------->>> Crear usuario  <<<-------------------"
	eval Usuario="$1"
	f1=`echo $Usuario | cut -d ':' -f 1`
	f2=`echo $Usuario | cut -d ':' -f 2`
	f3=`echo $Usuario | cut -d ':' -f 3`
	f4=`echo $Usuario | cut -d ':' -f 4`
	f5=`echo $Usuario | cut -d ':' -f 5`
	f6=`echo $Usuario | cut -d ':' -f 6`
	f7=`echo $Usuario | cut -d ':' -f 7`

	echo "-Nombre del usuario:  ${f1}"
    		validacionUsername "${f1}"
	  #-p, --password PASSWORD
    #Note: This option is not recommended because the password (or encrypted password) will be visible by users listing the processes.
    #You should make sure the password respects the system's password policy.
	echo "-Password:  ${f2}"
	echo "-ID de usuario: ${f3}"
    	echo "-ID del grupo:  ${f4}"
    		validacionGrupoID "${f4}"
	echo "-Informacion de usuario:  ${f5}"
	echo "-Directorio home:  ${f6}"
		validacionHome "${f6}"
	echo "-Command shell:  ${f7}"

	if [[ $verificacion -eq 0 ]]
	then
		useradd "${f1}" -p "${f2}" -u "${f3}" -g "${f4}" -c "${f5}" -d "${f6}" -m -s "${f7}"

		if [ $? -eq $SUCCESS ];
		then
			cifrarPass "${f1}" "${f2}"
			echo "	>> Usuario [${f1}] agregado correctamente... <<"
			echo "${Usuario}" >> userAgregados.csv && sed -i "/${f1}/d" userNOAgregados.csv
			agregados=$((agregados+1))
		else
			echo "	<< Usuario [${f1}] No se pudo agregar... >>"
			rechazados=$((rechazados+1))
		fi
	else
        	echo "	<< Usuario [${f1}] No se pudo agregar... >>"
		echo "Porfavor, corregir los datos marcados con | <<----X |."
		echo "			    Total de errores= ${verificacion}"
		rechazados=$((rechazados+1))
	fi
	echo " "
        echo "<<--------------------------------------------------------->>"
        echo " "

	verificacion=0
}
validacionUsername(){
	username="$1"
	 if grep -q "${username}" /etc/passwd
        then
                echo "      El usuario -> ${username} <- ya existe:"
                cat /etc/passwd | grep $username
                echo "      Se requiere otro nombre diferente...  <<-------X"
		verificacion=$((verificacion+1))
        else 
		echo "      El nombre del usuario -> ${username} <- no existe,Esta disponible para usar."
	fi
}
validacionGrupoID(){
	id="$1"
	s=`grep -c "${id}" /etc/group`
        if [[ $s -eq 1 ]]
	then
		echo "      El grupo con ID -> ${id} <- existe en el sistema."
		cat /etc/group | grep "${id}"
	else
                echo "      El Grupo con ID -> ${id} <- no existe:"
                echo "      No es posible ingresar al usuario en un grupo que no existe <<------------X"
		verificacion=$((verificacion+1))
        fi
}
validacionHome(){
	homeU="$1"
	echo "      Directorio home principal: /home"
	directorio=`grep -o "/" <<< "${homeU}" | wc -l`
	echo "      Numero de / del directorio a agregar= ${directorio}"
	if [[ $directorio == 0 ]]
	then
		echo "      El dato -> ${homeU} <- no es un directorio, por lo cual no se puede usar como Home <<---------------X"
		verificacion=$((verificacion+1))
	else
		echo "      El dato -> ${homeU} <- es un directorio correcto"
		if [ -d "$homeU" ]
		then
        	        echo "      El directorio -> ${homeU} <- ya existe con otro usuario <<-----------X"
               		 verificacion=$((verificacion+1))
       		 else
                	echo "      El directorio -> ${homeU} <- esta disponible "
       		 fi
	fi
}
cifrarPass(){
	user="$1"
	pass="$2"
	echo "${user}:${pass}" | chpasswd --md5
	echo "Contraseña cifrada con el algoritmo de MD5: "
	cifrado=`cat /etc/shadow | grep "${user}"`
  	echo "${cifrado}" | cut -d ':' -f 2
	echo " "

}


while IFS=: read -r f1
do
	crearUsuario "\${f1}"	
done < ${file}

echo ">>>Estructura final directorio /home:"
echo "Carpetas dentro de /home"
ls -1 /home
echo "<<-------------------------------------------------->>"

echo "->Usuarios agregados correctamente= ${agregados}"
echo "->Usuarios que no se pudieron agregar= ${rechazados}"
echo " "
exit 0
