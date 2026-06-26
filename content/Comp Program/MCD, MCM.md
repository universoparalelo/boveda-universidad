---
tipo: referencia
tags: [cp, matematicas, teoria-numeros]
categoria: matematicas
---

## MCD - Maximo comun divisor
> El **MCD de dos numeros** es el numero mas grande que divide a ambos.

`MCD(12, 18) = 6` porque sus divisores son:
```
12 → 1,2,3,4,6,12
18 → 1,2,3,6,9,18
```
- Entonces el 6 es el comun maximo que divide a ambos en enteros.

### Algoritmo de Euclides
- Partiendo de esta idea:
```
gcd(a, b) = gcd(b, a % b)
```
- hasta que `b = 0`
```
gcd(48,18)

48 % 18 = 12
18 % 12 = 6
12 % 6 = 0

resultado = 6
```

### Implementacion en python
```
from math import gcd

print(gcd(48,18))
```

### Implementacion manual
```
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
```

## MCM - Minimo comun multiplo
> El **MCM** es el numero mas pequeno que es multiplo de ambos.

`MCM(4,6) = 12`
```
4 -> 4, 8, 12
6 -> 6, 12
```

### Implementacion en Python
```
from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)
```

## MCD de muchos numeros
```
from math import gcd
from functools import reduce

nums = [24, 36, 60]

g = reduce(gcd, nums)

print(g)  # 12
```

## MCM para varios numeros
```
from math import gcd
from functools import reduce

def lcm(a,b):
    return a*b//gcd(a,b)

nums = [4,6,8]

ans = reduce(lcm, nums)

print(ans)
```

## Simplificar funciones
`24/36` - hallamos el MCD y dividimos cada miembro y el resultado se lo formatea e imprime:
```
from math import gcd

a = 24   # numerador
b = 36   # denominador

g = gcd(a, b)

a = a // g
b = b // g

print(a, "/", b)
```

## Saber si a y b son coprimos
- Los numeros coprimos (o primos entre si) son aquellos pares de numeros enteros cuyo unico divisor comun es el 1. Esto significa que su Maximo Comun Divisor (MCD) es igual a 1. No es necesario que los numeros sean primos individualmente; por ejemplo, 8 (1,2,4,8) y 9 (1,3,9) son coprimos.
- Caracteristicas
	- **Numeros consecutivos:** Dos numeros naturales consecutivos siempre son coprimos (ej. 15 y 16, 100 y 101).
	- **Numeros primos:** Dos numeros primos distintos siempre son coprimos (ej. 7 y 13).
	- **Fracciones:** Si el numerador y el denominador de una fraccion son coprimos, la fraccion es irreducible.
```
if gcd(a,b) == 1:
    print("coprimos")
```

## Propiedad del MCD
El MCD tiene una propiedad clave:
`gcd(a,b)=gcd(a−b,b)`
o tambien
`gcd(a,b)=gcd(a,b−a)`
Esto significa que **restar los numeros no cambia el MCD**.

- Por lo tanto:
`gcd(20,12) = gcd(12,8)` que es 4

## Diferencias entre numeros
- Tenemos un array `[14, 20, 26]`
- Entonces calculamos las diferencias
```
20 - 14 = 6
26 - 20 = 6
```
- Y luego el mcd `gcd(6,6) = 6`
- Entonces decimos que los valores estan separados por valores multiplos de 6

## Relacionado con
- [[Aritmetica modular]]
- [[Numeros primos]]
