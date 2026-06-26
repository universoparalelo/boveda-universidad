---
tipo: tecnica
tags: [cp, busqueda, tecnica]
complejidad: O(n)
---

# Two pointers

Tecnica que usa **dos indices** que recorren un array (generalmente ordenado) para resolver problemas en O(n).

## Implementacion basica
```python
l = 0
r = n - 1

while l < r:
    s = a[l] + a[r]

    if s == target:
        return True
    elif s < target:
        l += 1
    else:
        r -= 1
```

## Cuando usarlo
- Buscar pares que suman un valor en un array ordenado
- Problemas de subarrays con condicion
- Fusionar dos arrays ordenados
- Remover duplicados

## Relacionado con
- [[Busqueda lineal y binaria]]
- [[Sorting]]
