concepto de pila
after_eip = b'C'*200
vemos un registro ESP con muchas C
follow in dump

vemos todos los registros donde siguen esas Cs
a partir de que conocemos las letras que inyectamos sabemos donde empieza a inyectarse las C, que representan el codigo manipulado
en este caso vienen despues del registro ESP

no podemos hacer que eip apunte directamente al esp, sino que debe apuntar a otro registro que aplique un jump (salto) al esp recien.

a tener en cuenta: muchos caracteres no son interpretados, los puede tomar como varchar

Debemos determinar que caracteres los toma como varchar, esto depende de cada programa.

!mona config -set workinfolder C:\Users\savitar\Desktop\Analysis
!mona bytearray
crea un bytearray
el null byte \x00 suele dar problemas porque representa el final de la cadena
generar un shellcode que no tenga un null byte
!mona bytearray -cpb "\x00"
Ahora hay que ver que caracter no fue representado

impacket-smbserver smbFolder $(pwd) -smb2support
recurso compartido que se sincronice con el directorio actual
explorador de archivo \\ip\smbfolder
copiamos el bytearray en la carpeta y listo
lo ponemos en after_eip

!mona compare
c elegi esp click derecho y copiar
!mona compare -a 0xesp 0f C:\\Users\Savitar\Desktop\Analysis\bytearray.bin
\x00 \x0a errores con esos caracteres

generamos un bytearray nuevo sin los caracteres que dan problemas
debemos cerrar programas, volver a cargar, ejecutar y leer donde se corrompio