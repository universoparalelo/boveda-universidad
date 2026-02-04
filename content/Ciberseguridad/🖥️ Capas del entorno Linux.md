## 📌 Idea general

Un sistema Linux está compuesto por múltiples capas que trabajan juntas para permitir que el usuario interactúe con la computadora.
Podemos imaginarlo como una pila que va desde el hardware hasta los programas que usamos.

---
# 🧅 Pila del sistema Linux
```
Hardware  
↓  
Kernel Linux  
↓  
Userland (GNU + herramientas base)  
↓  
Distribución (Ubuntu, Kali, Arch, etc.)  
↓  
Display Server (Wayland / X11)  
↓  
Desktop Environment (GNOME, KDE, XFCE, etc.)  
↓  
Window Manager  
↓  
Terminal Emulator  
↓  
Shell  
↓  
Multiplexores (tmux, screen)  
↓  
Aplicaciones del usuario
````

---
# 1️⃣ Hardware

Componentes físicos de la computadora:
- CPU
- RAM
- Disco
- GPU
- Periféricos

👉 Es lo único que existe físicamente.

---
# 2️⃣ Kernel Linux
El kernel es el **núcleo del sistema operativo**.
## Funciones principales
- Administrar procesos
- Manejar memoria
- Controlar hardware mediante drivers
- Manejar red
- Administrar permisos

📌 Linux técnicamente es solo el kernel.

---
# 3️⃣ Userland (GNU + herramientas base)

Son los programas básicos que permiten usar el sistema.
Incluye:
- coreutils (`ls`, `cp`, `mv`, etc.)
- librerías
- systemd (arranque del sistema)
- shells
- utilidades básicas

👉 Kernel + GNU = GNU/Linux

---
# 4️⃣ Distribuciones Linux
Una distribución es un sistema operativo completo basado en Linux.
## Incluye
- Kernel
- Programas base
- Gestor de paquetes
- Configuración
- Software adicional
## Ejemplos

| Distribución | Base          |
| ------------ | ------------- |
| Ubuntu       | Debian        |
| Kali         | Debian        |
| Parrot       | Debian        |
| Arch         | Independiente |

---
# 5️⃣ Display Server (Sistema gráfico)

Permite que los programas dibujen ventanas y gráficos.

---
## 🧱 X11 (Xorg)
Sistema tradicional.
### Características
- Muy compatible
- Modular
- Antiguo pero estable

---
## ⚡ Wayland
Reemplazo moderno de X11.
### Ventajas
- Más seguro
- Mejor rendimiento
- Arquitectura más simple

---
## Ver cuál estás usando
```bash
echo $XDG_SESSION_TYPE
````

---
# 6️⃣ Desktop Environment (Entorno de Escritorio)
Es la interfaz gráfica completa que ve el usuario.
Incluye:
- Paneles
- Menús
- Configuración
- Aplicaciones gráficas
- Window manager

---
## Ejemplos

| Entorno    | Características      |
| ---------- | -------------------- |
| GNOME      | Moderno, minimalista |
| KDE Plasma | Muy personalizable   |
| XFCE       | Liviano              |
| LXQt       | Muy liviano          |
| Cinnamon   | Tradicional          |

---
👉 Una misma distro puede usar distintos entornos.
Ejemplo:
- Ubuntu → GNOME
- Kubuntu → KDE
- Xubuntu → XFCE

---
# 7️⃣ Window Manager
Controla el comportamiento de las ventanas.
Funciones:
- Posicionamiento
- Bordes
- Animaciones
- Tiling o stacking

---
## Ejemplos

| WM        | Usado en    |
| --------- | ----------- |
| Mutter    | GNOME       |
| KWin      | KDE         |
| i3        | Tiling WM   |
| bspwm     | Minimalista |
| awesomeWM | Scriptable  |

---
# 8️⃣ Terminal Emulator
Programa gráfico que simula una terminal.
👉 No es el shell.

---
## Ejemplos
- kitty
- gnome-terminal
- alacritty
- konsole
- xterm

---
# 9️⃣ Shell
Intérprete de comandos que ejecuta lo que escribe el usuario.

---
## Ejemplos

| Shell | Características      |
| ----- | -------------------- |
| bash  | Estándar universal   |
| zsh   | Muy configurable     |
| sh    | Minimalista          |
| fish  | Amigable visualmente |

---
## Ver qué shell usás
```bash
echo $SHELL
```

---
# 🔟 Multiplexores de terminal
Permiten manejar múltiples sesiones dentro de una terminal.

---
## tmux
Permite:
- Dividir pantalla
- Mantener procesos activos
- Reconectar sesiones remotas
- Trabajar con múltiples paneles

---
# 📦 ¿Todo esto son paquetes?
La mayoría sí, pero representan **capas conceptuales distintas**.
Ejemplo:
```bash
sudo apt install gnome-shell
sudo apt install kitty
sudo apt install zsh
sudo apt install tmux
```

---
# 🧠 Analogía: La casa Linux

| Capa                | Analogía              |
| ------------------- | --------------------- |
| Hardware            | Terreno               |
| Kernel              | Cimientos             |
| Distribución        | Estructura de la casa |
| Display server      | Electricidad          |
| Desktop environment | Muebles y decoración  |
| Terminal            | Escritorio            |
| Shell               | Usuario escribiendo   |
| tmux                | Múltiples escritorios |

---
# 🔍 Comandos útiles para inspeccionar el sistema

## Kernel
```bash
uname -r
```

---
## Entorno gráfico
```bash
echo $DESKTOP_SESSION
```

---
## Display server
```bash
echo $XDG_SESSION_TYPE
```

---
## Shell actual
```bash
echo $SHELL
```

---
# 📚 Conceptos clave resumidos

- Linux = Kernel
- Distribución = Sistema operativo completo
- Wayland/X11 = Sistema gráfico
- Desktop Environment = Interfaz visual completa
- Terminal Emulator = Programa que abre terminal
- Shell = Intérprete de comandos
- tmux = Multiplexor de terminal
