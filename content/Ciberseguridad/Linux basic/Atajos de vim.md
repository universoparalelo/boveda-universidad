## Para crear o escribir en un archivo con vim
`vim hola.txt`

## Modos
En vim existen tres modos, segun en el que estes los comandos varian su accion. Por defecto siempre estamos en modo normal, excepto que queramos modificar el texto (insert) o copiarlo (visual)
## Modo normal
- Es de lectura por lo tanto no podes escribir
- Podes seleccionar un texto y copiarlo
- Podes pegar texto
- Ingresas con `escape`

## Modo insert
- Es de escritura pero si te queres mover podes usar las flechas
- Poder pegar texto con `ctrl_shift_v`
- Ingresas con la `a` delante del caracter que estas parado o con `i` por detras del mismo
## Modo visual
- Este modo se usa para copiar un texto
- Ingresas desde un modo normal con la tecla `v`
## Movimiento (o las flechas de movimiento)
`h` - izquierda
`j` - abajo
`k` - arriba
`l` - derecha

`0` - inicio de linea
`$` - fin de linea

`alt+u` - deshacer

`w` - moverte por palabras
`3w` - moverte 3 palabras hacia delante
`dw` - borras una palabra
`5dw` - borras cinco palabras

`v` - entras en modo visual
`flechas o $` - una letra por vez o hasta el final de la linea
`y` - copiar la seleccion
`yy` - copiar una linea
`o` - crear una nueva linea debajo
`p` - pegar la seleccion

`.` - vuelve a repetir la ultima accion

`/` - modo busqueda

`qa` - empezas a grabar comandos
`q` -  salis del modo grabar
`30@a` - repetis los comandos grabados 30 veces

`:%s/nologin/yeslogin/g` - reemplaza **todas** las apariciones de nologin a yeslogin
`:%s/nologin/yeslogin` - reemplaza la primer aparicion de nologin a yeslogin

`:q` - salir
`:wq` - escribir y salir
`:q!` - salida forzada
