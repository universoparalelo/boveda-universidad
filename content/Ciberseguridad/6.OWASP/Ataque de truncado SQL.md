> El ataque de truncamiento SQL (SQL Truncation) es una técnica maliciosa donde un atacante explota la capacidad limitada de un campo de base de datos (por ejemplo, VARCHAR(20)). Al ingresar datos excesivamente largos, la base de datos trunca (elimina) el exceso para ajustarlo, lo que puede resultar en la sobrescritura de datos existentes o la elusión de validaciones de seguridad.

## Laboratorio
- IA: tornado - [[vulnhub]]
	- En este lab podemos hacer mucho directory listing y ahi encontramos paginas interesantes
## Ataque
- En la pagina de registro de usuario si escribimos un nombre nos da un limite de 13 caracteres.
- Si leemos el html vemos que nos dice max-length=13 esto es una limitacion desde la base de datos.
- Como este limite se coloca desde el lado de usuario y nos permite verlo significa que tenemos ese conocimiento mas facilmente.
- Ahora para explotarlo podemos hacer una enumeracion de usuarios y agarramos un nombre
- `ejemp@ejem.com` - 13 caracteres, el limite
- Ahora si queremos registrarnos con este nombre nos dara error porque este usuario ya existe.
- Si ahora eliminamos o cambiamos el maximo de caracteres para ese campo.
- Y nos registramos con `ejemp@ejem.com   a` y una contrasenia cualquiera, agregamos espacios o caracteres luego del 13avo caracter, me acepta porque es un nombre nuevo pero cuando lo inserta en la base de datos los corta en el caracter 13 y sobreescribe la contrasenia.