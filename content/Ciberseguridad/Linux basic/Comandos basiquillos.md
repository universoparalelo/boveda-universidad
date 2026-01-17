```
whoami
```
- El dios de los dioses, Zeus querido

```
id
```
- Para saber a que grupo perteneces

```
sudo su
```
- Para pasar de usuario comun a privilegiado para ejecutar comandos de kernel o de alto nivel, peligrosos

```
cat /etc/grupos
```
- Para ver todos los grupos existentes en el sistema

```
which whoami
command -v whoami #alternativa
```
- Vemos la ruta absoluta de donde se encuentra un programa
- Los binarios deben tener ruta absoluta `/etc/bin/whoami`

```
echo $PATH
echo $HOME
echo $SHELL
```
- Siendo `PATH` una variables de entorno permite saber cual es el orden de prioridad que tendra en cuenta el sistema para ejecutar un comando con la ruta relativa especificada aqui
- Siendo `HOME` la ruta por defecto al aplicar un cd
- Siendo `SHELL` para saber que tipo de shell utilizamos por defecto

```
cat /etc/group | grep "floppy"
```
- Ver permisos de un grupo en especifico

```
pwd
```
- Conocer donde nos encontramos

```
ls
ls -l
```
- Listar carpetas del directorio actual
- Listar carpetas y sus permisos

```
cd /carpeta
cd ..
cd /
```
- Cambiar de directorio
- Retroceder de directorio
- Ir a la raiz

```
cat /etc/passwd
cat /etc/shells
```
- Lista todos los usuarios con los permisos, identificadores, ruta por defecto, la bash que se abre, etc
- Lista todos los tipos de shell que podemos utilizar
