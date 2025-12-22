> Joomla! **es uno de los softwares de sitios web más populares**, gracias a su comunidad global de desarrolladores y voluntarios, quienes se aseguran de que la plataforma sea fácil de usar, extensible, multilingüe, accesible, responsiva, optimizada para motores de búsqueda y mucho más.

## Herramientas
- [joom scan](https://github.com/OWASP/joomscan) 

## Caso practico
Descargar el proyecto de vulhub [joomla/CVE2015](https://github.com/vulhub/vulhub/tree/master/joomla/CVE-2015-8562)
```bash
svn checkout https://github.com/vulhub/vulhub/trunk/joomla/CVE-2015-8562
cd CVE-2015-8562
docker-compose up -d
```

## Joom scan
```bash
git clone https://github.com/rezasp/joomscan.git
cd joomscan
perl joomscan.pl
```

Uso comun:
```bash
perl joomscan.pl --u http://localhost:8080
```

**Para ver el reporte de forma bonita**:
```bash
cd reportes/localhost_8080/
mv nombre_larguisimo_del_archivo index.html
python3 -m http.server 80
```
Y entras desde la web http://localhost:80
