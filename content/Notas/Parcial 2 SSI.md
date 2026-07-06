**DISEÑO DE PROGRAMA DE SEGURIDAD – Evaluación Individual**  
  
**Contexto:** Fintech regional con integración a múltiples APIs bancarias.  
**Entorno tecnológico:** Cloud pública (IaaS/PaaS).  
Existe presión regulatoria para mejorar controles y auditoría.  
La organización busca alinear sus prácticas con estándares internacionales y mejorar su madurez en seguridad.  
  
## **Consigna:** Diseñe un programa mínimo de seguridad aplicando el caso presentado. Máximo: 350 palabras. _Evite respuestas genéricas; priorice medidas aplicables al contexto tecnológico y organizacional._  
  
1) **Objetivo estratégico:** Defina el objetivo del programa en un máximo de 3 líneas.  
2) **Política clave:** Nombre una política relevante y defina su alcance: qué cubre y a quién aplica.  
3) **Roles mínimos:** Defina tres roles: responsable, operación y auditoría. Indique una responsabilidad concreta para cada uno.  
4) **Controles priorizados:** Proponga cinco controles concretos, coherentes con el contexto tecnológico y organizacional.  
5) **Respuesta a incidentes:** Proponga un flujo mínimo de respuesta a incidentes, ordenado en seis pasos.  
6) **Métricas:** Proponga dos métricas: una operativa y una de gestión.  
7) **Riesgo cloud específico y mitigación:** Identifique un riesgo propio del uso de servicios cloud y proponga una mitigación concreta, considerando las responsabilidades del cliente y del proveedor.  
8) **Declaración de uso de IA:** Indique si utilizó IA. En caso afirmativo, declare herramienta utilizada y propósito de uso.  
_Se penalizarán propuestas incoherentes con el contexto, sin priorización o que no demuestren aplicación personal de los contenidos._

### Respuesta

**1) Objetivo estratégico**

Implementar un Programa de Seguridad de la Información que proteja los datos financieros y personales de los clientes, garantice la disponibilidad de los servicios y el cumplimiento regulatorio, alineando la organización con buenas prácticas internacionales como ISO/IEC 27001 y el marco NIST.

**2) Política clave**

**Política de Gestión de Accesos e Identidades.** Aplica a empleados, administradores, desarrolladores y terceros con acceso a la infraestructura cloud y a las APIs bancarias. Define autenticación multifactor, principio de mínimo privilegio, revisión periódica de permisos y gestión segura de credenciales.

**3) Roles mínimos**

- **Responsable:** CISO. Define la estrategia de seguridad, aprueba políticas y gestiona los riesgos.
- **Operación:** Administrador de Seguridad Cloud. Implementa controles, monitorea eventos de seguridad y administra identidades y configuraciones.
- **Auditoría:** Auditor Interno. Verifica el cumplimiento de políticas, revisa evidencias y recomienda acciones de mejora.

**4) Controles priorizados**

- Implementar MFA para todos los accesos administrativos y privilegiados.
- Aplicar cifrado de datos en tránsito (TLS) y en reposo utilizando servicios nativos del proveedor cloud.
- Centralizar logs de infraestructura, aplicaciones y accesos mediante un SIEM para auditoría y detección temprana.
- Realizar revisiones periódicas de permisos IAM aplicando el principio de mínimo privilegio.
- Ejecutar análisis automáticos de vulnerabilidades y gestión de parches sobre máquinas virtuales y aplicaciones expuestas.

**5) Respuesta a incidentes**

1. Detección y registro del incidente.
2. Clasificación y evaluación del impacto.
3. Contención inmediata (aislamiento de recursos comprometidos).
4. Erradicación de la causa raíz.
5. Recuperación mediante restauración y validación del servicio.
6. Lecciones aprendidas y actualización de controles y procedimientos.

**6) Métricas**

- **Operativa:** Tiempo promedio de aplicación de parches críticos desde su publicación. 
- **De gestión:** Porcentaje de hallazgos de auditoría corregidos dentro del plazo establecido.

**7) Riesgo cloud específico y mitigación**

**Riesgo:** Configuración incorrecta de recursos cloud (por ejemplo, almacenamiento expuesto públicamente).  
**Mitigación:** El proveedor asegura la infraestructura física y la disponibilidad del servicio, mientras que el cliente es responsable de configurar correctamente IAM, redes y almacenamiento. Se implementarán revisiones automáticas de configuraciones, políticas de infraestructura como código y auditorías periódicas.

**8) Declaración de uso de IA**

Se utilizó ChatGPT como herramienta de apoyo para organizar y redactar la respuesta, aplicando los conceptos trabajados en la materia y adaptándolos al caso propuesto.

---
## **BIA, RTO, RPO Y PRIORIDAD DE RECUPERACIÓN – Evaluación Individual**  
  
**Contexto:**  
Una empresa de energía monitorea subestaciones mediante sistemas remotos y centro de control.  
  
**Incidente:**  
Un incendio en la sala técnica afecta servidores de monitoreo y comunicaciones internas.  
  
**Restricciones del caso:**

- El control local de subestaciones permanece operativo.
- El centro de control pierde visibilidad parcial.
- Existe sitio alternativo con capacidad limitada.
- La comunicación con cuadrillas es crítica.

**Procesos afectados:**  

