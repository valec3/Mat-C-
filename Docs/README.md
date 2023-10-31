## ***Documentacion de metodos importantes C++***


<a href="#arreglos">Arreglos</a>
<a href="#strings">Strings</a>
<a href="#vectores">Vectores</a>
<a href="#conjuntos">Conjuntos</a>
<a href="#mapas">Mapas</a>
<a href="#arboles">Arboles</a>
<a href="#colas">Colas</a>
<a href="#pares">Pares</a>
<a href="#grafos">Grafos</a>
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
##### Crear un vector

```cpp
vector<int> v; // v = {}
```
##### Crear un vector con un tamaño inicial

```cpp
vector<int> v(3); // v = {0, 0, 0}
```

##### Longitud de un vector

```cpp
vector<int> v = {1, 2, 3};
int len = v.size(); // len = 3
```

#### Ordenar un vector

```cpp
vector<int> v = {3, 2, 1};
sort(v.begin(), v.end()); // v = {1, 2, 3}
```

#### Ordenar un vector de forma descendente

```cpp
vector<int> v = {1, 2, 3};
sort(v.begin(), v.end(), greater<int>()); // v = {3, 2, 1}
```
#### Ordenar un vector de pares por el primer elemento

```cpp
vector<pair<int, int>> v = {{3, 1}, {2, 2}, {1, 3}};
sort(v.begin(), v.end()); // v = {{1, 3}, {2, 2}, {3, 1}}
```
#### Ordenar un vector de pares por el segundo elemento

```cpp
vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 1}};
sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}); // v = {{3, 1}, {2, 2}, {1, 3}}
```

#### Eliminar un elemento en un vector

```cpp
vector<int> v = {1, 2, 3};
v.erase(v.begin() + 1); // v = {1, 3}

// Eliminar los ultimos 2 elementos
v.erase(v.end() - 2, v.end()); // v = {1}

// Eliminar todos los elementos
v.clear(); // v = {}

// Eliminar todos los elementos que cumplan una condicion
v.erase(remove_if(v.begin(), v.end(), [](int x) {
    return x == 1;
}), v.end()); // v = {2, 3}

// Eliminar todos los elementos que no cumplan una condicion
v.erase(remove_if(v.begin(), v.end(), [](int x) {
    return x != 1;
}), v.end()); // v = {1}

// Eliminar todos los elementos duplicados
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end()); // v = {1, 2, 3}

// Eliminar elemento en la posicion n
v.erase(v.begin() + n); // v = {1, 3}

// Eliminar el elemento 2
v.erase(find(v.begin(), v.end(), 2)); // v = {1, 3}

// Eliminar los elementos desde la posicion n hasta la posicion m
v.erase(v.begin() + n, v.begin() + m); // v = {1, 3}

```


## Conjuntos

#### Crear un conjunto

```cpp
set<int> s; // s = {}
// Con un tamaño inicial
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
#### Eliminar un elemento en un conjunto

```cpp
set<int> s = {1, 2, 3};
s.erase(2); // s = {1, 3}
```
#### Encontrar un elemento en un conjunto

```cpp
set<int> s = {1, 2, 3};
if(s.find(2) != s.end()) cout << "Encontrado" << endl;
```
#### Encontrar el primer elemento en un conjunto

```cpp
set<int> s = {1, 2, 3};
int x = *s.begin(); // x = 1
```
#### Encontrar el ultimo elemento en un conjunto

```cpp
set<int> s = {1, 2, 3};
int x = *s.rbegin(); // x = 3
```
#### Encontrar el elemento mas grande en un conjunto

```cpp
set<int> s = {1, 2, 3};
int x = *max_element(s.begin(), s.end()); // x = 3
```
#### Encontrar el elemento mas pequeño en un conjunto

```cpp
set<int> s = {1, 2, 3};
int x = *min_element(s.begin(), s.end()); // x = 1
```
#### Recorrer un conjunto

```cpp
set<int> s = {1, 2, 3};
// Forma 1
for(auto x : s) {
    cout << x << endl;
}
// Forma 2
for(auto it = s.begin(); it != s.end(); it++) {
    cout << *it << endl;
}
```
#### Recorrer un conjunto de forma inversa

```cpp
set<int> s = {1, 2, 3};
for(auto it = s.rbegin(); it != s.rend(); it++) {
    cout << *it << endl;
}
```

#### Convertir un conjunto a un vector

```cpp
set<int> s = {1, 2, 3};
vector<int> v(s.begin(), s.end()); // v = {1, 2, 3}
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

### Crear un par

```cpp
pair<int, int> p; // p = {0, 0}
```
<h2>Bits</h2>
<h4>Operadores</h4>

| Operador | Descripcion |
| --- | --- |
| & | AND |
| \| | OR |
| ^ | XOR |
| ~ | NOT |
| << | Desplazar a la izquierda |
| >> | Desplazar a la derecha |
| &= | AND y asignar |
| \|= | OR y asignar |
| ^= | XOR y asignar |
| <<= | Desplazar a la izquierda y asignar |
| >>= | Desplazar a la derecha y asignar |

