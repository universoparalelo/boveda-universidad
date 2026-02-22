`sudo apt install hydra`

## Usage
```bash
hydra -l user -P passlist.txt ftp://192.168.0.1 -t 200
```
- `-l` usuario conocido
- `-P` lista de contrasenias a intentar
- `-t` cantidad de hilos