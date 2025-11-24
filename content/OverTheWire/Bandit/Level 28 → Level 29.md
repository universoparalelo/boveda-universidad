There is a git repository at `ssh://bandit28-git@bandit.labs.overthewire.org/home/bandit28-git/repo` via the port `2220`. The password for the user `bandit28-git` is the same as for the user `bandit28`.

Clone the repository and find the password for the next level.
## Comandos
```
git clone ssh://bandit28-git@bandit.labs.overthewire.org:2220/home/bandit28-git/repo

cd repo

#tenemos que ver en la historia del repo donde estaba la contrasenia con el commit que es el ID por asi decirlo
git checkout -d d0cf2ab7dd7ebc6075b59102a980155268f0fe8f

cat README.md
```

- git-checkout
## Contraseña    
- 4pT1t5DENaYuqnqvadYs1oE4QLCdjmJ7