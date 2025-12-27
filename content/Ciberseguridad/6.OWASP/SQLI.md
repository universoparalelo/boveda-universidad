> SQL inyections. Que son? Generalmente cuando te logueas en cualquier pagina lo que haces al colocar el usuario y tu contrasenia es que luego eso se envia a un servidor que debe chequear que eso coincida con algun usuario y contrasenia guardado en sus base de datos. Esto que se envia se llama **query**, esta query se puede manipular para confundir a la base de datos y darnos paso libre aun sin poner contrasenias correctas, ennumerar usuarios o revelar informacion confidencial


## Herramientas
- mariabd-server
- apache2
- php-mysql

## Caso practico
```
service mysql start
lsof i:3306
```
- Para iniciar un servicio de mariadb y verificarlo
```
service apache2 start
lsof i:80
```
- Lo mismo para iniciar un servicio de apache2
- Luego ingresamos al servicio de mysql
```
mysql -uroot -p
```
- Dentro de este panel
- Para ver todas las bases de datos (creadas por defecto) `show databases;`
- Para utilizar una base de dato `use mysql;`
- Listas las tablas disponibles `show tables;`
- Ver las columnas `describe user;`
- Ver informacion de una tablas eligiendo las columnas `select user,password from user;`
- Confirmar si existe un usuario `selecto user,password from user where user = 'admin';`
- Crear una db `create Database Hacking;`
- `use Hacking;`
- Crear una tabla con las columnas y el tipo de dato`create table users(name varchar(10), password varchar(8));`
- Agregar valores `insert into users(name, password) values('admin', 'admin123');`
- Modificar un valor en una columna `update users set name='cele' where name='admin';`
---
Para conectar la bd con apache2 mediante php
`create user 'universo'@'localhost' idetified by 'paralelo22';`
Para darle todos los privilegios a ese usuario
`grant all privileges on Hacking.* to 'universo'@'localhost'`

# 15'
