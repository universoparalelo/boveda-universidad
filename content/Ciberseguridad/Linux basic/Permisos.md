## Lectura
```
touch file.txt
nano file.txt #crea el archivo y podes escribir directamente
vi hola.txt #otro editor de texto mas lindo visualmente
```
- Crear un archivo

```
echo "hola" > file.txt
```
- Escribimos dentro de file "hola", sin agregar al contenido que pueda estar dentro

```
echo "hola" >> file.txt
```
- Agrega contenido a file.txt

```
ls -l #para leer los permisos
```
- `.rw--r--r--` como al principio tiene un punto o guion es un archivo, si tiene una d es un directorio
- `r` lectura
- `w` escritura
- `x` para directorio poder ingresar, o para archivo podes ejecutar si es ejecutable
- `-rw-` | `r--` | `r--` se dividen en grupos de 3 siendo la primer terna los permisos del propietario, la segunda del grupo y la tercera de otros

```
ls -l /etc/shadow
```
- Se guardan contrasenias

## Escritura o modificacion
```
chmod o+w prueba/
```
- `chmod` es el comando para modificacion de permisos
- `o` el usuario otro, puede ser `g` para grupo o `u` de propietario
- `+w` se le agrega la posibilidad de escritura, puede ser `+r` o `+x` o una combinacion de varias
- `-w`, `-r`, `-x` para quitar permisos

```
chgrp savitar prueba/
```
- Cambia al grupo `savitar` el directorio `prueba/` que antes pertenecia a root

```
drwx-r-x-r-x --> drw--w-rw-
# mi version
chmod u-x prueba/ && chmod g-rx prueba/ && chmod g+w prueba/ && chmod o-x prueba/ && chmod o+w prueba/
# optimizada
chmod u-x,g-rx,g+w,o-x,o+w prueba/
```

## Usuario
```
useradd pepe -s /bin/bash -d /home/pepe
```
- Agregamos un usuario `pepe`
- `-s` se ejecuta una bash para ese usuario
- `-d` el home para ese usuario es `/home/pepe`

```
cat /etc/passwd # ver informacion acerca de cada usuario
passwd pepe
```
- `passwd` le agregamos una contrasenia a pepe

```
chgrp pepe /home/pepe
chown pepe /home/pepe
chown pepe:pepe pepe # matas dos pajaros de un tiro
```
- Cambiar el grupo
- Cambiar de propietario

```
groupadd Alumnos
cat /etc/groups | grep Alumnos
```
- Crear un grupo

```
usermod -a -G Alumnos pepe
```
- Agregamos a pepe al grupo Alumnos
- Crear un grupo

## Asignar permisos con octal
```
rwx|r-x|r-x
111|101|101
7|5|5
```
- Las letras son 1s y los guiones 0s y luego convertimos a decimal
```
r-x|r--|-w-
101|100|010
5|4|2
```
- Con esos valores numericos podemos hacer esto:
```
chmod 542 prueba
```
- Estamos cambiando los permisos del directorio prueba con octal

## Permisos especiales
```
chmod +t prueba
```
- Permite que solo el usuario duenio del directorio pueda eliminar archivos, incluso cuando el directorio tiene permisos de escritura para otros.
- Este permiso se conoce como **sticky bit**

```
cp /etc/hosts prueba
```
- Crear una copia de un archivo en el directorio actual

```
lsattr
```
- Lista atributos especiales de archivos y directorios

```
chattr +i -V prueba
```
- Cambiar los atributos especiales y mostrar `-V` toda la informacion obtenida del proceso 
- [Todos los atributos posibles](https://man7.org/linux/man-pages/man1/chattr.1.html)