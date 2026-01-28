- Para ingresar por ssh a un servidor de forma remota:
```
ssh usuario@pagina -p 2220
ssh bandit0@bandit.labs.overthewire.org -p 2220
sshpass -p 'ZjLjTmM6FvvyRnrb2rfNWOZOTa6ip5If' ssh bandit0@bandit.labs.overthewire.org -p 2220
```

- En el nivel 2 hay un archivo que se llama `-` y se complica para leer.
```
cat home/bandit1/-
cat ./-
cat $(pwd)/-
grep -r "\w" 2>/dev/null | tail -n 1 | awk '{print $2}' FS=":"
grep -r "\w" 2>/dev/null | tail -n 1 | cut -d ":" -f 2
grep -r "\w" 2>/dev/null | tail -n 1 | tr ':' ' ' | awk '{print $2}' 
```

- Si hay un archivo con espacios:
```
cat spaces\ in\ this\ filename
cat *
cat /home/bandit2/*
cat s*
```

- Para archivos ocultos
```
ls -la
find .
find . -type f
find . -type f | grep "hidden" | xargs cat
find . -type f | grep -vE "bashrc|logout|profile" | xargs cat
```

- Para archivos que son leibles por los humanos (ASCII)
```
find . -type f | xargs file
```

- Para archivos que son leibles por humanos, no es ejecutable y pesa 1033 bytes:
```
find . -type f ! -executable -size 1033c | xargs file | xargs cat | xargs
```

- Para archivos que pertenecen a un usuario y un grupo y pesan 33 bytes:
```
find . -type f -user bandit7 -group bandit8 -size 33c
```

## Filtrado de datos
```
cat data.txt | grep "millionth"
cat data.txt | grep "millionth" | awk "{print $2}"
cat data.txt | grep "millionth" | awk "NF{print $NF}"

cat data.txt | grep "millionth" | cut -d " " -f 24
cat data.txt | grep "millionth" | xargs | cut -d ' ' -f 2
cat data.txt | grep "millionth" | rev | awk "{print $1}"
```

- Filtrar por cadenas unicas ordenando antes
```
sort data.txt | uniq -u
echo -e "\n[+] La contrasenia es: $(sort data.txt | uniq -q)\n"
```
## Reemplazando
- Para caracteres
```
tr ':' ' '
```
- Reemplazo un `:` a un ` `

- Para palabras:
```
sed 's/probando/prueba'
sed 's/probando/prueba/g'
```
- Cambio la palabra `probando` a `prueba`

## Interpretacion de archivos binarios
`string` se utiliza para imprimir cadenas de caracteres imprimibles, sobre en archivos binarios que la puede petar tu compu

- Si tenemos un archivo binario y en el hay luego de unos simbolos = una contrasenia, entonces:
```
strings data.txt | grep "===" | tail -n 1 | awk 'NF{print $NF}'
```

## Codificacion y decodificacion en base64
> Sistema mas potente de codificacion para caracteres ASCII

- Para convertir una cadena en base64
```
echo "Hola esto es una prueba" | base64
echo /etc/host | base64 -w 0
```

- Para decodificar
```
echo "Q2VsZXN0ZQo=" | base64 -d
```

## Rotacion 13 ROT13
- Cada letra se codifica rotando a 13 posiciones por delante

```
cat data.txt | tr '[a-zA-Z]' '[n-za-mN-ZA-M]'
```
