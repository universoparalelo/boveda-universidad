> Similar al XSS una mala programacion para agregar estilos dinamicamente, dejando al usuario el control del mismo y no sanitizando la entrada, se puede acontecer inyecciones XSS.

## Laboratorios
- [[skf-labs]]/nodeJs/CSSI

## Ataque
- Es como un picker color que te deja elegir los colores del texto.
- Podemos inyectar:
```html
red;} </style> <script>alert('XSS')</script>
```
- Y te haces un pancho