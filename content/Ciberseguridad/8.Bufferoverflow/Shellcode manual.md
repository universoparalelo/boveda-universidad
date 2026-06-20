## Introducción

Un **shellcode** es una secuencia de instrucciones en lenguaje máquina que se ejecuta directamente en memoria.

El shellcode depende de varios factores:

- Sistema operativo (Linux, Windows, BSD, etc.)  
- Arquitectura (x86, x64, ARM, etc.)
- Llamadas al sistema (syscalls) disponibles

Por este motivo, un shellcode para Linux x86 no funcionará necesariamente en Linux x64 o Windows.

---
# Analizando shellcodes generados con msfvenom

## Generar un ejecutable ELF

```bash
msfvenom -p linux/x86/exec CMD="echo 'Hola mundo'" -f elf -o binary
```

Genera un binario ELF ejecutable que ejecuta el comando especificado.

---
## Obtener el shellcode en bruto (raw)

```bash
msfvenom -p linux/x86/exec CMD="echo 'Hola mundo'" -f raw
```

Muestra únicamente los bytes del shellcode sin cabeceras ELF.

---
## Ver los bytes en hexadecimal

```bash
msfvenom -p linux/x86/exec CMD="echo 'Hola mundo'" -f raw | xxd
```

Permite observar la representación hexadecimal del shellcode.

---
## Desensamblar el shellcode

```bash
msfvenom -p linux/x86/exec CMD="echo 'Hola mundo'" -f raw | ndisasm -b32 -
```

Muestra las instrucciones ensamblador correspondientes a los bytes.

---
## Desensamblado con colores

```bash
msfvenom -p linux/x86/exec CMD="echo 'Hola mundo'" -f raw | disasm
```

Hace lo mismo que `ndisasm`, pero con resaltado visual.

---
# Analizando syscalls con strace

`strace` permite observar las llamadas al sistema realizadas por un proceso.

Instalación:

```bash
sudo apt install strace
```

Ejemplo:

```bash
strace ./binary
```

Si el programa imprime:

```text
Hola mundo
```

En `strace` aparecerá algo similar a:

```c
write(1, "Hola mundo\n", 11)
```

Esto indica que el programa ejecutó la syscall `write`.

---
# Tabla de syscalls

En sistemas Linux de 32 bits existe el archivo:

```bash
/usr/include/asm/unistd_32.h
```

(o según la distribución)

```bash
/usr/include/x86_64-linux-gnu/asm/unistd_32.h
```

Este archivo contiene los identificadores numéricos de cada syscall.

Ejemplos:

|Syscall|Número|
|---|---|
|exit|1|
|write|4|
|chmod|15|
|execve|11|

---
# Syscalls en Linux x86

En Linux x86 las llamadas al sistema suelen ejecutarse mediante:

```asm
int 80h
```

o

```asm
int 0x80
```

Antes de ejecutar la interrupción, los registros deben contener los parámetros adecuados.

Convención:

|Registro|Uso|
|---|---|
|eax|Número de syscall|
|ebx|Argumento 1|
|ecx|Argumento 2|
|edx|Argumento 3|

---
# Primer programa: Hola Mundo

Crear archivo:

```bash
nvim code.asm
```

Código:

```asm
section .text
	global _start

_start:

	; syscall write
	mov eax, 4
	mov ebx, 1

	push 0x0a6f646e ; do
	push 0x756d2061 ; mun
	push 0x6c6f48 ; hola

	mov ecx, esp
	mov edx, 11

	int 80h

	; syscall exit
	mov eax, 1
	xor ebx, ebx

	int 80h
```

---
# Construcción de cadenas en la pila

Las cadenas suelen colocarse directamente en la pila mediante instrucciones `push`.

Ejemplo:

```bash
echo -n "Hola" | xxd -ps
```

Resultado:

```text
486f6c61
```

Debido al formato **little-endian** de x86, los bytes quedan almacenados en memoria al revés.

Por eso se empujan en orden inverso:

```asm
push 0x616c6f48
```

Representa:

```text
Hola
```

al ser leído desde memoria.

## Regla práctica

1. Convertir el texto a hexadecimal.
2. Dividir en bloques de 4 bytes (8 caracteres hex).
3. Invertir el orden de los bytes dentro de cada bloque.
4. Hacer los `push` desde el final de la cadena hacia el principio.

---
# Compilar el ensamblador

## Ensamblar

```bash
nasm -f elf code.asm
```

Genera:

```text
code.o
```

Objeto ELF de 32 bits.

---
## Enlazar

```bash
ld -m elf_i386 -o final code.o
```

Genera el ejecutable final.

---
# Obtener el shellcode

Ver desensamblado:

```bash
objdump -d final
```

Extraer únicamente los bytes:

```bash
printf '\\x' && \
objdump -d final \
| grep "^ " \
| cut -f2 \
| tr -d ' ' \
| tr -d '\n' \
| sed 's/.\{2\}/&\\x /g' \
| head -c-3 \
| tr -d ' '
echo
```

Resultado esperado:

```text
\xb8\x04\x00\x00\x00...
```

Estos bytes constituyen el shellcode.

---
# Shellcode para ejecutar /bin/sh

Una de las syscalls más utilizadas es `execve`.

Número:

```text
11
```

Código:

```asm
section .text
	global _start

_start:

	mov eax, 11

	push 0x0
	push 0x68732f2f
	push 0x6e69622f

	mov ebx, esp

	xor ecx, ecx
	xor edx, edx

	int 80h
```

## Explicación

La pila queda así:

```text
/bin//sh
```

`ebx` apunta al inicio de la cadena.

```asm
execve("/bin//sh", NULL, NULL)
```

Al ejecutarse, reemplaza el proceso actual por una shell interactiva.

---
# Conceptos importantes para shellcoding real

Un shellcode utilizado en explotación normalmente intenta:

- Evitar bytes nulos (`0x00`)
- Ser lo más pequeño posible
- Ser independiente de direcciones absolutas
- Utilizar registros ya disponibles cuando sea posible
- Evitar instrucciones que generen caracteres problemáticos

Por eso, el código compilado para aprendizaje suele necesitar optimizaciones adicionales antes de convertirse en un shellcode utilizable en un exploit real.