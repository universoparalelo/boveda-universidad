- Escapar el siguiente caracter `\`
- Toma cualquier caracter excepto una nueva linea `.`
- Hace referencia al ultimo caracter que tomo `&`
- Desde el comienzo de la linea `^`

```bash
cat archivo.js | awk '/name: "Tentacle"/,/resuelta:/' | grep -vE "id|sku|resuelta|activeDirectory" | tr -d '"' | tr -d "," | sed -E 's/(name:|ip:|so:|dificultad:|skills:|like:|youtube:)/${blueColour}&${endColour}/'
```
- con respecto al ultimo `sed` estoy diciendo si encuentras `name:` o `ip:` o etc, entonces lo cambias por los colores y con `&` haciendo referencia a lo que tomo ya sea `hola:` o cualquiera de las palabras para que lo coloque en medio.
```bash
cat archivo.js | awk '/name: "Tentacle"/,/resuelta:/' | grep -vE "id|sku|resuelta|activeDirectory" | tr -d '"' | tr -d "," | sed -E 's/^[^:]*/${blueColour}&${endColour}/'
```
- una solucion diferente
- y otra mas rara
```
cat archivo.js | awk '/name: "Tentacle"/,/resuelta:/' | grep -vE "id|sku|resuelta|activeDirectory" | tr -d '"' | tr -d "," | sed 's/^ *//' | sed -E 's/[^:]*/${blueColour}[+] & -->${endColour}/' | sed 's/://'
```