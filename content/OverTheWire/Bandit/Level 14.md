The password for the next level is stored in **/etc/bandit_pass/bandit14 and can only be read by user bandit14**. For this level, you don’t get the next password, but you get a private SSH key that can be used to log into the next level. 
**Note:** **localhost** is a hostname that refers to the machine you are working on

## Comandos
```
cat sshkey.private
#copia absolutamente todo lo que este archivo, desde BEGIN a END

#en otra ternimal, fuera de la sesion bandit13
cat > nombrearchivo << 'KEY'
#cuando presionas enter vas a pegar lo que copiaste y al final escribis KEY para salir de esa terminal

chmod 600 nombrearchivo
ssh -i nombrearchivo bandit14@bandit.labs.overthewire.org -p 2220
```
- chmod
- ssh

## Contraseña
- MU4VWeTyJk8ROof1qqmcBPaLh7lDCPvS