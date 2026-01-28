```bash
#!/bin/bash

echo "Hola esto es un prueba"

ip a | grep ens33 | tail -n 1 | awk '{print $1}' FS="/"
# ip a | grep ens33 | tail -n 1 | cut -d / -f 1
# ip a | grep ens33 | tail -n 1 | tr '/' ' ' | awk '{print $1}'

echo -e '\n[+] Esta es tu direccion ip -> $(ip a | grep ens33 | tail -n 1 | awk '{print $1}' FS="/")\n'

variable="cele"

echo "Hola, $variable"
```

- Colores
```bash
#Colours
greenColour="\e[0;32m\033[1m"
endColour="\033[0m\e[0m"
redColour="\e[0;31m\033[1m"
blueColour="\e[0;34m\033[1m"
yellowColour="\e[0;33m\033[1m"
purpleColour="\e[0;35m\033[1m"
turquoiseColour="\e[0;36m\033[1m"
grayColour="\e[0;37m\033[1m"
```

- Agregar color en bash
```bash
echo -e "\n${yellowColour}Esto${endColour} ${blueColor}es un prueba${endColour} ${greenColour}de colores${endColour}\n"
```