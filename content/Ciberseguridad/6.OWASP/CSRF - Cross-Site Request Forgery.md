> El CSRF es un tipo de exploit malicioso de un sitio web en el que comandos no autorizados son transmitidos por un usuario en el cual el sitio web confía.​ Esta vulnerabilidad es conocida también por otros nombres como XSRF, enlace hostil, ataque de un clic, secuestro de sesión, y ataque automático.

## Laboratorio
```
wget https://seedsecuritylabs.org/Labs_20.04/Files/Web_CSRF_Elgg/Labsetup.zip
unzip Labsetup.zip
rm !$
cd Labsetup
docker compose up -d
```

- Hay que modificar el `/etc/hosts`
```
10.9.0.5 www.seed-server.com
10.9.0.5 www.example32.com
10.9.0.105 www.atacker32.com
```

- Ingresamos a `http://www.seed-server.com`

- Los usuarios existentes son:
```
alice:seedalice
samy:seedsamy
```

## Interceptando
- La idea de esta vulnerabilidad es replicar peticiones aprovechandonos de la falta de verificaciones que realiza el servidor por detras.
- Entonces una vez logueados como samy o alice en la seccion Profile intentemos cambiarnos el nombre y al guardar interceptar la peticion con Burp Suite.
- Al observar la peticion de POST para cambiarnos el nombre vemos la serie de datos que envia al servidor, lo pasamos el Repetidor y sobre esta peticion hacemos click derecho y Change request method, que transforma de POST a GET, eliminamos los campos de \_\_elgg_ts y \_\_elgg_token y enviamos
- En la pagina veremos que de Alice pasa a valer el nuevo nombre, lo que sacamos como conclusion es que si logramos que un usuario X ejecute esa url, porque como es GET es el default de cualquier peticion, vamos a cambiarle el nombre de perfil a cualquier persona, porque tambien vemos el id de cada usuario.

## Realizando el ataque
- En la seccion de mensajes podemos enviar un mensaje y codear en html y el sistema lo interpreta luego.
- Con esto podemos enviar `<img src="http://www.seed-server.com/edit/" alt="Hola como estas?" />` y cuando el destinatario lo abra vera solo el alt, que se despliega cuando hay problemas con la url de la imagen, y se ejecutara la url de la imagen donde le decimos que cambie el nombre de usuario.
- **Aclaracion**: en la parte de la url de /edit/ iria toda la url que ejecutamos cuando cambiamos nuestro nombre de perfil y debemos cambiar el id del usuario destinatario

## Cambiar contrasenias
- El proposito principal de este tipo de ataque es cambiar la contrasenia de un usuario (del cual no conocemos la contrasenia).
- Hay veces que para cambiar nuestra contrasenia solo debemos colocar una nueva contasenia dos veces (para verificar), si es ese caso se puede usar este ataque.
- Pero cuando se requiere colocar la anterior puede que no funcione, porque aunque eliminemos el campo de la contrasenia anterior sigue esperando la contrasenia anterior.
- Pero para que se sepa que ese es el proposito principal de este ataque.

## Caso particular
- Si la pagina no deja tramitar una peticion por GET y te obliga a usar POST podemos hacer lo siguiente dentro del comentario:
```html
<form method="POST" action="https://YOUR-LAB-ID.web-security-academy.net/my-account/change-email"> 
	<input type="hidden" name="email" value="anything%40web-security-academy.net"> 
</form> 
<script> 
	document.forms[0].submit(); 
</script>
```
- `value` debemos poner el email urlencodeado, notese que el `%40` es el arroba @
