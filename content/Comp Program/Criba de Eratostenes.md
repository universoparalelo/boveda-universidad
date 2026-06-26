---
tipo: algoritmo
tags: [cp, matematicas, teoria-numeros]
categoria: matematicas
complejidad: O(n log n)
---

> La **Criba de Eratostenes** es uno de los algoritmos mas importantes de **teoria de numeros en programacion competitiva**. Sirve para:
> **Encontrar todos los numeros primos hasta N de forma eficiente.**
	Es extremadamente comun en problemas de:
	- numeros primos
	- factorizacion
	- conteo de primos
	- teoria de numeros
- Tiene una complejidad de O(n log n) — [[Big O]]
## Numeros primos
- Un numero primo es un numero que **solo tiene dos divisores**: `1 y el mismo`

## El algoritmos
- Funciona eliminando multiplos:
- `Encontrar primos hasta 20`
- Los numeros a evaluar serian: `[2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]`
- El primer primo seria `2` y sus multiplos son: `[4,6,8,10,12,14,16,18,20]`
- Eliminamos esos numeros del array y nos queda: `[2,3,5,7,9,11,13,15,17,19]`
- El siguiente primo es `3` y sus multiplos son: `[6,9,12,15,18]`
- Los eliminamos y nos queda: `[2,3,5,7,11,13,17,19]`
- Hacemos lo mismo hasta `raiz_cuadrada(20) ~= 4,472` y listo
- La lista de numeros primos hasta 20 = `[2,3,5,7,11,13,17,19]`

## Implementacion
```
n = 20

is_prime = [True]*(n+1)
is_prime[0] = is_prime[1] = False

for i in range(2, int(n**0.5)+1):
    if is_prime[i]:
        for j in range(i*i, n+1, i):
            is_prime[j] = False

for i in range(2, n+1):
    if is_prime[i]:
	        print(i)
```


## SPF - Smallest Prime Factor
- En lugar de factorizar cada numero desde cero, **precalculamos para cada numero su factor primo mas pequeno**.
- Armas la criba tiene una complejidad O(n log n) y factorizar un numero O(log n)

## Implementacion
- Creamos una matriz donde para cada posicion igualamos a su factor primo mas pequenio
- Entonces para `sf[82]` su factor primo mas pequenio es `2`, entonces `82/2=42`
- Ahora vemos para `sf[42]=2` entonces `42/2=21`
- `sf[21]=3` entonces `21/3=7`
- `sf[7]=7` terminamos y nos queda `[2,2,3,7]` listo.

- Creamos la criba:
```
N = 1000000

spf = [0]*(N+1)

for i in range(2, N+1):
    if spf[i] == 0:
        for j in range(i, N+1, i):
            if spf[j] == 0:
                spf[j] = i
```
- Funcion para factorizar:
```
def factorize(x):
    factors = []

    while x != 1:
        factors.append(spf[x])
        x //= spf[x]

    return factors
```

### Contar divisores
```
n = 84 = 2² × 3¹ × 7¹

(2+1)(1+1)(1+1) = 12
```

## Relacionado con
- [[Numeros primos]]
- [[Aritmetica modular]]
- [[Big O]]
