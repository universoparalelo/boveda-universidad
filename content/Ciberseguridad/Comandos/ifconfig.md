> **ifconfig** es una utilidad de administración de sistemas en sistemas Unix y similares que se utiliza para configurar, mostrar y gestionar interfaces de red.  Permite asignar direcciones IP, configurar máscaras de red, activar o desactivar interfaces, cambiar direcciones MAC y verificar el estado de las conexiones de red.

```
ifconfig
```

- **Mostrar todas las interfaces, incluidas las inactivas**:  
    `ifconfig -a`
    
- **Activar una interfaz (por ejemplo, eth0)**:  
    `ifconfig eth0 up`
    
- **Desactivar una interfaz**:  
    `ifconfig eth0 down`
    
- **Asignar una dirección IP y máscara de red**:  
    `ifconfig eth0 192.168.1.10 netmask 255.255.255.0`
    
- **Cambiar la dirección MAC de una interfaz**:  
    `ifconfig eth0 down`  
    `ifconfig eth0 hw ether 13:11:20:33:49:66`  
    `ifconfig eth0 up`