- Buscar en Internet datos reales de Universidad para armar la BD

### OLTP
- No guarda historia

### OLAP
- Enriquece los datos, estan mejor ordenados

## Proceso de ETL
- Se tarda el doble en armar el etl que el esquema de la bd
- Se hace a medida
- Herramientas sin/con codigo 
- Lo hace generalmente el Ingeniero de Datos
- A veces el cliente quiere un reporte, no un DW elaborado
- Debe tener una documentación
- Sistema fuente -> Extraccion -> Staging Area(se colocan los datos sin procesar, se limpia luego) -> Transformacion -> Carga -> DW/OLAP
- **No se usan primary keys se usan claves subrogadas**, deben ser independientes al modelo oltp

### Extraccion
- Se recomienda hacer 2 codigos para la carga inicial y otra para una carga incremental

### Transformacion
- Unificar los datos
- Crear las claves subrogadas

### Carga
- Se graban los datos transformados directamente al DW
- Aca nos damos cuenta de si hicimos la extraccion y tranformacion de forma correcta
- Frecuencia de carga: mensual, diaria, horario, streaming
- Como hacemos la indexacion? Se borran las claves id y foreign key
- Podemos hacer una carga minima para chequear que este correcto todo

### Calidad de los datos
- Las dimensiones deben ser consistentes
- MDM son los datos maestros que deben ser de calidad para alimentar el DW luego
- El ETL debe tener metadatos para saber como hizo el proceso completo y controlarlo por si hubo errores
- 