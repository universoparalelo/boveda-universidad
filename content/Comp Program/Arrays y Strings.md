---
tipo: referencia
tags: [cp, python, estructuras]
categoria: estructuras
---

## Listas
- Creacion
```
a = []
a = [1,2,3]
a = [0]*n
a = list(range(n))
```
- Creacion de matriz (muy comun):
```
a = [[0]*m for _ in range(n)]
```
- Acceso indexado
```
a[i]
a[0]
a[-1]
```
- Agregar/quitar elementos
```
a.append(x) # O(1)
a.pop() # saca el ultimo O(1)
a.pop(i) # O(n)
a.insert(i,x) # O(n)
```
- Longitud
```
len(a) # O(1)
```
- Ordenar
```
a.sort()
b = sorted(a)
a.sort(reverse=True)
```
- Suma, minimo y maximo
```
sum(a)
min(a)
max(a) # todos O(n)
```
- Contar ocurrencias
```
a.count(x)
```
- Buscar un elemento
```
x in a
```
- Reverso
```
a.reverse()
b = a[::-1]
```
- Copiar lista
```
b = a[:]
b = a.copy()
```
- Slice
```
b = a[l:r] # O(r-l)
```
- Enumerate
```
for i,val in enumerate(a):
```
- Comprehensions lists
```
square = [x*x for x in a]
```

## Strings
> Son inmutables

- Creacion
```
s = "Hola"
```
- Acceso
```
s[i]
s[-1]
```
- Longitud
```
len(s)
```
- Slice
```
s[l:r]
```
- Split()
```
s.split()
s.split(",")
```
- Join()
```
"".join(s) # ['Hola']
```
- Replace
```
s.replace("a", "b")
```
- Substring
```
"abc" in s
s.find("abc")
```
- Start with / End with
```
s.startswith("ab")
s.endswith("xz")
```
- Lower/Upper
```
s.lower()
s.upper()
```
- Strip()
```
s.strip()
s.strip("\n")
```
- Contar caracteres
```
s.count("a")
# pero es mejor
from collections import Counter
Counter(s) # Counter(s)["a"]
```

## Relacionado con
- [[Entradas y Salidas]]