|Proceso|Descripción breve|Tipo de impacto principal|
|---|---|---|
|Centro de control|Supervisión de subestaciones|Operativo / seguridad|
|Comunicaciones con cuadrillas|Coordinación de atención en campo|Operativo|
|Monitoreo de alarmas|Detección de fallas críticas|Seguridad / operativo|
|Gestión de reclamos|Atención a usuarios afectados|Reputacional|
|Reportes regulatorios|Información a organismos de control|Legal|

  
**Escala de impacto:**  
1 = No significativo; 2 = Bajo / tolerable; 3 = Moderado; 4 = Significativo; 5 = Severo.  
**Umbral máximo tolerable:** nivel 2. Cuando el impacto supera este nivel, debe analizarse la activación de medidas de continuidad o recuperación.  
  
**Consigna:**  
Complete las dos planillas BIA solicitadas. No se exige una única respuesta exacta, pero sí una solución coherente y defendible. El impacto debe mantenerse o aumentar a medida que crece el tiempo de interrupción.  
  
**1) Matriz de Impacto BIA**  
Complete la matriz con valores de 1 a 5 para cada proceso y franja horaria.  

|Proceso|15 min|30 min|1 h|2 h|4 h|8 h|Tipo de impacto|
|---|---|---|---|---|---|---|---|
|Centro de control|||||||Operativo / seguridad|
|Comunicaciones con cuadrillas|||||||Operativo|
|Monitoreo de alarmas|||||||Seguridad / operativo|
|Gestión de reclamos|||||||Reputacional|
|Reportes regulatorios|||||||Legal|

  
**Justificación breve:**  
- Proceso más crítico:  
- Motivo:  
- Proceso menos crítico:  
- Motivo:  
  
**2) Planilla de RTO, RPO y Prioridad de Recuperación**  
Complete la siguiente planilla a partir de la matriz anterior.  

|Proceso|RTO|RPO|MTD|Prioridad|Plan activado|Crítico|
|---|---|---|---|---|---|---|
|Centro de control|||||||
|Comunicaciones con cuadrillas|||||||
|Monitoreo de alarmas|||||||
|Gestión de reclamos|||||||
|Reportes regulatorios|||||||

  
**Pautas:**  
- RTO: tiempo objetivo de recuperación.  
- RPO: pérdida máxima tolerable de información.  
- MTD: tiempo máximo tolerable de interrupción.  
- Prioridad: alta, media o baja.  
- Plan activado: IRP, BCP, DRP o combinación.  
- Crítico: sí, no o condicional.  
  
**Justificación breve de la prioridad:**  
- Orden de recuperación propuesto:  
- Motivo principal:  
- Dependencias relevantes:  
  
**3) Declaración de uso de IA**  
Indique si utilizó IA. En caso afirmativo, declare herramienta utilizada y propósito de uso.  
_Se evaluará la coherencia entre impacto, criticidad, RTO, RPO, MTD, prioridad, plan activado y adaptación al escenario._

### Respuesta

# 1) Matriz de Impacto BIA

|Proceso|15 min|30 min|1 h|2 h|4 h|8 h|Tipo de impacto|
|---|:-:|:-:|:-:|:-:|:-:|:-:|---|
|Centro de control|2|3|4|5|5|5|Operativo / seguridad|
|Comunicaciones con cuadrillas|2|3|4|5|5|5|Operativo|
|Monitoreo de alarmas|2|3|5|5|5|5|Seguridad / operativo|
|Gestión de reclamos|1|1|2|3|4|5|Reputacional|
|Reportes regulatorios|1|1|1|2|3|4|Legal|

**Justificación breve**

- **Proceso más crítico:** Monitoreo de alarmas.
    
- **Motivo:** La pérdida de detección de fallas puede impedir reaccionar ante eventos que comprometan la seguridad de la infraestructura eléctrica y aumentar el riesgo operativo.
    
- **Proceso menos crítico:** Reportes regulatorios.
    
- **Motivo:** Aunque son obligatorios, su impacto es principalmente legal y suele manifestarse en plazos mayores que las primeras horas del incidente.
    

---

# 2) Planilla de RTO, RPO y Prioridad de Recuperación

|Proceso|RTO|RPO|MTD|Prioridad|Plan activado|Crítico|
|---|---|---|---|---|---|---|
|Centro de control|1 h|15 min|2 h|Alta|IRP + DRP + BCP|Sí|
|Comunicaciones con cuadrillas|30 min|15 min|2 h|Alta|IRP + BCP|Sí|
|Monitoreo de alarmas|30 min|0-15 min|1 h|Alta|IRP + DRP|Sí|
|Gestión de reclamos|4 h|1 h|8 h|Media|BCP|No|
|Reportes regulatorios|8 h|4 h|24 h|Baja|DRP|Condicional|

**Justificación de la prioridad**

- **Orden de recuperación propuesto:**
    
    1. Monitoreo de alarmas.
        
    2. Comunicaciones con cuadrillas.
        
    3. Centro de control.
        
    4. Gestión de reclamos.
        
    5. Reportes regulatorios.
        
- **Motivo principal:** Se priorizan los procesos cuya indisponibilidad afecta directamente la seguridad de la operación, la detección de fallas y la coordinación de las cuadrillas de campo. Luego se recuperan los procesos administrativos y regulatorios, cuyo impacto es diferido.
    
- **Dependencias relevantes:** El centro de control depende de las comunicaciones y de la infraestructura tecnológica recuperada en el sitio alternativo. El monitoreo de alarmas requiere servidores, enlaces de comunicación y acceso a las subestaciones. La gestión de reclamos depende de la disponibilidad del centro de control para brindar información actualizada a los usuarios.
    

---

# 3) Declaración de uso de IA

Se utilizó ChatGPT como herramienta de apoyo para organizar el análisis BIA y completar la matriz de impacto, RTO, RPO y prioridades de recuperación, aplicando los conceptos desarrollados en la materia y adaptándolos al escenario planteado.