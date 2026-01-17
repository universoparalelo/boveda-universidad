### Para separar comandos `;`
```
whoami; ls
```

### Operando &&
- Similar a `;` pero solo se ejecuta el segundo comando si el primero fue exitoso

```
cat /etc/hosts
```
- Para conocer los hosts

```
echo $?
```
- Para ver el codigo de estado del comando anterior
- Entre 1-125 error; 126 comando encontrado pero no ejecutable; 127 comando no encontrado; 0 funciono todo bien

### Operando ||
- En caso de que el primero no sea exitoso ejecuta el siguiente
```
wham || echo "hola"
```

- Los errores son `stderr`, entonces si un comando da error y tiene definido un stderr lo va a mostrar, en el caso que no queramos verlo:
```
wham 2>/dev/null
```
- Quiero que lo errores, referenciado con el numero 2, se redigan hacia dev/null que es un archivo **agujero negro**

- Todo lo que se ve es `stdout`
```
ls > /dev/null
```
- Estamos llevando toda la salida hacia el agujero negro
```
lsf > /dev/null 2>&1
```
- Aca como la salida va a dar error, porque lsf no existe, podemos convertir los errores en salida normal entonces se redige hacia /dev/null
```
python3 -m http.server 80 &>/dev/null
```
- Redigir errores o salida estandar hacia el agujero negro

- Si queremos abrir un programa desde la consola y que la salida no este activa agregamos un & para que le asigne un PID, numero de proceso,  y asi podemos usar la consola para otros comandos.
- _Pero si cerrramos la consola se cierra el programa, porque sigue siendo un proceso hijo_
```
wireshark &>/dev/null &
```
- Para crear un proceso aparte
```
wireshark &>/dev/null & disown
```