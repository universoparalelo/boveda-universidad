---
tipo: bitacora
tags: [cp, contests]
estado: en-progreso
---

A. Bingo candies
```
t = int(input())

for _ in range(t):
    n = int(input())
    m = []
    for _ in range(n):
        m += list(map(int, input().split()))

    set_m = set(m)
    bandera = False

    v = n*n - n

    for e in set_m:
        if m.count(e) > v:
            print("NO")
            bandera=True
            break

    if not bandera:
        print("YES")
```

B. Cyclists
```
t = int(input())

for _ in range(t):
    n,k,p,m = map(int, input().split())
    mazo = list(map(int, input().split()))
    cant = 0

    while m > 0:
        if p <= k:
            m -= mazo[p-1]
            v = mazo.pop(p-1)
            mazo = mazo[:]+[v]
            p = n
            cant += 1
        else:
            mi = 9999
            pos = 0
            for i in range(k):
                if mazo[i] < mi:
                    mi = mazo[i]
                    pos = i

            m -= mazo[pos]
            e = mazo.pop(pos)
            mazo = mazo[:]+[e]

            if p == 1:
                p = n
            else:
                p -= 1


    print(cant)
```
