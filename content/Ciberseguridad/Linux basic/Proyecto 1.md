- Obtener todos los datos de una pagina
```
curl -s -X GET <url>
```
- `-s` en modo silencioso

- Guardamos en un archivo
```
curl -s -X GET <url> > archivo.js
```

- Mejoramos la sintaxis para mejor lectura
```
cat archivo.js | js-beautify | sponge archivo.js 
```
- `sudo npm -g install js-beautify` para instalar de forma global js-beautify

