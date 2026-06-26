---
tipo: bitacora
tags: [cp, problemas, codeforces]
estado: en-progreso
---

### 3 de marzo
Watermelon - 15 minutos - 122 ms - 3 intentos
```
n = int(input())

if n%2 == 0 and n > 2:
    print("YES")
else:
    print("NO")
```
- Mejora
```python
n = int(input())
print("YES" if n % 2 == 0 and n > 2 else "NO")
```

Way Too Long Words - 22 minutos - 46 ms - 2 intentos
```
n = int(input())
a = []

for _ in range(n):
    word = list(input())
    if len(word) > 10:
        nword = word[0]+str(len(word)-2)+word[-1]
        a.append(nword)
    else:
        a.append("".join(word))

for i in a:
    print(i)
```
- Mejora
```python
n = int(input())

for _ in range(n):
    w = input()
    if len(w) > 10:
        print(w[0] + str(len(w)-2) + w[-1])
    else:
        print(w)
```

Team - 4 minutos - 124 ms - 1 intento
```python
n = int(input())
r = 0

for _ in range(n):
    s = list(map(int, input().split()))
    if sum(s) > 1:
        r += 1

print(r)
```

Bit++ - 4 minutos - 62 ms - 1 intento
```python
n = int(input())
x = 0

for _ in range(n):
    s = list(input()) # no es necesario convertir a lista, los strings son indexables
    if s[1] == '+':
        x += 1
    else:
        x -= 1

print(x)
```

### 08/04/2026
Next Round - 27 minutos - 92 ms - 3 intentos
```
n, k = map(int, input().split())
puntajes = list(map(int, input().split()))

h = 0
for valor in puntajes:
   if valor >= puntajes[k-1] and valor != 0:
       h+=1

print(h)
```
- Mejora:
```python
n, k = map(int, input().split())
scores = list(map(int, input().split()))

threshold = scores[k-1]

print(sum(1 for s in scores if s >= threshold and s > 0))
```

Domino piling - 5 minutos - 124 ms - 1 intento
```python
m,n = map(int, input().split())

t=m*n

print(t//2)
```

Beautiful Matrix - 10 minutos - 124 ms - 1 intento
```python
m = []

for _ in range(5):
    line = list(map(int, input().split()))
    m.append(line)

for i in range(5):
    for j in range(5):
        if m[i][j] == 1:
            print(abs(i-2)+abs(j-2))
            break # mejor usar exit() porque hay un solo cero
```

Petya and Strings - 10 minutos - 156 ms - 1 intento
```
a = list(input())
b = list(input())

for i in range(len(a)):
    if ord(a[i].lower()) > ord(b[i].lower()):
        print(1)
        exit()
    elif ord(b[i].lower())>ord(a[i].lower()):
        print(-1)
        exit()

print (0)
```
- Python ya tiene comparacion lexicografica
```python
a = input().lower()
b = input().lower()

if a > b:
    print(1)
elif a < b:
    print(-1)
else:
    print(0)
```
### 10 de marzo
Boy or Girl - 6 minutos - 124 ms - 1 intento
```
name = input()
c = []

for letter in name:
    if letter not in c:
        c.append(letter)

if len(c)%2 == 0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')
```
- Es mucho mas eficiente usar **set** para evitar el **not in c**:
```python
name = input()

if len(set(name)) % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
```


Helpful Maths - 3 minutos - 124 ms - 1 intento
```python
line = input().split('+')
line.sort()

print("+".join(line))
```

Word Capitalization - 6 minutos - 92 ms - 1 intento
```python
c = input()
n = c[1:]

print(f'{c[0].upper()}{n}')
```

Bear and Big Brother - 5 minutos - 62 ms - 1 intento
```python
a, b = map(int, input().split())
years = 0

while a <= b:
    a *= 3
    b *= 2
    years += 1

print(years)
```

### 12 de marzo
Elephant - 12 minutos - 46 ms - 1 intento
```
n = int(input())
p = 0

for i in range(5,1,-1):
    if n >= i:
        resto = n % i
        p += (n//i)
        n = resto
    
if n != 0:
    p += 1

print(p)
```

Stones - 6 minutos - 124 ms - 1 intento
```
n = int(input())
stones = input()
count = 0

for i in range(n-1):
    if stones[i] == stones[i+1]:
        count += 1

print(count)
```

Soldier and Bananas - 12 minutos - 46 ms - 1 intento
```
k, n, w = map(int, input().split())

total_n = sum(i*k for i in range(1,w+1))

if total_n - n > 0:
    print(total_n - n)
    exit()

print(0)
```

Word - 5 minutos - 124 ms - 1 intento
```
w = input()
count_l = 0

for l in w:
    if l > 'Z':
        count_l += 1

if count_l >= len(w)-count_l:
    print(w.lower())
else:
    print(w.upper())
```

### 15 de marzo
Wrong substraction - 18 minutos - 46 ms - 1 intento
```
n, k = map(int, input().split())

while k > 0:
    if n % 10 != 0:
        if n % 10 <= k:
            r = n % 10
            n -= r
            k -= r
        else:
            n -= 1
            k -= 1
    else:
        n = n / 10
        k -= 1

print(int(n))
```

Nearly Lucky Numbers - 13 minutos - 156 ms - 1 intento
```
from collections import Counter 

n = input()
c = Counter(n)

print("YES" if ((c['4']+c['7']) == 4 or (c['4']+c['7']) == 7)  else "NO")
```

Anton And Danik - 13 minutos - 62 ms - 2 intentos
```
from collections import Counter 
n = int(input())
w = input()
c = Counter(w)

if c['A'] > c['D']:
    print('Anton')
elif c['A'] == c['D']:
    print('Friendship')
else:
    print('Danik')
```

Translation - 5 minutes - 62 ms - 1 intento
```
w = input()
t = input()
s = ""

for i in range(len(w)-1, -1, -1):
    s += w[i]

if s == t:
    print('YES')
else:
    print('NO')
```

## Tecnicas relacionadas
- [[Problemas/Busqueda binaria]]
- [[Problemas/Two pointers]]
