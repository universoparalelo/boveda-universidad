---
tipo: tecnica
tags: [cp, busqueda, tecnica]
complejidad: O(log n)
---

# Busqueda binaria

Buscar un elemento en un **array ordenado** dividiendo el espacio de busqueda a la mitad en cada paso.

## Requisitos
- El array debe estar **ordenado**
- La funcion debe ser **monotonica** (hay un punto donde deja de ser valido)

## Implementacion
```python
l = 0
r = len(a) - 1

while l <= r:
    mid = (r + l) // 2
    if a[mid] == target:
        return mid
    elif a[mid] < target:
        l = mid + 1
    else:
        r = mid - 1
```

## Con bisect (Python)
```python
import bisect

bisect.bisect_left(a, x)   # primer indice donde insertar x
bisect.bisect_right(a, x)  # ultimo indice donde insertar x

# Contar ocurrencias en O(log n)
count = bisect_right(a, x) - bisect_left(a, x)
```

## Cuando usarlo
- Busqueda en arrays ordenados
- Encontrar el punto donde una condicion cambia
- Problemas de "minimo X tal que..."
- Optimizacion con respuesta binaria

## Relacionado con
- [[Busqueda lineal y binaria]]
- [[Big O]]
- [[Sorting]]
