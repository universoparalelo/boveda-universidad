> Docker Compose es una **herramienta para definir y ejecutar aplicaciones Docker multicontenedor**. Utiliza un único archivo YAML (`docker-compose.yml`) para configurar servicios, redes y volúmenes, permitiendo levantar toda la pila de una aplicación (frontend, backend, base de datos) con un solo comando, facilitando el desarrollo y pruebas.

### 1er Laboratorio - Kibana
Aprovechamos un proyecto de [[vulhub]]
```
cd vulhub/kibana/CVE-2018-17246
docker compose up -d
```
Y vamos a nuestro navegador en `localhost:5601` ya esta armado

`curl -s -X GET "https://localhost:5601/api/blablabla"` se ve en los logs de esa maquina que ejecuto lo que pidio, entonces podemos crear un archivo malicioso porque descubrimos que la maquina ejecuta lo que le mandamos por mas de devolvernos un error

### 2do Laboratorio - Imagemagick
```
cd vulhub/imagemagick/CVE-2016-3714
docker compose up -d
```
- Procesador de archivos multimedia, imagenes, gif, etc.

