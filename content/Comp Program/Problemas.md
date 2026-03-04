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