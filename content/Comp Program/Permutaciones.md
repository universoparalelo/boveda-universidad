---
tipo: referencia
tags: [cp, combinatoria, permutaciones]
categoria: combinatoria
---

> Una **permutacion** es un reordenamiento de elementos.

- Ejemplo:
```
[1, 2, 3]

Permutaciones:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```
- Cantidad total: n!

---
## Tipos importantes en CP

### Permutaciones de 1..n

Muy comunes:
```
p = [2, 3, 1]
```
- Interpretacion:
- indice → posicion
- valor → a donde apunta

---
### Permutacion como grafo (MUY IMPORTANTE)

- Una permutacion es un conjunto de **ciclos**.
- Ejemplo:
```
p = [2, 3, 1]
```
- Este array es un array de posiciones donde el elemento 2 esta en la posicion 1 verdad? Bueno ahora lo leeriamos asi, en la posicion 1 se encuentra el elemento 2, me voy hacia la posicion 2, en la posicion 2 esta el valor 3, me voy hacia la posicion 3, en la posicion 3 hay un 1, me voy hacia la posicion 1. Entonces como volvi a la posicion donde inicie se formo un ciclo. Puede que un array contenga mas de un ciclo entonces se le suma una posicion mas a la inicial y se sigue explorando.

- Ciclo:
```
1 → 2 → 3 → 1
```
Esto aparece TODO el tiempo en problemas.

---

## 3. Ciclos de una permutacion

### Como encontrarlos
```python
p = [2, 3, 1]
n = len(p)
visited = [False]*n

for i in range(n):
    if not visited[i]:
        j = i
        while not visited[j]:
            visited[j] = True
            j = p[j] - 1   # si es 1-indexado
```
- Aca faltaria contar cuantos elementos y cuales pertenecen a un ciclo y cuantos ciclos son.
---
## Version completa
```python
p = [2, 3, 1]
n = len(p)
visited = [False]*n

cycles = []

for i in range(n):
    if not visited[i]:
        j = i
        cycle = []

        while not visited[j]:
            visited[j] = True
            cycle.append(j + 1)   # guardamos el numero (1-index)
            j = p[j] - 1

        cycles.append(cycle)
```

---
### Propiedades importantes
- Una permutacion se descompone en ciclos disjuntos
- Suma de tamanos de ciclos = n
- Muy util para:
    - swaps minimos
    - detectar estructura
    - simulaciones

---
## Numero minimo de swaps

- Para ordenar una permutacion:
`swaps = n - cantidad de ciclos`

---
## Algoritmos clasicos

### Generar permutaciones
```python
from itertools import permutations

for p in permutations([1,2,3]):
    print(p)
```
Solo sirve para n ≤ 8 (fuerza bruta)

---
### Next Permutation (IMPORTANTISIMO)
- Genera la siguiente permutacion lexicografica.
1. Encontrar primer indice donde deja de crecer
2. Intercambiar
3. Revertir sufijo

---
### Inversa de una permutacion

```python
inv = [0]*n
for i in range(n):
    inv[p[i]-1] = i+1
```

---
### Composicion de permutaciones

```python
# r = p ∘ q
r[i] = p[q[i]]
```

---
## Permutaciones aplicadas k veces
- Problema tipico:
> aplicar permutacion k veces

- Si ciclo tiene tamano `L`:
```
posicion final = (pos + k) % L
```
Complejidad O(n)

---
## Permutaciones y paridad

- Permutacion par/impar
- Basado en cantidad de swaps

Util en:
- matrices
- determinantes
- puzzles

---
## Problemas tipicos de ICPC

### 1. Detectar ciclos
- contar ciclos
- tamano de ciclos

---
### 2. Aplicar k veces
- usar modulo en ciclos

---
### 3. Ordenar con swaps minimos
- usar formula de ciclos

---
### 4. Construir permutacion
Ej:
- sin puntos fijos
- con restricciones

---
### 5. Permutacion valida
- verificar si array es permutacion:
```python
len(set(a)) == n and min(a)==1 and max(a)==n
```

---
### 6. Conteo de permutaciones
- factoriales
- combinatoria

---
# Trucos de competitivo

### Usar 0-index o 1-index consistente

### Convertir a grafo mentalmente

### Pensar en ciclos SIEMPRE

### Si hay "repetir operacion k veces" → ciclos

### Si hay swaps → ciclos

---
# Ejercicios recomendados (Codeforces)

Busca problemas con:
- "permutation"
- "cycles"
- "swap"

Ejemplos tipicos:
- ordenar con swaps
- reconstruir permutacion
- aplicar operaciones

---
# Nivel ICPC real

Lo que tenes que dominar:

- detectar ciclos rapido
- usar modulo en ciclos
- contar swaps
- invertir permutaciones
- componerlas
- pensar en grafos

## Relacionado con
- [[Subconjuntos]]
