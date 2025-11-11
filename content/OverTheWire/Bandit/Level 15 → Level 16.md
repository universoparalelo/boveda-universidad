The password for the next level can be retrieved by submitting the password of the current level to **port 30001 on localhost** using SSL/TLS encryption.
**Helpful note: Getting “DONE”, “RENEGOTIATING” or “KEYUPDATE”? Read the “CONNECTED COMMANDS” section in the manpage.**
## Comandos
```
nc -vz localhost 30001  #para chequear que el puerto esta vivo

openssl s_client -connect localhost:30001 #se abre la conexion y luego se pega la contrasenia anterior
```

## Contraseña    
- kSkvUpMQ7lBYyCM4GBPvCvT1BfWRy0Dx