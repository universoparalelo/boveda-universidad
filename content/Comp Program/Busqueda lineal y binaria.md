
### Busqueda lineal
```
for a in elements:
	if a == target:
```
- Si en cambio target es una lista conviene:
```
set_target = set(target)
for a in elements:
	if a in set_target: # O(1)
```

### Busqueda binaria
- la lista debe estar ordenada
- la funcion debe ser monotonica, hay un punto donde el array deja de ser valido.
```
l = 0 
r = len(a) - 1

while l <= r:
	mid = (r+l) // 2
	if a[mid] == target:
		return mid
	elif l < target:
		l = mid + 1
	else
		r = mid - 1
```

- Con modulo bisect
```
import bisect

bisect.bisect_left(a, x)
bisect.bisect_right(a, x)
```
- Sirve para contar rapidamente ocurrencias
```
count = bisect_right(a, x) - bisect_left(a, x)
```

---
### Ejercicio 1 - Sorting descendente
```
n = int(input())
elements = list(map(int, input().split()))
elements.sort(reverse=True)

return(elements)
```

### Ejercicio 2 - Two pointers clasico
```
n = int(input())
a = list(map(int, input().split()))
a.sort()
target = int(input())

l = 0
r = n-1
while l < r:
	s = a[l] + a[r]
	
	if s == target:
		return "YES"
	elif s < target:
		l += 1
	else:
		r -= 1
return "NO"
```

### Ejercicio 3 - Bisect
- Dado un array ordenado y Q queries.
- Para cada query x, imprimir cuántos números son ≤ x.
- Debe ser O(Q log n).
```
import bisect

array = list(map(int, input().split()))
array.sort()

n = int(input())
result = []

for i in range(n):
	x = int(input())
	cant = bisect.bisect_left(array, x) + 1
	result.appen(cant)
	
print(*result)
```

## Bisect
![[Pasted image 20260302190057.png|592]]