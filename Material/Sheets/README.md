# Algoritmos tipicos

<a>Algorithmos de Busqueda</a>
<a href="#AthOrd">Algorithmos de Ordenamiento</a>


### Primos

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

### Gauss
```c++
int gauss(int n) {
    return (n * (n + 1)) / 2;
}
```

## Fibonacci
```c++
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```
## Maximo Comun Divisor
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

## Minimo Comun Multiplo
```c++

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
// second version (function implemented in C++ STL)
int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}
```

## Kadane’s Algorithm (Maxima suma de subarreglo)
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


## Busqueda Binaria

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

## Sieve of Eratosthenes
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



<h2 id="AthOrd">Algorithmos de Ordenamiento</h2>

### Quick Sort
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

### Counting Sort
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



