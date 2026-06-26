---
tipo: referencia
tags: [cp, python, io]
categoria: io
---

## Leer entradas
### input()
- input simple
```
s = input()
```
- leer un entero
```
s = int(input())
```
- multiples enteros en una linea
```
s = list(map(int, input().split()))
```
- leer dos enteros
```
a, b = map(int, input().split())
```
- leer multiples lineas
```
n = int(input())
arr = []
for _ in n:
	arr.append(int(input()))
```

### sys.stdin.readline
- leer multiples lineas
```
import sys

input = sys.stdin.readline
s = input().strip()
```

- leer directamente
```
s = sys.stdin.read().split()
nums = list(map(int, s))
```

### leer matrices
```
n, m = map(int, input().split())
grid = [list(map(int, input().split()) for _ in range(n)]
```

### leer string como lista de caracteres
```
lista = list(input())
```

### leer digitos como enteros individuales
```
# 12345
digits = list(map(int, input())) # [1,2,3,4,5]
```

## Mostrar datos
- mostrar datos
```
print(x) # 1
```
- multiples datos
```
print(x,y,z) # 1 2 3
```
- format
```
print(f"{x},{y},{z}") # 1,2,3
```
- join()
```
res = []
for i in range(100000):
    res.append(str(i))

print(",".join(res))
```

## Relacionado con
- [[Arrays y Strings]]
