Logging in to bandit26 from bandit25 should be fairly easy… The shell for user bandit26 is not /bin/bash, but something else. Find out what it is, how it works and how to break out of it.

NOTE: if you’re a Windows user and typically use Powershell to ssh into bandit: Powershell is known to cause issues with the intended solution to this level. You should use command prompt instead.
## Comandos
```
cat bandit26.sshkey
#copiar desde BEGIN to END

exit
touch bandit26.sshkey
nano bandit26.sshkey
#pegar el contenido anterior y control 0 control x
chmod 600 bandit26.sshkey
ssh -i bandit26.sshkey bandit26@bandit.labs.overthewire.org -p 2220
```

## Contraseña    
- archivo rsa