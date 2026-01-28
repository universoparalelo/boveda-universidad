```
sudo systemctl start ssh
ssh s4vitar@localhost
```
- Para habilitar el servicio de ssh y luego conectarte proporcionando la contrasenia

```
ssh-keygen
```
- Generar una clave publica y privada RSA
- Si haces una copia de la clave publica y le nombras a esta copia `authorized_keys` vas a poder ingresar al ssh sin proporcionar contrasenia alguna, es como una llave que te otorga el duenio del servidor
```
cp id_rsa.pub authorized_keys
ssh s4vitar@localhost
```

- En vez de hacer una copia tambien puedes hacer:
```
ssh-copy-id -i id_rsa s4vitar@localhost
```
- Sino simplemente con:
```
ssh -i id_rsa s4vitar@localhost
```
