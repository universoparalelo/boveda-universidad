### Binario

**192.168.12.10/13**
10100000.10101000.00001100.00001010 --> (192.168.12.10)
11111111.11111000.00000000.00000000 --> (255.248.0.0 --> **MASCARA**) 
|-----------------------------------------------------------------| [AND]
10100000.10101000.00000000.00000000 --> (192.168.0.0 --> **NETWORK ID**)
10100000.10101111.11111111.11111111 --> (192.175.255.255 --> **BROADCAST**)

**Cantidad de hosts** --> 2^(32-13) = 524288

### ¿Que hice?
- 1er linea: es la direccion IP en binario, separado por puntos.
- 2da linea: es la cantidad de 1s tantas veces como /x corresponda y despues 0s.
- 3er linea: se realiza una operacion entre la 1er y 2da linea de AND. Si ambos numeros son 1 se escribe 1, sino 0.
- 4ta linea: Se escriben los mismos numeros de la 3er linea tantas veces como /x corresponda y despues 1s.

