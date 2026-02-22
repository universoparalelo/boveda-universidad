- [Link de descarga](https://github.com/SamJoan/droopescan)

## Instalacion:
```bash
git clone https://github.com/SamJoan/droopescan
cd droopscan/
python3 -m venv venv
source venv/bin/activate
```
- Antes de hacer el `pip` vamos a reemplar estas lineas en `setup.py`
```
install_requires=[
        'cement>=2.10,<2.10.99',
        'setuptools',
        'requests',
        'pystache',
    ],
```
- Ahora si podemos estar tranquilos
```
pip install -r requirements.txt
./droopescan scan --help
```

Escaneo basico:
```bash
droopscan scan drupal --url http://localhost:8080
```
