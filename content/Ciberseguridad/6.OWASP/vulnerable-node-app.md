- [Link al repo](https://github.com/Charlie-belmer/vulnerable-node-app)

## Cambios a realizar
- En `app/Dockerfile`
```
FROM node:18
```
- En `app/routes/default.route.js`
```
for (var i=0; i < users.length; i++) {
	user = new User(users[i]);
	user.save()
		.then(item => {
			console.log("added user " + item.username)
		})
		.catch(err => {
			console.log("Error adding user " + err)
		});
}
```
- Hay que cambiar _u.username_ en `then` y _u.username_ en `catch`
## Contruir el contenedor
```
docker-compose build
docker-compose up
```

- `http://localhost:4000`