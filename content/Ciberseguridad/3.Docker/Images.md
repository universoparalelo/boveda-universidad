```
docker images
```
- Visualizacion de las imagenes descargadas

## Dockerfile
- Archivo que contiene todas las instrucciones para correr maquina/s virtual/es.
- Dentro de ellos se construyen los contenedores.
```dockerfile
FROM ubuntu:latest

LABEL maintainer="creador del universo creador_del_universo@gmail.com"
```
- `FROM` elegimos un sistema operativo como base.
- Antes se utilizaba `MAINTAINER` pero eso cambio.
### Para montar la imagen
`docker build -t my_first_image .`
### Correr una imagen
`docker run -dit --name myContainer my_first_image`
- -dit le estamos diciendo que corra como un proceso independiente, que sea interactivo mediante una consola y que esos parametros los junte
### Interactuar con el contenedor
`docker exec -it myContainer bash`
### Configurar la maquina 'desnuda'
```
apt update
apt install net-tools -y
apt install iputils-ping -y
```
### Descargar imagenes de la nube
`docker pull debian:latest`
## Imagen actualizada
```dockerfile
FROM ubuntu:latest

LABEL maintainer="creador del universo creador_del_universo@gmail.com"

RUN apt update && apt install -y net-tools \
	iputils-ping \
	git \
	nano \
	curl 
```
Para construir:
`docker build -t my_first_image:v2 .`
Para correr:
`docker run -dit --name mySecondContainer my_first_image:v2`

## Eliminar imagen
`docker rmi <image-id>`
`docker rmi $(docker images -q)` borra todas las imagenes habidas y por haber

## Filtrar por imagenes que quedaron a media descarga
`docker images --filter "dangling=true"`