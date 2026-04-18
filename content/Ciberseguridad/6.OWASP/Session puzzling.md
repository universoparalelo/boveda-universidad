> La sobrecarga de variables de sesión, o Session Puzzling, es una vulnerabilidad web que ocurre cuando una variable de sesión se reutiliza para fines distintos en diferentes partes de una aplicación. Un atacante manipula estas variables para eludir la autenticación, elevar privilegios o suplantar usuarios, llevando a cabo acciones no autorizadas.

## Laboratorio
- [[skf-labs]]/nodeJs/sessionPuzzle
## Ataque
- Basicamente se trata de que en la parte de `Forgot your password?` en la respuesta se encuentra una cookie de sesion jwt que podes usarla para loguearte sin saber la contrasenia y demas.