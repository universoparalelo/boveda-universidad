```
find / --name passwd
```
- Buscar segun una palabra

```
find / -perm -4000
```
- Archivos con permisos SUID

```
find / -group wheel
```
- Archivos pertenecientes a un grupo

```
find / -group savitar -type d
find / -group savitar -type f
```
- Hallar archivos `f` o directorios `d` pertenecientes a un grupo

```
find / -user root --writable 
find / -user root --executable
```

```
find / -name dex\*
find / -name \*exd\*
find / -name dex\*.sh
```
- Distintas formas de buscar un archivo cuando no te acordas del nombre completo
