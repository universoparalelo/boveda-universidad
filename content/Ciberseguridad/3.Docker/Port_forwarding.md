- Se refiere a elegir un puerto nuestro para exponerlo y que sea el mismo que tiene el contenedor.

> Dockerfile
```dockerfile
FROM ubuntu:latest

LABEL maintainer="creador del universo creador_del_universo@gmail.com"

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y net-tools \
	iputils-ping \
	git \
	nano \
	curl \
	apache2 \
	php

EXPOSE 80

CMD ["apache2ctl","-D","FOREGROUND"]
# ENTRYPOINT service apache2 start && /bin/bash
```

`docker build -t my_first_server .`

```
docker run -dit -p 80:80 --name myWebServer my_first_server
```
- `-p 80:80` quiero que mi puerto 80 se convierta en el puerto 80 del contenedor

`docker port myWebServer` -> visualizamos los puertos ocupados por los contenedores activos y su referencia al nuestro real.

```
docker run -dit -p 80:80 -v ruta/de/tu/directorio/local:ruta/del/contenedor --name myWebServer my_first_server
```
- `-v ruta/local:ruta/contenedor` -> Supongamos que hay un directorio en tu maquina local que quieres que este tambien en la maquina virtual, entonces utilizas esto.
- Si no lo puedes configurar directamente en el Dockerfile agregando esta linea
- `COPY prueba.txt /var/www/html/` dentro del Dockerfile

## Visualizar que sucede dentro del contenedor
`docker logs <container-id>`
`docker logs <container-id> -f`