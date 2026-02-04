- Clonar repo
```
git clone url
```

- Para ver la historia
```
git log
```

- Para ver que cambios se realizo en un determinado commit
```
git show <id_commit>
```

- Ver otras ramas existentes
```
git branch -a
```
- `-a` es para ver todas las ramas, incluso las que no estan en local

- Cambiar de rama
```
git checkout <rama>
```

- Ver si hay tags en el repo
```
git tag
```
- Se utilizan para marcar puntos importantes en la historia

- Mostrar que hay en el tag
```
git show <tag>
```

- Para aniadir archivos al lugar de trabajo
```
git add .
```

- Para crear un commit
```
git commit -m "mensaje"
```

- Para subirlo al repositorio remoto
```
git push origin main
```