> Netcat es un herramienta para abrir puertos y quedarnos en la escucha o espera de una terminal

- Nos ponemos en la escucha del localhost en el puerto 30000
```
nc localhost 30000
```

- Para ver los puertos abiertos en mi red
```
ss -nltp
```

- Truquito para operar sobre cada linea de un output
```
echo "23
22
21
20" | while read line; do echo "Estamos leyendo la linea: $line"; done
```

- Convertir numeros hexadecimales a decimales:
```
echo "[+] Decimal: 1500 -> Hexadecimal: $(echo "obase=16; ibase=10; 1500" | bc)"
```

- Para conocer que servicio esta corriendo por determinado puerto
```
lsof -i:22
```

- Para conectarnos a un servicio que requiere encriptacion ssl
```
ncat --ssl localhost 30001
```

- Dentro de bash podemos averiguar desde consola que puertos estan abiertos o no segun el codigo de error que devuelve:
```
echo '' 2&>/dev/null > /dev/tcp/127.0.0.1/22
```

