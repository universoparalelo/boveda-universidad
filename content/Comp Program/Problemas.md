### 3 de marzo
Watermelon - 15 minutos - 122 ms - 3 intentos
```
n = int(input())

if n%2 == 0 and n
    print("YES")
else:
    print("NO")
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

Team - 4 minutos - 124 ms - 1 intento
```
n = int(input())
r = 0

for _ in range(n):
    s = list(map(int, input().split()))
    if sum(s) > 1:
        r += 1

print(r)
```

Bit++ - 4 minutos - 62 ms - 1 intento
```
n = int(input())
x = 0

for _ in range(n):
    s = list(input())
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

Domino piling - 5 minutos - 124 ms - 1 intento
```
m,n = map(int, input().split())

t=m*n

print(t//2)
```

Beautiful Matrix - 10 minutos - 124 ms - 1 intento
```
m = []

for _ in range(5):
    line = list(map(int, input().split()))
    m.append(line)

for i in range(5):
    for j in range(5):
        if m[i][j] == 1:
            print(abs(i-2)+abs(j-2))
            break
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