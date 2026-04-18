> El ataque de redireccionamiento abierto (también conocido como redireccionamiento no validado) se produce cuando una aplicación web redirige a los usuarios a una URL proporcionada mediante un parámetro no validado. Si bien los redireccionamientos abiertos pueden utilizarse para el phishing por sí solos, su principal valor para los atacantes reside en su función como componente de cadenas de exploits: permiten a un atacante eludir las comprobaciones de validación basadas en el dominio y redirigir flujos sensibles a la seguridad (como la autorización OAuth) a través del dominio legítimo hacia un destino controlado por el atacante.

## Laboratorios
- [[skf-labs]]/nodeJS/Url-redirection
- /nodeJS/Url-redirection-harder
- /nodeJS/Url-redirection-harder2

## Ataques
- Si analizamos una peticion que mediante una url redirije al usuario a otra pagina podemos intentar inyectar otra pagina como https://google.com
```
/redirect?newurl=https://google.com
```

- A veces no se permiten determinados caracteres pero podemos codificarlo en urlencode como ser un punto '.' en urlencode es '%2e' pero todavia detecta el punto, entonces debemos aplicar de nuevo urlencode al '%' que es '%25' 
```
/redirect?newurl=https://google%252ecom
```

- Las urls https no necesitan las //, entonces se puede reducir a https:google.com
```
/redirect?newurl=https:google%252ecom
```


## Herramientas
- [[ufonet]] - medio ilegal ya para ataques ddos