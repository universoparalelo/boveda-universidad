> Un volcado o "dump" hexadecimal es una ==representación textual de datos binarios (archivos, memoria o dispositivos) mostrada en formato hexadecimal, comúnmente usado en depuración e ingeniería inversa==.

- Para crear un archivo hexadecimal con `xxd`
```
cat /etc/host | xxd
```
- Para revertir un archivo hexadecimal:
```
xxd -r data
cat data | xxd -ps | xargs | tr -d ' '
```

## Cambiar el contenido de un archivo y guardarlo en el mismo (editar)
```
sudo apt install moreutils
echo "Hola como estas" > hola.txt
cat hola.txt | awk '{print $2}' | sponge hola.txt
```
- Instalamos un paquete que contiene `sponge` que es una libreria para editar el contenido de un archivo directamente por instrucciones de consola, sin necesidad de abrir nano o nvim

- Descomprimimos el archivo `data` que esta dumpeado en hexadecimal:
```
cat data | xxd -r | sponge data
file data
```
- Con `file` nos fijamos que tipo de archivo se convierte y nos damos cuenta que es un comprimido

## Archivos comprimidos y descompresion
- La descompresión de archivos es un **proceso que restaura los datos a su estado original después de haber sido comprimidos**.
- Tipos de compresion: *gzip* *bzip2* *tar* *zip*

```
sudo apt install ghex
ghex ~/Pictures/foto.png
```
- Con la libreria `ghex` podemos obtener los hexadecimales de cualquier tipo de archivos para averiguar que tipo de archivos es
- Los numeros magicos son los primeros 4 u 8 digitos que aparece en el dump de ese archivo generado por ghex
- Con esta pagina [wikipedia/lista de tipo de archivo](https://en.wikipedia.org/wiki/List_of_file_signatures) podemos averiguar ello

```
gunzip data.gzip
bunzip2 data.bzip2
tar data.tar
unzip data.zip
```
- Diferentes librerias para descomprimir ese tipo de archivos

```
sudo apt-get install p7zip-full
7z l data.gz
7z x data.gz
```
- Descompresor de cualquier tipo de archivo comprimido
- `l` vemos que tipo de archivo es
- `x` ejecutamos la descompresion
