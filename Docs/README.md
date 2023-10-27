# Documentacion de metodos importantes C++
<a href="#arreglos">Arreglos</a>
<a href="#tips">tips</a>

<h2 id="arreglos">Arreglos</h2>

## Arreglos
### Crear un arreglo

```cpp
int a[3]; // a = {0, 0, 0}
```
### Crear un arreglo con un tamaño inicial

```cpp
int a[3] = {1, 2, 3}; // a = {1, 2, 3}
```
### Longitud de un arreglo

```cpp
int a[3] = {1, 2, 3};
int len = sizeof(a) / sizeof(a[0]); // len = 3
```
### Ordenar un arreglo

```cpp
int a[3] = {3, 2, 1};
sort(a, a + 3); // a = {1, 2, 3}
```
## Strings
-------

#### String to Int

```cpp
string s = "123";
int x = stoi(s);
```
#### Int to String

```cpp
int x = 123;
string s = to_string(x);
```
#### String to Char

```cpp
string s = "123";
char c = s[0];
```
#### Char to String

```cpp
char c = '1';
string s = string(1, c);
```

#### Longitud de un string

```cpp
string s = "123";
int len = s.length();
```
#### Comparar strings

```cpp
string s1 = "123";
string s2 = "123";
if(s1 == s2) cout << "Son iguales" << endl;
```

#### Comparar sin importar mayusculas o minusculas(strcmpi)

```cpp
string s1 = "123";
string s2 = "123";
if(strcmpi(s1.c_str(), s2.c_str()) == 0) cout << "Son iguales" << endl;
```

#### Substring

```cpp
string s = "123";
string sub = s.substr(1, 2); // sub = "23"
```

#### Encontrar un caracter en un string

```cpp
string s = "123";
int pos = s.find('2'); // pos = 1
// si no lo encuentra devuelve -1
```

#### Encontrar un string en un string

```cpp
string s = "123";
int pos = s.find("23"); // pos = 1
// si no lo encuentra devuelve -1
```
#### Reemplazar un caracter en un string

```cpp
string s = "123";
s[0] = '2'; // s = "223"
```
#### Reemplazar un string en un string

```cpp
string s = "123";
s.replace(0, 2, "23"); // s = "233"
```

#### Insertar un caracter en un string

```cpp
string s = "123";
s.insert(0, "2"); // s = "2123"
```

#### Insertar un string en un string

```cpp
string s = "123";
s.insert(0, "23"); // s = "23123"
```
#### Eliminar un caracter en un string

```cpp
string s = "123";
s.erase(0, 1); // s = "23"
```

#### Eliminar un string en un string

```cpp
string s = "123";
s.erase(0, 2); // s = "3"
```

#### Convertir un string a minusculas

```cpp
string s = "ABC";
transform(s.begin(), s.end(), s.begin(), ::tolower); // s = "abc"
```
#### Convertir un string a mayusculas

```cpp
string s = "abc";
transform(s.begin(), s.end(), s.begin(), ::toupper); // s = "ABC"
```
#### Convertir un string a un vector de caracteres

```cpp
string s = "123";
vector<char> v(s.begin(), s.end()); // v = {'1', '2', '3'}
```
#### Convertir un vector de caracteres a un string

```cpp
vector<char> v = {'1', '2', '3'};
string s(v.begin(), v.end()); // s = "123"
```

#### Invetir un string

```cpp
string s = "123";
reverse(s.begin(), s.end()); // s = "321"
```

#### Ordenar un string

```cpp
string s = "321";
sort(s.begin(), s.end()); // s = "123"
```
#### Ordenar un string de forma descendente

```cpp
string s = "123";
sort(s.begin(), s.end(), greater<char>()); // s = "321"
```
## Vectores
-------
#### Crear un vector

```cpp
vector<int> v; // v = {}
```
#### Crear un vector con un tamaño inicial

```cpp
vector<int> v(3); // v = {0, 0, 0}
```

#### Longitud de un vector

```cpp
vector<int> v = {1, 2, 3};
int len = v.size(); // len = 3
```