<h4>Funciones</h4>

| Funcion | Descripcion |
| --- | --- |
| __builtin_popcount(x) | Cuenta los bits 1 |
| __builtin_popcountll(x) | Cuenta los bits 1 |
| __builtin_ctz(x) | Cuenta los bits 0 desde la derecha |
| __builtin_ctzll(x) | Cuenta los bits 0 desde la derecha |
| __builtin_clz(x) | Cuenta los bits 0 desde la izquierda |
| __builtin_clzll(x) | Cuenta los bits 0 desde la izquierda |
| __builtin_ffs(x) | Devuelve la posicion del primer bit 1 |
| __builtin_ffsll(x) | Devuelve la posicion del primer bit 1 |
| __builtin_parity(x) | Devuelve 1 si el numero de bits 1 es par, 0 si es impar |
| __builtin_parityll(x) | Devuelve 1 si el numero de bits 1 es par, 0 si es impar |
| __builtin_bswap32(x) | Intercambia los bytes de un entero de 32 bits |
| __builtin_bswap64(x) | Intercambia los bytes de un entero de 64 bits |

<h4>Operaciones</h4>

| Operacion | Descripcion |
| --- | --- |
| x & (x - 1) | Elimina el ultimo bit 1 |
| x & (-x) | Devuelve el ultimo bit 1 |
| x \| (1 << n) | Enciende el bit n |
| x & ~(1 << n) | Apaga el bit n |
| x ^ (1 << n) | Invierte el bit n |
| x & ((1 << n) - 1) | Elimina los bits desde la posicion n |
| x & ~((1 << n) - 1) | Elimina los bits desde la posicion 0 hasta la posicion n |
| x & ((1 << n) - 1) | Devuelve los bits desde la posicion 0 hasta la posicion n |
| x & ~((1 << (n + 1)) - 1) | Devuelve los bits desde la posicion n hasta la posicion 0 |
| x & (x - 1) | Devuelve el numero de bits 1 |
| x & -x | Devuelve el numero de bits 1 |
| x & (x + 1) | Devuelve el numero de bits 0 desde la derecha |
| x & ~(x + 1) | Devuelve el numero de bits 0 desde la derecha |
| x & (x - 1) | Devuelve el numero de bits 0 desde la izquierda |
| x & (x - 1) | Devuelve el numero de bits 0 desde la izquierda |
| x & (x - 1) | Devuelve la posicion del primer bit 1 |

<h4>Ejemplos</h4>

#### Encender un bit

```cpp
int x = 0;
x |= (1 << 2); // x = 4
```
#### Apagar un bit

```cpp
int x = 7;
x &= ~(1 << 2); // x = 3
```
#### Invertir un bit

```cpp
int x = 7;
x ^= (1 << 2); // x = 3
```

## Grafos
-------



<!------------------------------------------->
<!------------------------------------------->
<!------------------------------------------->
<!------------------------------------------->
<!------------------------------------------->
<!------------------------------------------->

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

#### Fibonacci Memoizacion
```cpp
int FibMemoizacion(int n, vector<int>&arr){//4
    if(arr[n] != 0) return arr[n];
    if(n < 2) return n;
    //arr[4] = 2 + 1 --> 3
    arr[n] = FibMemoizacion(n-1 , arr) + FibMemoizacion(n - 2, arr);//3
    //arr[4] = 3,arr[3] = 2 , arr[2] = 1
    return arr[n];
}
```
#### Fibonacci Dinamico
```cpp
int FibDinamico(int n){
    vector<int>dinamico(n+1 , 0);

    dinamico[0] = 0;
    dinamico[1] = 1;

    for(int i = 2; i < n; i++){
        dinamico[i] = dinamico[i-1] + dinamico[i-2];
    }

    return dinamico[n];
}
```
#### Quicksort
```cpp
void quicksort(int* arr, int izq, int der){
    int i = izq, j = der, temp;
    int p = arr[(izq + der)/2];//toma un numero del arreglo como valor :: exactamente el q esta en la posicion media del mismo

    while(i <= j){
        while(arr[i] < p) i++;
        while(arr[j] > p) j--;

        if(i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if(izq < j) quicksort(arr, izq, j);
    if(i < der) quicksort(arr, i, der);

}
```
#### Exponenciacion Rapida
```cpp
ll expMod(ll a, ll n, int m){
    if(n == 0) return 1;
    if(n == 1) return a % m;
    if(n % 2 == 0){
        ll resultado = exp(a, n/2);
        return ((resultado % m) * (resultado % m)) % m;
    }
    else{
        return ((exp(a, n-1) % m) * (a % m)) % m;
    }
}
```
#### Algoritmo de Euclides
```cpp
while(a % b != 0){
    a %= b;
    swap(a,b);
}

mcd = b;
mcm = (p*q)/mcd;
```
