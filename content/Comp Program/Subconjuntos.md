> Dado un conjunto con n elementos
> S = {ai,a2,a3,...,an}
> Un subconjunto es cualquier seleccion de esos elementos (incluyendo todos o ninguno)

- Ejemplo
```
S = [1,2,3]
```
- Subconjuntos:
```
[]
[1]
[2]
[3]
[1,2]
[1,3]
[2,3]
[1,2,3]
```
- Cantidad total `2^n`

## Generacion de 2^n en CP
- Recursion
- **Bitmask**
- Iteracion sobre mascaras

## Bitmask
- Representa a cada elemento como numero binario, que puede valer 0 o 1.
- Si tenemos S = [A,B,C]
### Representacion en tabla

| máscara | binario | subconjunto |
| :------ | :------ | :---------- |
| 0       | 000     | []          |
| 1       | 001     | [A]         |
| 2       | 010     | [B]         |
| 3       | 011     | [A,B]       |
| 4       | 100     | [C]         |
| 5       | 101     | [A,C]       |
| 6       | 110     | [B,C]       |
| 7       | 111     | [A,B,C]     |

### Codigo
```python
a = [1,2,3]
n = len(a)

for mask in range(1 << n):
    subset = []
    
    for i in range(n):
        if mask & (1 << i):
            subset.append(a[i])
    
    print(subset)
```
- Operador bit a bit `&`
- Operador `>>`, trabaja al nivel del bit tambien
- Complejidad: **n\*2^n**
- Para soluciones que requieran n>=20

## Alternativas
- Para soluciones con n mayores a 20 se utiliza **man in the middle**
- Se dividen los valores, se usan estrategias matematicas, ordenar, podar, etc.