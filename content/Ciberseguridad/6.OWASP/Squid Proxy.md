> El Squid Proxy es un servidor web proxy-caché con licencia GPL cuyo objetivo es funcionar como proxy de la red y también como zona caché para almacenar páginas web, entre otros. Actúa como protección separando las dos redes y como zona caché para acelerar el acceso a páginas web o restringir el acceso a contenidos.


## Laboratorio
- [[sickos]] - vulnhub

## Ataque
- Realizamos un reconocimiento hacia la maquina vulnerable
- Descubrimos un puerto 3128 abierto que corresponde al servicio proxy Squid.
- Basicamente el proxy ayuda a que no podamos entrar directamente a la pagina web porque el puerto 80 aparece `filtered`, no esta abierto como tal.
- Pero si configuramos el proxy con la ip de la maquina y el puerto 3128, que es donde corre el servicio de Squid, podremos ingresar a la pagina web.
- A partir de aca podemos iniciar un descubrimiento como siempre, pero debemos aniadir el proxy
```
wfuzz -u http://192.168.100.92 --proxy 192.168.100.92:3128 -w diccionario -hc=503 -c
```
- Podemos hacer un curl tambien
```
curl http://192.168.100.92 --proxy 192.168.100.92:3128
```
- Con autenticacion
```
curl http://192.168.100.92 --proxy http://admin:password@192.168.100.92:3128
```
- Esto de por si no es una vulnerabilidad sino un servicio que debemos saber que existe