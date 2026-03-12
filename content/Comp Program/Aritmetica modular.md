> La aritmética modular, conocida como "aritmética del reloj", es un sistema donde los números "dan la vuelta" al alcanzar un valor fijo llamado **módulo** (n), enfocándose en el residuo de la división. Dos números y son congruentes módulo n (a ≡ b mod(n)) si tienen el mismo resto al dividirse por n.

## Propiedades importantes
- Suma
```
(a + b) mod m = ((a mod m) + (b mod m)) mod m
```

- Resta
```
(a - b) mod m = ((a mod m) - (b mod m)) mod m
```

- Multiplicacion
```
(a × b) mod m = ((a mod m) × (b mod m)) mod m
```

## Exponenciacion modular
```python
def mod_pow(a, b, m):
    res = 1
    a %= m

    while b > 0:
        if b & 1:
            res = (res * a) % m

        a = (a * a) % m
        b >>= 1

    return res
```
- Complejidad O(log n) para calcular `a^b mod m` sin overflow

## Inverso modular
- Queremos hallar X
```
a * x ≡ 1 (mod m)
```
- Python ya tiene una funcion integrada 
```python
inv = pow(a, MOD-2, MOD)
```