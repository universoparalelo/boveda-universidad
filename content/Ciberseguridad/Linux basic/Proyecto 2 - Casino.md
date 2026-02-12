## Tecnica Martingala
- Apuestas si sale numero par o impar
- Empiezas apostando x cantidad, si ganas sigues apostando x cantidad pero si pierdes apuestas el doble de x y asi infinitamente
- Dependiendo de la cantidad inicial de x sera tu beneficio si ganas

## Tecnica Labouchere Inversa
- Empezamos con un array [1 2 3 4] ejemplo
- Apostamos la suma de los extremos [1 + 4] en este caso = 5
- Si perdemos eliminamos el 1 y el 4 del array y nos queda [2 3]
- Si ganamos colocamos al final de array el beneficio, que seria 5 en este caso y nos quedaria [1 2 3 4 5]
- Si nos quedamos sin numeros en el array volvemos a armar el mismo array [1 2 3 4] y listo

## Codigo puro

### declare
- `-i` numero entero
- `-a` array
- `-r` solo de lectura, como si fuese una constante

### variables
- Para declararlas
```bash
hola="esto es un saludo"
```
- Para mostrarlas
```bash
echo -e "Usando el $hola"
```
- Para modificarlas
```
let hola+=" estoy agregando esto despues de saludo"
```

### operadores
- `-eq` igual a
- `-gt` mas grande que (greater than)
- `-ge` mas grande o igual (greater or equal)
- `-lt` mas chico que (less than)
- `-le` mas chico o igual que (less or equal than)
- `!` negacion
- `&&` y, and
- `||` o, or
- `$variable` si una variable esta vacia

### estructuras basicas
```bash
if [] && []; then
elif []; then
else
fi
```

```bash
while []; do
done
```

```bash
for i in (seq 1 100); do
done
```

```bash
while true; do
done
```

```bash
while getopts "o:h" arg; do
	case $arg in
		o)
		h)
	esac
done 
```