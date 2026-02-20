```
docker ps
```
- Visualizar contenedores activos

`docker ps -a` incluye contenedores que estan frenados
`docker rm <container-id>`
`docker rm <container-id> --force` matas contenedores que estan corriendo
`docker rm $(docker ps -a -q) --force` matas todos los contenedores

## Frenar un contenedor
`docker stop <container-id>`