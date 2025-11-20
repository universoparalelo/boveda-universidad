There is a setuid binary in the homedirectory that does the following: it makes a connection to localhost on the port you specify as a commandline argument. It then reads a line of text from the connection and compares it to the password in the previous level (bandit20). If the password is correct, it will transmit the password for the next level (bandit21).

**NOTE:** Try connecting to your own network daemon to see if it works as you think
## Comandos
```
#Tenes 2 terminales y entras a bandit20 con las dos

#Terminal A
nc -l -p 4444

#Terminal B
./suconnect 4444

#Terminal A de vuelta
0qXahG8ZjOVMN9Ghs7iOWsCfZyXOUbYO #que es la contrasenia del nivel anterior
```
- nc
## Contraseña    
- EeoULMCra2q0dSkYj561DX7s1CpBuOBt