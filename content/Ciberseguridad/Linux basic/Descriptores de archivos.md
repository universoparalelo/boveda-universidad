```
exec 3<> file
```
- Crea un archivo `file` en el directorio actual, su identificador es `3` y tiene permisos de lectura `<` y escritura `>`
```
whoami >&3
```
- La salida de whoami se escribe `>` hacia el `3` que es file
- Asi podemos ejecutar cualquier cantidad de comandos y agregar esa informacion al archivo
```
exec 3>&-
```
- Para cerrar el archivo, ya no se puede escribir nada mas en el

```
exec 8>&5
```
- Creamos una copia de lo que tiene el archivo 5 en el 8
- Cada informacion nueva que se guarde en 5 tambien se esta guardando en el 8