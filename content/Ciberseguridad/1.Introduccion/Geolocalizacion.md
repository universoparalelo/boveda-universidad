## IPs locales vs. IPs públicas

Tu computadora tiene **dos "identidades" de red**:

**IP privada/local** (la que ves en tu máquina, ej: `192.168.1.105`)

- La asigna tu router mediante DHCP
- Solo existe dentro de tu red doméstica
- Miles de millones de dispositivos en el mundo comparten estos mismos rangos (192.168.x.x, 10.x.x.x, 172.16.x.x)

**IP pública** (la que ve el mundo exterior, ej: `190.210.x.x`)

- La asigna tu ISP a tu router
- Esta sí es única a nivel global (en un momento dado)
- Es la que ven los servidores cuando navegás

## Obtener tu IP global
```
curl ifconfig.me 
# o 
curl ipinfo.io
```