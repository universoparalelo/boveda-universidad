> Una **forward shell** no es un tipo clásico como reverse o bind, sino una técnica para **redirigir tráfico a través de una máquina comprometida**.

Se usa en pivoting.
Permite acceder a servicios internos a través de la máquina comprometida.

---
## 🔁 Escenario típico

`Atacante ───► Máquina comprometida ───► Red interna`
El atacante usa la máquina comprometida como puente.

---
## 🧠 ¿Para qué sirve?

- Acceder a bases de datos internas    
- Acceder a servicios no expuestos
- Moverse lateralmente
- Escalar privilegios

---
## 🛠 Ejemplo conceptual con SSH

`ssh -L 8080:192.168.1.10:80 user@comprometida`
Eso significa:
- Todo lo que yo envíe a localhost:8080
- Se redirige a 192.168.1.10:80 desde la máquina comprometida
Es un túnel.

---
## ⚖️ Ventajas

✔️ Permite pivoting  
✔️ Acceso a redes internas  
✔️ Muy poderoso en post-explotación

## ❌ Desventajas

❌ Más complejo  
❌ Requiere control previo de una máquina

---
## Ejemplo practico
- El firewall te impide obtener una reverse shell.
- Entonces hay que crear tuberias mediante las cuales ejecutamos comandos en archivos temporales que luego se guardan en otros archivos.
- Desde el **Atacante** creamos un archivo malicioso que lee el servidor, porque esta todo correcto pero por detras ese archivo contiene codigo que la **Victima** ejecuta y guarda en otro archivo que el **Atacante** puede leer.