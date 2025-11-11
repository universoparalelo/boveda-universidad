The password for the next level is stored in the file **data.txt**, which is a hexdump of a file that has been repeatedly compressed. For this level it may be useful to create a directory under /tmp in which you can work. Use mkdir with a hard to guess directory name. Or better, use the command “mktemp -d”. Then copy the datafile using cp, and rename it using mv (read the manpages!)

> Mi recorrido fue binario -> gzip -> bzip2 -> POSIX -> gzip -> bzip2 -> POSIX -> ASCII
## Comandos
```
mktemp -d
cp data.txt /tmp/nombreraro
mv data.txt salida.txt

xxd -r salida.txt > salida.bin #convierte en binario
file salida.bin #ver que tipo de dato es

#si el archivo es gzip
mv salida.bin salida.gz
gunzip salida.gz

#si el archivo es bzip2
mv salida salida.bz2
bunzip2 salida.bz2

#si el archivo es POSIX tar
tar xf salida 

#si el archivo es ASCII
cat salida
```
- cp
- mv
- xxd
- gunzip
- bunzip2
- tar
- file
## Contraseña
- FO5dwFsc0cbaIiH0h8J2eUks2vdTDwAn