#### Ordenar un vector

```cpp
vector<int> v = {3, 2, 1};
sort(v.begin(), v.end()); // v = {1, 2, 3}
```

### Ordenar un vector de forma descendente

```cpp
vector<int> v = {1, 2, 3};
sort(v.begin(), v.end(), greater<int>()); // v = {3, 2, 1}
```
### Ordenar un vector de pares por el primer elemento

```cpp
vector<pair<int, int>> v = {{3, 1}, {2, 2}, {1, 3}};
sort(v.begin(), v.end()); // v = {{1, 3}, {2, 2}, {3, 1}}
```
### Ordenar un vector de pares por el segundo elemento

```cpp
vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 1}};
sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}); // v = {{3, 1}, {2, 2}, {1, 3}}
```
## Mapas
## Conjuntos
#### Crear un conjunto

```cpp
set<int> s; // s = {}
```
#### Crear un conjunto con un tamaño inicial

```cpp
set<int> s(3); // s = {0, 0, 0}
```
#### Longitud de un conjunto

```cpp
set<int> s = {1, 2, 3};
int len = s.size(); // len = 3
```
#### Insertar un elemento en un conjunto

```cpp
set<int> s = {1, 2, 3};
s.insert(4); // s = {1, 2, 3, 4}
```
## Arboles
-------
### Crear un arbol

```cpp
set<int> s; // s = {}
```
### Crear un arbol con un tamaño inicial

```cpp
set<int> s(3); // s = {0, 0, 0}
```
### Longitud de un arbol

```cpp
set<int> s = {1, 2, 3};
int len = s.size(); // len = 3
```
### Insertar un elemento en un arbol

```cpp
set<int> s = {1, 2, 3};
s.insert(4); // s = {1, 2, 3, 4}
```

## Colas
-------
### Crear una cola

```cpp
queue<int> q; // q = {}
```
### Crear una cola con un tamaño inicial

```cpp
queue<int> q(3); // q = {0, 0, 0}
```
### Longitud de una cola

```cpp
queue<int> q = {1, 2, 3};
int len = q.size(); // len = 3
```
### Insertar un elemento en una cola

```cpp
queue<int> q = {1, 2, 3};
q.push(4); // q = {1, 2, 3, 4}
```
### Eliminar un elemento en una cola

```cpp
queue<int> q = {1, 2, 3};
q.pop(); // q = {2, 3}
```
### Obtener el primer elemento de una cola

```cpp
queue<int> q = {1, 2, 3};
int x = q.front(); // x = 1
```
## Pares
-------
## Grafos
-------
<h2 id="tips">Algoritmos</h2>

#### Busqueda binaria

```cpp
int binarySearch(vector<int> v, int x) {
    int l = 0, r = v.size() - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(v[m] == x) return m;
        if(v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
```
#### Busqueda binaria recursiva

```cpp
int binarySearch(vector<int> v, int l, int r, int x) {
    if(l <= r) {
        int m = l + (r - l) / 2;
        if(v[m] == x) return m;
        if(v[m] < x) return binarySearch(v, m + 1, r, x);
        else return binarySearch(v, l, m - 1, x);
    }
    return -1;
}
```
#### Criba de Eratostenes

```cpp
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}
```
#### Factorial

```cpp
int factorial(int n) {
    int ans = 1;
    for(int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
```
#### Factorial recursivo

```cpp
int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n - 1);
}
```
#### Fibonacci
La sucesion de fibonacci es una sucesion de numeros donde cada numero es la suma de los dos numeros anteriores, los primeros dos numeros son 0 y 1, por lo que la sucesion empieza asi: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

```cpp
int fibonacci(int n) {
    int a = 0, b = 1;
    for(int i = 0; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return a;
}
```
#### Gauss
El metodo de gauss es un metodo para sumar los numeros del 1 al n, se puede calcular con la formula (n * (n + 1)) / 2
```cpp
int gauss(int n) {
    return (n * (n + 1)) / 2;
}
```
#### Maximo comun divisor

```cpp
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
```
o tambien
```cpp
```