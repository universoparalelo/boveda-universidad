> Burp Suite es una herramienta de software propietaria para la evaluación de seguridad y las pruebas de penetración de aplicaciones web.
## Herramientas
- **foxy proxy**, extension para el navegador y poder agilizar el proceso de captura.

## Proxy
- `Configuration` - Aca vemos en que puerto de forma local esta escuchando BurpSuite

## Repeater
- Una vez interceptada una peticion `ctrl_r` 
- Por aqui podemos crear las pestanias que queremos donde una vez interceptada una peticion podemos manipularla y enviarla multiples veces, viendo la respuesta y guardarla.

## Auditar una URL en particular
- `Proxy > Configuration` activamos la ultima opcion sobre no enviar items si se esta fuera del scope
- Para configurar el scope nos vamos a `Target > Scope > Add` aniadimos la url, por ej http://localhost:8000

## Interceptar  un request
- `Proxy > Intercept` presionas la opcion **Intercept is on** y en la web envias la peticion. 
- Luego para ver la respuesta podes ir a Repeater, pero sino en la misma seccion anterior `click derecho > Do intercept > Response to this request` y le das a Forward y listo

## Ataque
- `ctrl_i > Intruder`
- Podemos modificar campos que estan resaltados y seleccionar un campo como payload
- Payload hace referencia a un texto que va a cambiar su valor
- Entonces luego elegimos el tipo de ataque, generalmente `Sniper` y en `Payloads` cargamos un diccionario de palabras de `SecLists` y `Start Attack`
- Un ataque de tipo `Cluster Bump` es cuando queremos dos campos (usuario y contrasenia)
- Un ataque `Battering ram` es para dos campos pero la palabra clave se repite
- Un ataque `Pitchfork` agarra usuario y contrasenia en la misma linea del diccionario seleccionado