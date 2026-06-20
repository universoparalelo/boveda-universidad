> Una **pila** (o _stack_ en inglés) es una estructura de datos lineal que almacena y recupera elementos siguiendo el principio **LIFO** (Last In, First Out). Esto significa que el **último elemento en entrar es el primero en salir**, de forma muy similar a cómo funciona una pila de platos en la vida real.

```python
after_eip = b'C'*200
```
- Al correr el programa en SLMail se habra pausado
- Si vemos el registro ESP y con click derecho follow in dump veremos todos los registros donde siguen esas Cs 
- A partir de que conocemos las letras (porque las pusimos nosotros) sabemos en que direccion empieza a inyectarse las C 
- Sabemos donde se va a ir el codigo que inyectaremos o el codigo manipulado.
- En este caso vienen despues del registro ESP

### Tactica
- El EIP es el registro que le dice a la compu que instruccion proxima ejecutar.
- Aqui es donde inyectamos el codigo malicioso.
- Pero no podemos hacer que EIP apunte directamente al ESP, sino que debe apuntar a otro registro que aplique un jump (salto) al ESP recien.

### Problemas
- Muchos caracteres no son interpretados, los puede tomar como varchar.
- Es como mandarle una 'D' y que el programa diga 'No, eso es una Z' por algun motivo.
- Debemos determinar que caracteres los toma como varchar, esto depende de cada programa.

## Generar un bitearray
### Deteccion de badchars
- Para setear todo, dentro de ID (inmunity debugger):
```
!mona config -set workingfolder C:\Users\savitar\Desktop\Analysis
```
- Crear un bytearray con mona en ese directorio que configuramos:
```
!mona bytearray
```

- El null byte \x00 suele dar problemas porque representa el final de la cadena
- Para generar un shellcode que no tenga un null byte:
```
!mona bytearray -cpb "\x00"
```
- Ahora hay que ver que caracter no fue representado

### Compartir el recurso hacia un linux
```
impacket-smbserver smbFolder $(pwd) -smb2support
```
- Montamos un servidor desde el linux.

- Desde el explorador de archivo \\ip-windows\smbFolder
- Copiamos el bytearray en la carpeta y listo lo ponemos en after_eip y ejecutamos el python

### Automatizar
```
!mona compare -a 0xdireccionESP -f C:\\Users\Savitar\Desktop\Analysis\bytearray.bin
```
- En este caso con \x00 \x0a hay error.
- Corregimos el payload en el python y volvemos a reiniciar SLMail y ejecutamos.
- Repetimos hasta que se representen bien todos los caracteres.