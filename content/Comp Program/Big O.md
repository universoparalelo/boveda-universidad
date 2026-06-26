---
tipo: teoria
tags: [cp, analisis, complejidad]
categoria: analisis
---

> **Big O notation** is a mathematical tool used to describe the performance or complexity of an algorithm, specifically focusing on how its runtime or space requirements grow as the input size increases. It provides an **upper bound** on the growth rate, representing the **worst-case scenario** for an algorithm's efficiency.

**Common Notations**:
- **O(1)**: Constant time — execution time does not change with input size (e.g., accessing an array element by index).
- **O(log n)**: Logarithmic time — time grows slowly with input size (e.g., binary search).
- **O(n)**: Linear time — time grows proportionally with input size (e.g., iterating through an array).
- **O(n log n)**: Linearithmic time — common in efficient sorting algorithms like merge sort and quicksort.
- **O(n²)**: Quadratic time — time grows with the square of input size (e.g., nested loops).
- **O(2ⁿ)** or **O(n!)**: Exponential or factorial time — very slow for large inputs, typically seen in brute-force solutions.

**Video**
- [Learn Big O notation in 6 minutes 📈](https://www.youtube.com/watch?v=XMUe3zFhM5c)

![[Pasted image 20260226194933.png]]

## Tabla practica
| Complejidad | Maximo n aproximado viable |
| ----------- | -------------------------- |
| O(n)        | 10⁷ – 10⁶                  |
| O(n log n)  | 10⁶                        |
| O(n²)       | 3000 – 5000                |
| O(n³)       | 200                        |
| O(2ⁿ)       | n ≤ 20                     |
| O(n!)       | n ≤ 9                      |

## Relacionado con
- [[Sorting]]
- [[Busqueda lineal y binaria]]
