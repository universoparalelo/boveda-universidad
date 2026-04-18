> Una condición de carrera (race condition) ocurre cuando múltiples hilos o procesos acceden y modifican un recurso compartido simultáneamente, produciendo resultados inesperados e inconsistentes. El resultado final depende del orden de ejecución, que es impredecible, comportándose como una "carrera" por llegar primero.


## Laboratorios
- [[skf-labs]]/RaceCondition
- skf-labs/RaceCondition-file-write

## Ataques
- Este ataque se puede realizar cuando en el codigo dados determinados parametros se ejecuta algo que el usuario coloco y luego se elimina porque no cumplio determinada cosa en particular.
- Pero el archivo fue creado o el comando ejecutado por milisegundos.
- Entonces esto nos permite con un bucle en paralelo estar continuamente ejecutando o escuchando el evento e interceptar el proceso de creacion y eliminacion y ver el contenido.

### Primer lab: race-condition
- Se escribe un texto que luego se guarda en un archivo .txt, luego se pasa a un .sh y si pasa una verificacion se ejecuta en la pagina.
- Si se escribe un comando como ``id`` o `$(whoami)` no se ve porque al hacer la verificacion se ejecuta un booteo, pero se creo el .sh por lo que se puede ejecutar el archivo y ver el contenido.
- Para ello en una consola:
```bash
while true; do curl -s 'http://localhost:5000/?action=run' | grep Check | html2text | xargs | grep -v hola; done
```
- Mientras que en otra:
```bash
while true; do curl -s 'http://localhost:5000/?person=`id`&action=validate' | grep hola; done
```
- En la segunda consola estamos mandando el comando que queremos ejecutar `id` mientras que en la primera veremos el resultado reflejado en algun momento.
- Ambas estan ejecutandose constantemente y eso lleva que coincidan y se pueda leer el contenido antes de borrarse.

### Segundo lab: raceCondition-file-write
- Este lab me permite crear un archivo con lo que yo le coloque en la url
- Por ejemplo:
`http://localhost:5000/hola` - crea un archivo para descargar que dentro tiene la palabra hola
- Aca podemos hacer
```
while true; do curl -s 'http://localhost:5000/hola' | grep -v hola; done
```
- Y mientras tanto:
```
while true; do curl -s 'http://localhost:5000/testing' | grep -v testing; done
```
- Ambos pueden leer lo que el otro sube porque se estan superponiendo constatemente.