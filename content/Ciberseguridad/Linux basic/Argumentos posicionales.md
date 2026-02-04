- Cuando ejecutamos un archivo `./script.sh` podemos mandarle variables separadas por un espacio
- Ejemplo dde archivo
```
# ./archivo.sh
#!/bin/bash

echo $1
```
- `./archivo.sh hola` al ejecutar esto nos devuelve `hola` porque imprimimos el primer argumento que mandamos

`$0` es la bash que estamos ejecutando
`/usr/bin/zsh` en mi caso