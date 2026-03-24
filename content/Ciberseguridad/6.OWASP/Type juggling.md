> Type juggling (or type coercion) is **a feature in loosely typed languages like PHP that automatically converts variables from one data type to another during operations**, such as adding a string to an integer or using loose comparison (`==`). While convenient, it often leads to security vulnerabilities if not managed with strict comparisons (`===`).

![[Pasted image 20260324123338.png]]
- Esto es lo que pasa cuando utilizamos `==` en comparaciones.
## Laboratorio
- Para armar el escenario vulnerable iniciamos apache2 y creamos un formulario en html que se tramita con php y haga una verificacion riesgosa.
```
service apache2 start
cd /var/www/html
rm index.html
```
- Creamos un `index.php`:
```
<html>
	<body style="background-color:green">
		<font color="red"><center><h1>Secure Type Juggling</h1></center></font>
		<hr>
		<center>
			<form method="POST" >
				Usuario: <input type="text" name="username" id="username"/>
				&nbcp
				Contraseña: <input type="password" name="password" id="password"/>
				&nbcp
				<input type="submit" value="Enviar"/>
			</form>
		</center>
		
		<?php
			$USER="admin";
			$PASSWD="admin1234&^&^"
			
			if(isset($_POST['username']) && isset($_POST['password'])){
				if ($_POST['username'] == $USER){
					if(strcmp($_POST['password'], $PASSWD) == 0){
						echo "[+] Ha ingresado correctamente como administrador"				
					} else {
						echo "[!] La contrasenia proporcionada no es correcta"	
					}
				}
			}
			 
		?>
	</body>
</html>
```
- `&nbsp;` significa _non-breaking space_ (espacio de no separación) en HTML

## Inputs peligrosos
```
username=admin&password[]=
```
- Lo que hace es nose que hace la verdad
- En php 8+ ya no funciona, solucionaron el problema de que si venia un tipo de dato que no era string ya no se convierte a 0, sino que da error de tipos

## Cambio
```
<?php 
      $USER="admin"; 
      $PASSWD="0e462097431906509019562988736854"; 
      
      if(isset($_POST['username']) && isset($_POST['password'])){ 
        if ($_POST['username'] == $USER){
          $passwd_input = md5($_POST['password']);
          if($passwd_input == $PASSWD){ 
            echo "[+] Ha ingresado correctamente como administrador"; 
          } else { 
            echo "[!] La contrasenia proporcionada no es correcta"; 
          } 
        } 
      } 
?>
```
- Lo que hace es que cuando recibe la cadena `0e462097431906509019562988736854` la interpreta como 0 elevado a tanto y eso da cero, si nosotros enviamos una cadena `QNKCDZO` que luego en md5 tambien se transforma en 0eblablabla tambien dara como resultado 0 y `0=0` es true.
- Tambien llamados **hashes magicos**