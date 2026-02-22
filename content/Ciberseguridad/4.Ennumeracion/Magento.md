> Magento es una **plataforma de comercio electrónico de [código abierto](https://www.google.com/search?q=c%C3%B3digo+abierto&sca_esv=1224a207121717d4&sxsrf=AE3TifN7jV-Eq54Of6ZIwFJiNK3kKud-5Q%3A1766147023514&ei=z0NFaZOUH9fM5OUPu9ybwA8&ved=2ahUKEwjkj_Sx0smRAxXIBbkGHQARJgIQgK4QegQIARAC&uact=5&oq=magento&gs_lp=Egxnd3Mtd2l6LXNlcnAiB21hZ2VudG8yBxAAGIAEGAoyBRAAGIAEMgwQABiABBixAxgKGAsyCRAAGIAEGAoYCzIFEAAYgAQyCRAAGIAEGAoYCzILEC4YgAQY0QMYxwEyCRAAGIAEGAoYCzIFEAAYgAQyCRAAGIAEGAoYC0i1FlC7BFidFHADeAGQAQSYAY4BoAGJDKoBBDIuMTK4AQPIAQD4AQGYAgmgAskGqAISwgIKEAAYsAMY1gQYR8ICDRAAGIAEGLADGEMYigXCAhkQLhiABBiwAxjRAxhDGMcBGMgDGIoF2AEBwgIKEAAYgAQYQxiKBcICCBAAGIAEGMsBwgIHECMYJxjqAsICFhAuGIIGGIMGGCcY-gUY6gIY7QUY3QXCAgcQLhgnGOoCwgINECMY8AUYJxjJAhjqAsICFhAAGIAEGEMYtAIY5wYYigUY6gLYAQLCAh8QLhiABBjRAxhDGLQCGOcGGMcBGMgDGIoFGOoC2AECwgIhEC4YgAQY0QMYQxi0AhjnBhjHARjIAxiKBRjqAhgK2AECwgIKECMYgAQYJxiKBcICChAuGIAEGCcYigXCAhAQIxjwBRiABBgnGMkCGIoFwgIQEC4YgAQY0QMYxwEYJxiKBcICCBAAGIAEGLEDwgIOEC4YgAQYsQMY0QMYxwHCAg4QLhiABBixAxiDARiKBcICBBAAGAPCAgUQLhiABMICCBAuGIAEGLEDwgILEC4YgAQYxwEYrwHCAgoQLhiABBhDGIoFmAMQ4gMFEgExICnxBaH0bXxNBSD_iAYBkAYLugYECAEYCLoGBggCEAEYAZIHAzMuNqAH3KwBsgcDMC42uAeRBsIHBTMtNy4yyAeLAYAIAA&sclient=gws-wiz-serp&mstk=AUtExfANJgugaar4NaA7A6Ck-bnWPAOhugmL02wY8gxN48O5EAkZ60vObaET_OgfWg1lpCM8eXs_PpA-wuAKzveu-KIfE1lfxGW-D5FobrFwRIRyYCzgYkjzfniKkFz84JmLFPoGn6E-fF8eUI70Wjdpc_9KYBXePYLz6SS4J2bM_xvhV67iX6ImqCPSMm11wQHC2mvCLWgUMwP-IotmU5N9jxC6COUqulOUAbnkrD5rAY8T0r6D2kKq0QlF0f_4AZUW10LaknRjW913XOU6AYK1_8wq&csui=3) (PHP) altamente personalizable y escalable**, propiedad de [Adobe](https://business.adobe.com/es/products/commerce/magento.html). Ideal para grandes volúmenes de tráfico y B2B/B2C, permite gestionar inventarios, clientes y funciones avanzadas de e-commerce, ocupando cerca del 30% del mercado mundial.

## Herramientas
- [mage scan](https://github.com/steverobbins/magescan)

## Caso practico
Descargar el proyecto [magento/2.2](https://github.com/vulhub/vulhub/tree/master/magento/2.2-sqli)
```bash
svn checkout https://github.com/vulhub/vulhub/trunk/magento/2.2-sqli
cd 2.2-sqli/
docker-compose up -d
```

Hacemos el proceso de instalacion en http://localhost:8080.  
```bash
python3 magento-sqli.py http://localhost:8080/
```
Esto te devuelve la cookie de la sesion del administrador.

Dentro del buscador de Burp suite descargamos una extension Cookie Editor
`http://localhost:8080/administration/`
utilizando la extension copiamos la cookie y recargamos

## Mage scan
```bash
git clone https://github.com/steverobbins/magescan
cd magescan
```
Debemos descargar [magescan.phar](https://github.com/steverobbins/magescan/releases)
```bash
mv /home/user/Descargas/magescan.phar .
php magescan.phar
```

Escaneo basico
```
php magescan.phar scan:all https://127.0.0.1:8080
```



