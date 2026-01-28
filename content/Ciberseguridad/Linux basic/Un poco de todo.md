```
hostname -I | awk '{print $1}'
```

```
echo "Esta es mi ip: $(hostname -I | awk '{print $1}')"
```
- Para utilizar el output de un comando **$()**

### Configurar tu zsh
- En el archivo .zshrc o ~/.zshrc:
```
function vermiip(){
	echo "Esta es mi ip: $(hostname -I | awk '{print $1}')"
}
```
- Podes definir funciones que luego podes utilizarlas como comandos _vermiip_
```
alias cat="batcat"
alias ls="lsd"
```
- O aliases para otros comandos

## Actualizacion del sistema
```
sudo su
apt update
apt upgrade
```

*Excepto en parrot*
```
sudo su
apt update
parrot-upgrade
```

## Tmux
- Instalar Tmux [oh my tmux](https://github.com/gpakosz/.tmux)

## Diferencias entre archivos
```
diff password.old password.new
```
- `<` pertenece al primer archivo
- `>` pertenece al segundo
- `a` se ha aniadido (al segundo)
- `d` se ha eliminado
- `c` ha cambiado

## Abrir un puerto

```
nc -nlvp 4646
```

## Mirar que ocurre cada segundo en un directorio
```
watch -n 1 ls -l
```