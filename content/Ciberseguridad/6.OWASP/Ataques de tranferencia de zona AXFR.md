> El **DNS (Sistema de Nombres de Dominio)** es el sistema que traduce nombres de dominio legibles por humanos (como `example.com`) en direcciones IP que entienden las máquinas. Funciona como una “guía telefónica” de Internet. Una consulta DNS es simple: el cliente envía un nombre de dominio y recibe una IP como respuesta. Para poder hacer la consulta, el cliente ya debe conocer el nombre del host.

---
### Zonas DNS

Los servidores DNS organizan la información en **zonas**, que son partes del espacio de nombres que administran.
Por ejemplo:
- `example.com` puede ser una zona completa
- `sub.example.com` también puede ser una zona independiente

---
### Importancia del DNS

El DNS es un servicio crítico. Si falla un servidor y no hay caché disponible, el dominio deja de funcionar (web, mail, etc.).
Por eso, cada zona debe tener al menos:
- Un servidor primario
- Uno o más secundarios

---
### Transferencia de zona (AXFR)

Cuando hay cambios en una zona, es necesario que todos los servidores estén sincronizados. Hacer esto manualmente es ineficiente, por lo que se usan **transferencias de zona**.
El mecanismo más simple es **AXFR**:
- El servidor primario tiene la información actualizada
- El secundario solicita una copia completa de la zona
- Se replica toda la información

---
### Riesgo de seguridad

AXFR no tiene autenticación por defecto. Si no está bien configurado, cualquier cliente podría solicitar la zona.
Esto implica que un atacante puede obtener:
- Subdominios
- Hosts internos
- Direcciones IP
Es decir, un mapa bastante completo del sistema.

---
### Ejemplo con dig

Consultar servidores DNS:
```bash
dig +short ns zonetransfer.me
```

Intentar transferencia de zona:
```bash
dig axfr zonetransfer.me @nsztm1.digi.ninja.
```


## Laboratorio
- Vulhub/dns/dns-zone-transfer

- Descubrir dominios
```
dig @localhost -p 5354
```

- Descubrir subdominios
```
dig @localhost -p 5354 NS vulhub.org
```

- Realizar el axfr
```
dig @localhost -p 5354 axfr vulhub.org
```

Si funciona, devuelve todos los registros de la zona.

---
### Idea clave

Las transferencias de zona son necesarias, pero deben estar restringidas. Si no se controlan, exponen información sensible de la infraestructura.