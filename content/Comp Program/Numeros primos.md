> Un numero primo es un numero positivo entero que tiene como unicos divisores al 1 y a si mismo

### Verificar que un numero es primo
```python
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
```
- Con una complejidad de O(raiz (n))

### [[Criba de Eratostenes]]
- Para encontrar todos los primos hasta N
```python
def sieve(n):
    prime = [True]*(n+1)
    prime[0] = prime[1] = False

    for i in range(2, int(n**0.5)+1):
        if prime[i]:
            for j in range(i*i, n+1, i):
                prime[j] = False

    return prime
```
- Con una complejidad de O(n\*logn)

### Factorizacion prima
```python
def prime_factors(n):
    factors = []

    i = 2
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
        i += 1

    if n > 1:
        factors.append(n)

    return factors
```
- Complejidad O(raiz cuadrada n)

