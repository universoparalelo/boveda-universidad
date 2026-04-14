> Prototype pollution is **a JavaScript vulnerability that enables an attacker to add arbitrary properties to global object prototypes**, which may then be inherited by user-defined objects.

## Laboratorio
- [[skf-labs]]/nodeJS/Prototype-Pollution
- `npm install && npm start`
- `localhost:5000`

## Ataque
- Lo que sucede basicamente es que las propiedades de los objetos se pueden manipular, agregando o seteando algunas por defecto.
- Hay una funcion `merge` que permite insertar otro metodo `__proto__` que hace que un atributo determinado se coloque por defecto en tal valor, por ejemplo `"admin":true`
- Una vez que creamos una cuenta y nos logueamos se ve una seccion que dice `Admin: ` ahi es donde debe aparecer true si nos convertimos en administrador.
- Entonces utilizamos el envio de un mensaje a un administrador para manipular el envio.
- Con la peticion interceptada con [[burpsuite]]
```
{
	"email": "hola@hola.com",
	"msg": "Hola, como estas?",
	"__proto__":{
		"admin": true
	}
}
```
- Lo enviamos en formato json, por lo tanto debemos cambiar el **Content-Type** a **application/json**
- Y listo de esa forma todos los usuarios que se creen despues seran administradores por defecto.