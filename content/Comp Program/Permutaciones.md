> Una **permutación** es un reordenamiento de elementos.

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
- Cantidad total:  n!

---
## 🔢 Tipos importantes en CP

### ✔️ Permutaciones de 1..n

Muy comunes:
```
p = [2, 3, 1]
```
- Interpretación:
- índice → posición
- valor → a dónde apunta

---
### ✔️ Permutación como grafo (MUY IMPORTANTE)

- Una permutación es un conjunto de **ciclos**.
- Ejemplo:
```
p = [2, 3, 1]
```
- Este array es un array de posiciones donde el elemento 2 esta en la posicion 1 verdad? Bueno ahora lo leeriamos asi, en la posicion 1 se encuentra el elemento 2, me voy hacia la posicion 2, en la posicion 2 esta el valor 3, me voy hacia la posicion 3, en la posicion 3 hay un 1, me voy hacia la posicion 1. Entonces como volvi a la posicion donde inicie se formo un ciclo. Puede que un array contenga mas de un ciclo entonces se le suma una posicion mas a la inicial y se sigue explorando.

- Ciclo:
```
1 → 2 → 3 → 1
```
👉 Esto aparece TODO el tiempo en problemas.

---

## 3. Ciclos de una permutación

### 🔹 Cómo encontrarlos
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
            cycle.append(j + 1)   # guardamos el número (1-index)
            j = p[j] - 1

        cycles.append(cycle)
```

---
### 💡 Propiedades importantes
- Una permutación se descompone en ciclos disjuntos
- Suma de tamaños de ciclos = n
- Muy útil para:
    - swaps mínimos
    - detectar estructura
    - simulaciones

---
## Número mínimo de swaps

- Para ordenar una permutación:
`{swaps} = n - {cantidad de ciclos}`

---
## Algoritmos clásicos

### 🔹 Generar permutaciones
```python
from itertools import permutations

for p in permutations([1,2,3]):
    print(p)
```
👉 Solo sirve para n ≤ 8 (fuerza bruta)

---
### 🔹 Next Permutation (IMPORTANTÍSIMO)
- Genera la siguiente permutación lexicográfica.
1. Encontrar primer índice donde deja de crecer
2. Intercambiar
3. Revertir sufijo

---
### 🔹 Inversa de una permutación

```python
inv = [0]*n
for i in range(n):
    inv[p[i]-1] = i+1
```

---
### 🔹 Composición de permutaciones

```python
# r = p ∘ q
r[i] = p[q[i]]
```

---
##  Permutaciones aplicadas k veces
- Problema típico:
> aplicar permutación k veces

- Si ciclo tiene tamaño `L`:
```
posición final = (pos + k) % L
```
👉 COMPLEJIDAD O(n)

---
## Permutaciones y paridad

- Permutación par/impar
- Basado en cantidad de swaps

💡 Útil en:
- matrices
- determinantes
- puzzles

---
## Problemas típicos de ICPC

### 🧩 1. Detectar ciclos
- contar ciclos
- tamaño de ciclos

---
### 🔁 2. Aplicar k veces
- usar módulo en ciclos

---
### 🔄 3. Ordenar con swaps mínimos
- usar fórmula de ciclos

---
### 🎯 4. Construir permutación
Ej:
- sin puntos fijos    
- con restricciones

---
### 🧠 5. Permutación válida
- verificar si array es permutación:
```python
len(set(a)) == n and min(a)==1 and max(a)==n
```

---
### 🧮 6. Conteo de permutaciones
- factoriales
- combinatoria

---
# ⚡ 9. Trucos de competitivo

### ✔️ Usar 0-index o 1-index consistente

---
### ✔️ Convertir a grafo mentalmente

---
### ✔️ Pensar en ciclos SIEMPRE

---
### ✔️ Si hay "repetir operación k veces" → ciclos

---
### ✔️ Si hay swaps → ciclos

---
# 🏋️ 10. Ejercicios recomendados (Codeforces)

Buscá problemas con:
- "permutation"
- "cycles"
- "swap"

Ejemplos típicos:
- ordenar con swaps
- reconstruir permutación
- aplicar operaciones

---
# 🚀 11. Nivel ICPC real

Lo que tenés que dominar:

✅ detectar ciclos rápido  
✅ usar módulo en ciclos  
✅ contar swaps  
✅ invertir permutaciones  
✅ componerlas  
✅ pensar en grafos
