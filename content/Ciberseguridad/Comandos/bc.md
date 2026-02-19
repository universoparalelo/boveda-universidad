> The **bc command** in Linux is a powerful command-line calculator that supports arbitrary precision arithmetic, making it ideal for complex mathematical operations, including floating-point calculations, which standard shell scripting languages like Bash cannot handle natively.

```
echo 'obase=2; 12' | bc   # Converts 12 (base 10) to binary → 1100
echo 'obase=16; 255' | bc  # Converts 255 (base 10) to hexadecimal → FF   
```

- **Interactive Mode**:
```
bc
```
Enter expressions directly and get immediate results. Exit with `quit` or `Ctrl+D`. 

- **Non-Interactive Mode** (via pipe):
```
echo "5 + 3" | bc
echo "scale=2; 10 / 3" | bc    
```

- **Using Variables and Expressions**:
```
echo "a=10; b=5; a * b" | bc
```