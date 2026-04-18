> JWT (JSON Web Token) es un estándar abierto (RFC 7519) que define una forma compacta y autónoma para transmitir información segura entre partes como un objeto JSON. Se utiliza principalmente para autenticación y autorización, permitiendo al servidor verificar la identidad del usuario y sus permisos mediante una firma digital, sin necesidad de guardar la sesión en el servidor.

## Caracteristicas
> Partes de un JWT:
- Header: Indica el tipo de token y el algoritmo de firma (ej. HMAC SHA256 o RSA).
- Payload: Contiene las "declaraciones" (claims), como el ID del usuario, nombre, y fecha de expiración.
- Signature: Se crea tomando el header codificado, el payload codificado, una clave secreta y el algoritmo especificado en el header para asegurar la integridad.

## Laboratorio
- [[skf-labs]]/nodeJs/JWT-null
- [[skf-labs]]/nodeJs/JWT-secret

## Ataques
- En el primer laboratorio debemos de poder loguearnos como `user2` a partir de ser `user`
- El algoritmo del jwt puede ser NONE y no es necesaria la firma.
- En otros casos en necesario que este pero no necesariamente correcta
- Cada parte del jwt esta en base64

