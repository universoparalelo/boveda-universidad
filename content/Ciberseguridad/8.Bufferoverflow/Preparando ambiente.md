### Descargando sistema
- Descargar **Windows 7 download 32 bits**
- [Este es un video de confianza](https://www.youtube.com/watch?v=_PeNp-A0olw)
- [Link de descarga .iso](https://www.mediafire.com/file/miw9804l93cg2od/WIN_7_32-64_BITS.iso/file)

### Creando la maquina virtual
- Nombre de la maquian: windows 7 home basic
- Version 32 bits x86
- Tus datos: name y password
- Espacio: 32gb single file
- Ram: 4gb ram
- Procesador: 2 hilos
- Agregar: vbox guest additions
- Agregar: chrome https://www.google.com/intl/es_us/chrome/other-platforms/ para windows 32 bits a traves de una carpeta compartida automontada

### Para redimensionar
- Una vez que montado todo deberiamos instalarnos primero la guest additions de virtual box y luego chrome.
- Luego si en Ver -> Ajustar a pantalla deberia funcionar.

### Instalando cosas
- Buscar `immunity debugger` - es un depurador de 32 bits para windows
- Download debugger inmunity
- Rellenar con lo que sea el formulario
- Ejecutar, si, aceptar terminos y condiciones, close, ok, instala python, next, next

### Deshabilitar DEP 
- Buscar `desabilitar DEP` 
	- Abrir el cmd, escribir `bcdedit .exe /set {current} nx AlwaysOff`

### Descargar mona
- Repositorio Corelan Repository for mona.py
- Descargas el mona.py
- Creamos un archivo de texto y copiamos el mona.py
- move mona.py.txt mona.py
- C:/programfiles/inmunitync/inmnitydebugger/pycommands
- Pegamos el mona.py

### Desactivando firewall
- Windows firewall
- turn windows firewall on/off
- turn off en ambos

### Descargar SLmail5.5
- slmail 5.5 download
- run
- Para buscar vulnerabilidades `searchsploit slmail 5.5`
- La password es la vulnerable
- Slmail configuration
- Dentro de control, deberia estar activo (aparece como un semaforo)
- `telnet 192.168.111.97 110`
	USER test
	PASS test
