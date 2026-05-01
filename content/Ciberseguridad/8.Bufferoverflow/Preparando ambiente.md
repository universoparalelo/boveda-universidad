### Descargando sistema
- Descargar **Windows 7 download 32 bits**
- Este es un sitio de confiaza **uptown.com**
- Te lo pasas de tu parrot/kali/ubuntu hacia tu windows o donde tengas tu virtualbox/vmware 
```
python -m http:server 80
```
- En la otra maquina entramos a la web en 192.168.111.45/descargar imagen de windows

### Creando la maquina virtual
- Nombre de la maquian: windows 7 home basic
- Tus datos: name y password
- Espacio: 60gb single file
- Ram: 4gb ram
- Procesador: 4 hilos

### Para redimensionar
- Una vez que apretamos 70 veces en aceptar, tenemos que ir a Dispositivos -> Agregar CD -> vboxguestaddittions seleccionado
- Vas a los documentos de windows y deberia aparecer como disco nuevo, lo presionas y empieza a instalarse y ya despues elegir la resolucion si no te lo hizo automaticamente en Ver -> pantalla

### Instalando cosas

immunity debugger - es un depurador de 32 bits para windows
desabilitar DEP 
!mona
mona.py
move mona.py.txt mona.py
pycommands pegamos el mona.py

firewall
turn windows firewall on/off

slmail 5.5 download
run
searchsploit slmail 5.5
la password es la vulnerable

telnet 192.168.111.46 110
USER test
PASS test
