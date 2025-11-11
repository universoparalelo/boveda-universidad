The credentials for the next level can be retrieved by submitting the password of the current level to **a port on localhost in the range 31000 to 32000**. First find out which of these ports have a server listening on them. Then find out which of those speak SSL/TLS and which don’t. There is only 1 server that will give the next credentials, the others will simply send back to you whatever you send to it.
## Comandos
```
nc -vz locahost 31000-32000 ## para ver que puertos estan escuchando
# 31046 x 
# 31518 acepta TLS keyupdate no es
# 31691 x 
# es este 31790 acepta TLS keyupdate incorrect password
# 31960 x
```

## Contraseña    
- 