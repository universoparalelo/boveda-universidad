> Un ataque de oráculo de relleno (Padding Oracle Attack) es una técnica criptográfica que descifra datos cifrados abusando de los mensajes de error de un servidor. Al manipular el texto cifrado y analizar si el relleno es válido, el atacante deduce información byte a byte sin conocer la clave secreta.

## Cifrado CBC
![[Pasted image 20260323092717.png]]
### Cómo funciona el cifrado CBC

En CBC, antes de cifrar un bloque de texto plano, se combina mediante una operación **XOR** con el bloque de texto cifrado anterior.

1. **Vector de Inicialización (IV):** Como el primer bloque no tiene un bloque cifrado previo, se utiliza un valor aleatorio llamado IV.
2. **Encadenamiento:** Cada bloque de texto cifrado depende de todos los bloques de texto plano procesados hasta ese punto.
    - $C_i = E_K(P_i \oplus C_{i-1})$
3. **Descifrado:** El proceso se invierte. Se descifra el bloque y luego se aplica XOR con el bloque cifrado anterior para recuperar el texto plano.
    - $P_i = D_K(C_i) \oplus C_{i-1}$

### El Rol del Padding (Relleno)

Los algoritmos de bloque (como AES) requieren que los datos tengan un tamaño específico (ej. 16 bytes). Si tu mensaje es más corto, se añade **Padding**. El estándar más común es **PKCS#7**, donde si faltan 3 bytes, se añade tres veces el valor `03`. Al descifrar, el sistema verifica que el padding sea correcto antes de entregar los datos.
### ¿Por qué es vulnerable al Padding Oracle?

El ataque **Padding Oracle** ocurre cuando un servidor responde de manera distinta según si el padding de un mensaje enviado es válido o no. No necesitas la clave; solo necesitas que el servidor te "diga" si el formato es correcto.
### La mecánica del ataque

El atacante manipula el bloque de texto cifrado anterior ($C_{i-1}$) para alterar el resultado del texto plano del bloque actual ($P_i$) tras el descifrado.

1. **Modificación del Bit:** El atacante envía un bloque cifrado modificado.
2. **La Respuesta del "Oráculo":** * Si el servidor responde con un error de aplicación, el padding era **correcto**.
    - Si el servidor responde con un error de "Padding inválido", el atacante sabe que su modificación rompió la estructura.
3. **Fuerza Bruta Dirigida:** Al probar los 256 valores posibles para un byte del bloque previo y observar cuándo el servidor acepta el padding, el atacante puede deducir el valor original del texto plano mediante álgebra simple de XOR.

> **En resumen:** El atacante usa las respuestas de error del servidor como una "guía" para adivinar el contenido del mensaje, byte por byte, transformando un problema criptográfico en uno de lógica de errores.

### Prevencion
Para evitar esto, hoy en día se prefieren modos de cifrado autenticados como **AES-GCM**, que detectan si el mensaje ha sido manipulado antes de intentar descifrarlo.

## Herramientas
- [[padbuster]]
- Intruder de [[burpsuite]]

## Laboratorio
- Nos descargamos[[padding oracle]]
- Hacemos un escaneo a nivel local
```
arp-scan -I ens33 192.168.111.0 --localnet --ignoredups
```
- tambien sirve
```
nmap -sn 192.168.111.0/24
```

- Descubrimos puertos
```
nmap -p- --open -n -Pn -v 192.168.111.87
```

- Vemos el puerto 80 abierto asi que vamos a un navegador y entramos a `192.168.111.87` y automaticamente abre el puerto 80
- El objetivo de este laboratorio es loguearnos como el usuario admin

## Padbuster
```
padbuster http://192.168.111.87 cookie 8 -cookie 'auth=cookie'
```
- Antes de desencriptar me da una opcion para elegir la forma de desencriptar, siempre es la 2.
- `http:` la url de ataque
- `cookie` la cookie a hackear
- `8` el tamanio del bit de ataque
- `-cookie` las credenciales para poder realizar el ataque, cabeceras necesarias en este caso

### Encriptando
- Ahora si queremos el proceso contrario, es decir, obtener una cookie para loguearnos como admin debemos:
```
padbuster http://192.168.111.87 cookie 8 -cookie 'auth=cookie' -plaintext 'user=admin'
```

## Intruder
- Nos tenemos que crear un usuario con el nombre similar a 'admin', puede ser 'bdmin', 'cdmin', etc.
- Creamos un usuario 'cdmin' e interceptamos la recarga de la pagina con Burpsuite
- Mandamos el request a Intruder `ctrl_i` y realizamos una ataque de tipo Sniper Bit Flipper y lo importante es realizarlo sin url encoded.
- A partir de ahi es esperar a que salga una peticion con una longitud diferente y tal, e ir chequeando hasta encontrar una donde nos logramos loguear como admin.
- No hay mas truco.