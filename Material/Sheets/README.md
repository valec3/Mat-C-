<h1 style="text-align:center; font-weight:bold;color:#3af; border-bottom:4px solid #00d">Algoritmos</h1>

<ol style="list-style:none">
    <li><a href="#AthMat">Algoritmos Matematicos</a></li>
    <li><a href="#AthBus">Algoritmos de Busqueda</a></li>
    <li><a href="#AthOrd">Algorithmos de Ordenamiento</a></li>
    <li><a href="#AthGraf">Algoritmos de Grafos</a></li>
    <li><a href="#AthStr">Algoritmos de Strings</a></li>
    <li><a href="#AthGeo">Algoritmos Geometricos</a></li>
    <li><a href="#AthDin">Algoritmos de Programacion Dinamica</a></li>
    <li><a href="#AthGre">Algoritmos Greedy</a></li>
    <li><a href="#AthBit">Algoritmos Bitwise</a></li>
    <li><a href="#AthRan">Algoritmos Random</a></li>
    <li><a href="#AthOtr">Otros Algoritmos</a></li>
</ol>



<h2 id="AthMat" style="color:#596">Algoritmos Matematicos</h2>

#### Primos

- (Ver si un numero es primo)[#]
```c++
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
```

#### Gauss
```c++
int gauss(int n) {
    return (n * (n + 1)) / 2;
}
```

#### Fibonacci
```c++
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```
#### Fórmula de Binet
```c++
int fib(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}
```
#### Buscar el indice del numero n en la secuencia de fibonacci
```c++
int findIndex(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c = 1;
    int res = 1;
    while (c < n) {
        c = a + b;
        res++;
        a = b;
        b = c;
    }
    return res;
}
////////////////////
// second version
ll findIndex(ll n) {

    if(n==1) return 1;
    if(n==2) return 3;
    if(n==3) return 4;

    double phi = (1ll + sqrt(5ll)) / 2ll;
    ll index = round(log(n * sqrt(5ll) + 0.5) / log(phi));
    ll fib = round((pow(phi, index) - pow(1ll - phi, index)) / sqrt(5ll));
    if (fib == n)
        return index;
    else
        return -1; // n is not a Fibonacci number
}
// /////////////////////////
// third version
int findIndex(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(log(n * sqrt(5) + 0.5) / log(phi));
}

```



#### Maximo Comun Divisor
```c++
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
// second version
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
// third version (function implemented in C++ STL)
int gcd(int a, int b) {
    return __gcd(a, b);
}
```

#### Minimo Comun Multiplo
```c++

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
// second version (function implemented in C++ STL)
int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}
```

#### Kadane’s Algorithm (Maxima suma de subarreglo)
El algoritmo de Kadane es un algoritmo para la búsqueda del subarreglo de suma máxima en un arreglo unidimensional con números con signo. El algoritmo de Kadane es un algoritmo de programación dinámica que se resuelve en tiempo lineal.
```c++
int maxSubArraySum(int a[], int size) {
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
```
#### Sieve of Eratosthenes
El algoritmo de la criba de Eratóstenes es un método para encontrar todos los números primos hasta un límite dado. Fue creado por el matemático griego Eratóstenes (276-194 a. C.), que lo describió por primera vez en el año 240 a. C.
```c++
void sieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

```

#### Siguiente Permutacion
La siguiente permutación en orden lexicográfico de 1, 2, ..., n es la permutación de 1, 2, ..., n que aparece justo después de la permutación dada. Si la permutación dada es la última permutación, la siguiente permutación es la primera permutación.

```c++
void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
}
// second version
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

```
#### Permutaciones
El algoritmo de permutación de Johnson-Trotter es un algoritmo para generar todas las permutaciones de un conjunto dado.

```c++
void permute(vector<int>& nums, int l, int r) {
    if (l == r) {
        // process permutation
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permute(nums, l + 1, r);
            swap(nums[l], nums[i]);
        }
    }
}
```
#### Factorial
```c++
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Segunda version con MOD para evitar overflow
const int MOD = 1e9 + 7;
int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}
```


#### Combinaciones
Este algoritmo calcula el numero de combinaciones de n elementos tomados de k en k.
```c++
int binomialCoeff(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}
```



<h2 id="AthBus">Algoritmos de Busqueda</h2>

##### Busqueda Binaria
```c++
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
```

#### Busqueda Binaria en un arreglo rotado
```c++
int pivotedBinarySearch(int arr[], int n, int key) {
    int pivot = findPivot(arr, 0, n - 1);
 
    // If we didn't find a pivot, then
    // array is not rotated at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
 
    // If we found a pivot, then first
    // compare with pivot and then
    // search in two subarrays around pivot
    if (arr[pivot] == key)
        return pivot;
 
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
 
    return binarySearch(arr, pivot + 1, n - 1, key);
}
```

#### Busqueda de un pico

Este algoritmo busca un pico en un arreglo, un pico es un elemento que es mayor que sus vecinos, este algoritmo es una variacion de la busqueda binaria.

```c++
int findPeakUtil(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1), n);
    else
        return findPeakUtil(arr, (mid + 1), high, n);
}

int findPeak(int arr[], int n) {
    return findPeakUtil(arr, 0, n - 1, n);
}
```





<h2 id="AthOrd">Algorithmos de Ordenamiento</h2>

#### Bubble Sort
Complexity: O(n^2)
```c++
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
```
#### Insertion Sort
Complexity: O(n^2)
```c++
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

#### Quick Sort
Complexity: O(nlogn)
Peor caso: O(n^2)
```c++
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
```

#### Counting Sort

```c++
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
```
#### Merge sort
Complexity: O(nlogn)
```c++
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
```


## Revese Array
```c++
string reverseArray(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
    return s;
}
```

## TEMPLATE MOD
```c++
 ll gcd(ll a, ll b){if(b > a){return gcd(b, a);} if(b == 0){return a;} return gcd(b, a % b);}
  ll modpow(ll a,ll b){ll res = 1; while(b>0){if(b&1)res=(res*a)%MOD; a=(a*a)%MOD; b=b>>1;} return res;}        
  ll mod_add(ll a,ll b){return ((a%MOD) + (b%MOD))%MOD;}
  ll mod_sub(ll a,ll b){return ((a%MOD) - (b%MOD) + MOD)%MOD;}
  ll mod_mul(ll a,ll b){return ((a%MOD) * (b%MOD))%MOD;}
  ll mod_div(ll a,ll b){return ((a%MOD) * modpow(b,MOD-2))%MOD;}
```



