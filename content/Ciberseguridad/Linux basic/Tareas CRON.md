> Las tareas cron en Linux permiten automatizar comandos o scripts a intervalos fijos (minutos, horas, días) usando el demonio `crond` y el archivo `crontab` (cron table). Se configuran mediante la terminal con `crontab -e` para editar tareas repetitivas como copias de seguridad, limpieza de caché o actualizaciones, optimizando la administración del sistema.

**Estructura de un Cron Job**  
Una línea en `crontab` consta de 5 campos de tiempo seguidos por el comando:  
`* * * * * comando_a_ejecutar` 

1. Minuto (0-59)
2. Hora (0-23)
3. Día del mes (1-31)
4. Mes (1-12)
5. Día de la semana (0-7, donde 0 y 7 son domingo)

- Para listar todas las tareas cron actuales
```
cd /etc/cron.d | ls -l
```

## Crear tus propias tareas
[Generador de tareas cron](https://www.site24x7.com/es/tools/crontab/cron-generator.html)
