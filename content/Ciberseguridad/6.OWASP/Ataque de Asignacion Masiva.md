> En ocasiones, los marcos de software permiten a los desarrolladores vincular automáticamente los parámetros de las solicitudes HTTP a variables u objetos del código del programa para facilitar su uso. Esto, sin embargo, puede resultar perjudicial. En ocasiones, los atacantes pueden utilizar esta metodología para crear nuevos parámetros que el desarrollador nunca pretendió, lo que a su vez crea o sobrescribe nuevas variables u objetos en el código del programa que no estaban previstos.

## Laboratorios
- _Juice Shop Docker_
```
docker pull bkimminich/juice-shop
docker run -dit -p 3000:3000 --name JuiceShop bkimminich/juice-shop
```

- [[skf-labs]]/ruby/parameter-binding
```
docker pull blabla13337/owasp-skf-lab:parameter-binding
docker run -it --name parameterBinding -p 3000:3000 owasp-skf-lab:parameter-binding
```
## Ataque
- En en Juice Shop cuando nos registramos si observamos la respuesta nos muestra otras caracteristicas del usuario que creamos, entre ellas aparece el "role":"admin" 
- Por lo tanto cuando creamos un nuevo usuario podemos agregarle esa caracteristica pero con el valor "admin" y listo, creamos un usuario administrador
- Debido a una mala configuracion o no aclaracion de que caracteristicas acepta se pudo utilizar caracteristicas extras para definir un usuario

- En el segundo laboratorio `localhost:5000` o `172.0.0.2:5000` hay dos usuarios y si cambiamos los detalles de uno de ellos `Guest` podemos mediante fuerza bruta (probando) diferentes nombres de campo como isAdmin isadmin admin Admin IsAdmin is_admin igualando a true y en algun momento cede.
