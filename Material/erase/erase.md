<!-- LIBRERIA STL -->
# STRINGS 
### ¿Qué es un string?
Un string es una secuencia de caracteres que se almacenan en memoria de forma contigua. Los strings son contenedores de la librería estándar de C++.

##### Declaración de un string
```cpp
string nombre;
string saludo = "Hola";
string despedida("Adios");
string frase(10, 'a'); // frase = "aaaaaaaaaa"
```

##### Acceder a un caracter del string
```cpp
nombre[posicion];
```

##### Tamaño del string
```cpp
nombre.size();
```

##### Recorrer un string
```cpp
for (int i = 0; i < nombre.size(); i++) {
    cout << nombre[i] << endl;
}
```

##### Añadir un caracter al final del string
```cpp
nombre.push_back(caracter);
```

##### Eliminar el último caracter del string
```cpp
nombre.pop_back();
```

##### Eliminar un caracter del string
```cpp
nombre.erase(posicion);
```

##### Eliminar un rango de caracteres del string
```cpp
nombre.erase(posicion, longitud);
```

##### Insertar un caracter en el string
```cpp
nombre.insert(posicion, caracter);
```

##### Insertar un rango de caracteres en el string
```cpp
nombre.insert(posicion, cadena);
```

##### Buscar un caracter en el string
```cpp
nombre.find(caracter);
```
#### Convertir a mayúsculas
```cpp
// first version
for (int i = 0; i < nombre.size(); i++) {
    nombre[i] = toupper(nombre[i]);
}
// second version
transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);
```

#### Convertir a minúsculas
```cpp
// first version
for (int i = 0; i < nombre.size(); i++) {
    nombre[i] = tolower(nombre[i]);
}
// second version
// transform(int first, int last, int result, function)
transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);

```

##### Buscar un rango de caracteres en el string
```cpp
nombre.find(cadena);
```

##### Buscar un caracter en el string desde una posición
```cpp
nombre.find(caracter, posicion);
```

##### Buscar un rango de caracteres en el string desde una posición
```cpp
nombre.find(cadena, posicion);
```

<!-- Exercici 1 -->
[Exercici 1](https://omegaup.com/arena/problem/ContandoOvejas/)
<!-- Exercici 2 -->
[Exercici 2](https://omegaup.com/arena/problem/Coincidencias-de-una-cadena-con-/#problems)

# VECTORES

### ¿Qué es un vector?

Un vector es una secuencia de elementos del mismo tipo que se almacenan en memoria de forma contigua. Los vectores son contenedores de la librería estándar de C++.

##### Declaración de un vector

```cpp
vector<tipo> nombre;
```

##### Inicialización de un vector

```cpp
vector<tipo> nombre = {elemento1, elemento2, elemento3, ...};
```

##### Añadir un elemento al final del vector

```cpp
nombre.push_back(elemento);
```

##### Eliminar el último elemento del vector

```cpp
nombre.pop_back();
```

##### Acceder a un elemento del vector

```cpp
nombre[posicion];
```

##### Tamaño del vector

```cpp
nombre.size();
```

##### Recorrer un vector

```cpp
// for normal
for (int i = 0; i < nombre.size(); i++) {
    cout << nombre[i] << endl;
}
// for each
for (auto elemento : nombre) {
    cout << elemento << endl;
}

// for each con iteradores
for (auto it = nombre.begin(); it != nombre.end(); it++) {
    cout << *it << endl;
}
```

##### Ordenar un vector

```cpp
sort(nombre.begin(), nombre.end());
```

##### Ordenar un vector en orden inverso

```cpp
// sort(int first, int last, function)
// first version sorts in ascending order
sort(nombre.begin(), nombre.end(), greater<int>());
// second version sorts in descending order
sort(nombre.rbegin(), nombre.rend());
```

##### Máximo elemento de un vector

```cpp
*max_element(nombre.begin(), nombre.end());
```

##### Mínimo elemento de un vector

```cpp
*min_element(nombre.begin(), nombre.end());
```

##### Suma de los elementos de un vector

```cpp
// accumulate(int first, int last, int sum)
accumulate(nombre.begin(), nombre.end(), 0);
```

##### Media de los elementos de un vector

```cpp
// accumulate(int first, int last, int sum)
accumulate(nombre.begin(), nombre.end(), 0) / nombre.size();
```

##### Buscar un elemento en el vector

```cpp
// find(int first, int last, int value)
vector<int> = {1, 2, 3, 4, 5};
find(nombre.begin(), nombre.end(), 3); // devuelve un iterador
```

##### Buscar un elemento en el vector y devolver su posición

```cpp
// find(int first, int last, int value)
vector<int> = {1, 2, 3, 4, 5};
find(nombre.begin(), nombre.end(), 3) - nombre.begin(); // devuelve un entero
```

##### Buscar un elemento en el vector y devolver si existe

```cpp
// find(int first, int last, int value)
vector<int> = {1, 2, 3, 4, 5};
find(nombre.begin(), nombre.end(), 3) != nombre.end(); // devuelve un booleano
```

##### Eliminar un elemento del vector

```cpp
// erase(int position)
nombre.erase(nombre.begin() + posicion);
```

##### Eliminar un rango de elementos del vector

```cpp
// erase(int first, int last)
nombre.erase(nombre.begin() + posicion, nombre.begin() + posicion + longitud);
```

##### Insertar un elemento en el vector

```cpp
// insert(int position, int value)
nombre.insert(nombre.begin() + posicion, elemento);
```

##### Insertar un rango de elementos en el vector

```cpp
// insert(int position, int first, int last)
nombre.insert(nombre.begin() + posicion, nombre2.begin(), nombre2.begin() + longitud);
```

##### Invertir el orden de los elementos del vector

```cpp
// reverse(int first, int last)
reverse(nombre.begin(), nombre.end());
```

##### Intercambiar el contenido de dos vectores

```cpp
// swap(vector& x, vector& y)
vector<int> nombre1 = {1, 2, 3, 4, 5};
vector<int> nombre2 = {6, 7, 8, 9, 10};
swap(nombre1, nombre2);
```

##### Comprobar si un vector está ordenado

```cpp
// is_sorted(int first, int last)
is_sorted(nombre.begin(), nombre.end());
```

# SETS

### ¿Qué es un set?

Un set es un contenedor que almacena elementos únicos ordenados de menor a mayor. Los sets son contenedores de la librería estándar de C++.

##### Declaración de un set

```cpp
set<tipo> nombre;
```

##### Inicialización de un set

```cpp
set<tipo> nombre = {elemento1, elemento2, elemento3, ...};
```

##### Añadir un elemento al set

```cpp
nombre.insert(elemento);
```

<!-- Exercise 1 -->
[Exercise 1](https://omegaup.com/arena/problem/Ordenar/#problems)

<!-- Exercise 2 -->
