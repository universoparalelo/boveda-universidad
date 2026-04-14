> El abuso de las API se refiere al uso malicioso de una API mediante métodos que difieren de los casos de uso previstos o aceptables. Estos métodos podrían implicar la extracción excesiva de datos, el acceso no autorizado a los datos, la introducción de código malicioso o la interrupción de los servicios.

## Funcionamiento de una API
> El término API es una abreviatura de "application programming interface" (interfaz de programación de aplicaciones); es un conjunto de protocolos y definiciones que permiten a los distintos componentes o programas de software comunicarse entre sí y compartir datos.

- Las API determinan cómo una aplicación puede acceder a los datos o funciones que ofrece otro programa de software. 
- Por ejemplo, para incluir información meteorológica en un sitio web, los programadores pueden utilizar una API para comunicarse con un sitio que proporciona informes meteorológicos en tiempo real en lugar de tener que crear su propio programa para recopilar e interpretar datos meteorológicos. 
- En el mundo digital actual, las API participan en casi todas las acciones y transacciones que realiza online, incluida la realización de pagos móviles o la navegación por un sitio de comercio electrónico.
![[Pasted image 20260411120244.png]]

## Laboratorio
- [crAPI](https://github.com/OWASP/crAPI)
- `cd crAPI/deploy/docker`
- `docker compose pull`
- `docker compose -f docker-compose.yml --compatibility up -d`
- Debe salir todo bien, todo healthy, sino elimina todo y vuelve a intentar. Y si tampoco funciona hay un archivo para los troubleshooting.

## Formas de explotar
- Cuando me olvide la contrasenia me pide solo la nueva y un token llamado otp que son 4 digitos, aplicamos fuerza bruta.
- Hay urls que se basan en versiones, y lo especifican en la url, entonces al volver a una version anterior podemos utilizar esa vulnerabilidad.
- Hay veces que al ennumerar que metodos se pueden usar para una url determinada se puede usar post, con el cual podemos crear objetos de forma no autorizada, porque no somos los administradores del sitio, y crear un producto con valor negativo (-1000) y comprarlo para asi tener mas dinero.
- Cuando creamos un vehiculo podemos ennumerar los vehiculos de otras personas y ver informacion personal, por posts que realizan a un foro.
- Los cupones tambien detras tiene una base de datos mongo y podemos aplicar inyecciones nosql
- *Podriamos ver si aplica lo mismo en el login*

## Herramientas 
- [[postman]]


