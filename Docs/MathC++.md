# Matematica en C++

<h2>Contenido</h2>




<h2>Aritmetica</h2>

<h3>Aritmetica Modular</h3>

<p>La aritmetica modular es una forma de aritmetica en la que los numeros "se repiten" cada cierto numero. Por ejemplo, en aritmetica modular 12, 5+7=2, ya que 12-5=7 y 12-7=5. En C++, la funcion mod() devuelve el residuo de la division entre dos numeros, y se puede usar para calcular la aritmetica modular.</p>

```cpp
int mod(int a, int b) {
    return ((a%b)+b)%b;
}
```
<h3>Exponenciacion Modular</h3>

<p>La exponenciacion modular es una forma de calcular potencias de numeros muy grandes. La idea es que, si se tiene que calcular a<sup>b</sup> mod m, se puede calcular a<sup>b</sup> y luego calcular el residuo de la division entre a<sup>b</sup> y m. Sin embargo, calcular a<sup>b</sup> puede ser muy lento, por lo que se puede usar la siguiente propiedad:</p>

<p>a<sup>b</sup> mod m = (a mod m)<sup>b</sup> mod m</p>

<p>Esto se puede demostrar facilmente usando la definicion de modulo. Por lo tanto, se puede calcular (a mod m)<sup>b</sup> mod m, que es mucho mas rapido.</p>

```cpp
int modpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
```

<p>Esta funcion calcula a<sup>b</sup> mod m en O(log(b)).</p>








<h2>Teoria de Numeros</h2>

<h3>Algoritmo de Euclides</h3>

<p>El algoritmo de Euclides es un algoritmo que calcula el maximo comun divisor de dos numeros. El maximo comun divisor de dos numeros es el numero mas grande que divide a ambos numeros. Por ejemplo, el maximo comun divisor de 12 y 18 es 6, ya que 6 divide a 12 y 18, y no hay ningun numero mas grande que divida a ambos.</p>

<p>El algoritmo de Euclides se basa en la siguiente propiedad: si a > b, entonces el maximo comun divisor de a y b es el mismo que el maximo comun divisor de b y a-b. Esto se puede demostrar facilmente, ya que si un numero x divide a a y b, entonces x tambien divide a a-b, y viceversa.</p>

```cpp
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
```

<p>Este algoritmo calcula el maximo comun divisor de dos numeros en O(log(max(a, b))).</p>

<h3>Algoritmo de Euclides Extendido</h3>

<p>El algoritmo de Euclides extendido es una extension del algoritmo de Euclides que, en vez de calcular el maximo comun divisor de dos numeros, calcula los coeficientes de Bezout de dos numeros. Los coeficientes de Bezout de dos numeros a y b son dos numeros x e y tales que ax+by=gcd(a, b). Por ejemplo, los coeficientes de Bezout de 12 y 18 son -1 y 1, ya que -1*12+1*18=6=gcd(12, 18).</p>

<p>El algoritmo de Euclides extendido se basa en la siguiente propiedad: si a > b, entonces los coeficientes de Bezout de a y b son los mismos que los coeficientes de Bezout de b y a-b. Esto se puede demostrar facilmente, ya que si ax+by=gcd(a, b), entonces (a-b)x+by=gcd(a, b), y viceversa.</p>

```cpp
int x, y, gcd;
void extendedEuclid(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
```

<p>Este algoritmo calcula los coeficientes de Bezout de dos numeros en O(log(max(a, b))).</p>








<h2>Algebra</h2>

<h3>Algoritmo de Gauss-Jordan</h3>

<p>El algoritmo de Gauss-Jordan es un algoritmo que, dado un sistema de ecuaciones lineales, encuentra una solucion para el sistema. Un sistema de ecuaciones lineales es un conjunto de ecuaciones de la forma a<sub>1</sub>x<sub>1</sub>+a<sub>2</sub>x<sub>2</sub>+...+a<sub>n</sub>x<sub>n</sub>=b, donde a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> y b son numeros. Por ejemplo, el siguiente es un sistema de ecuaciones lineales:</p>

<p>2x+3y=5</p>
<p>4x+5y=6</p>

```cpp
const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
```
<p>Funcion incluida en la STL de C++.</p>

```cpp
int main() {
    vector < vector<double> > a (2, vector<double> (3)); // 2 ecuaciones, 3 variables
    a[0][0] = 2; a[0][1] = 3; a[0][2] = 5;
    a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;

    vector<double> ans;
    int res = gauss (a, ans);
    if (res == 0)
        puts ("No solution");
    if (res == 1) {
        puts ("Single solution:");
        for (size_t i=0; i<ans.size(); ++i)
            printf ("%f ", ans[i]);
        puts ("");
    }
    if (res == INF)
        puts ("Infinity of solutions");
}
```

<p>Este algoritmo encuentra una solucion para un sistema de ecuaciones lineales en O(n<sup>3</sup>), donde n es el numero de ecuaciones.</p>



<h2>Combinatoria y Permutacion</h2>

<h3>Factorial</h3>

<p>El factorial de un numero n, denotado n!, es el producto de todos los numeros desde 1 hasta n. Por ejemplo, 5!=1*2*3*4*5=120. El factorial se puede calcular facilmente usando un ciclo for.</p>

```cpp
int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}
```

<p>Este algoritmo calcula n! en O(n).</p>

<h3>Combinatoria</h3>

<p>La combinatoria es una rama de las matematicas que estudia los numeros combinatorios. Los numeros combinatorios son numeros que representan la cantidad de formas de escoger k elementos de un conjunto de n elementos. Por ejemplo, el numero combinatorio C(5, 2) es la cantidad de formas de escoger 2 elementos de un conjunto de 5 elementos. Esto se puede calcular facilmente usando la siguiente formula:</p>

<p>C(n, k) = n! / (k! * (n-k)!)</p>

<p>Por ejemplo, C(5, 2) = 5! / (2! * 3!) = 120 / (2 * 6) = 10.</p>

```cpp
int comb(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}
```

<p>Este algoritmo calcula C(n, k) en O(n).</p>

<h3>Permutacion</h3>

<p>La permutacion es una rama de las matematicas que estudia los numeros de permutacion. Los numeros de permutacion son numeros que representan la cantidad de formas de escoger k elementos de un conjunto de n elementos, donde el orden importa. Por ejemplo, el numero de permutacion P(5, 2) es la cantidad de formas de escoger 2 elementos de un conjunto de 5 elementos, donde el orden importa. Esto se puede calcular facilmente usando la siguiente formula:</p>

<p>P(n, k) = n! / (n-k)!</p>

<p>Por ejemplo, P(5, 2) = 5! / 3! = 120 / 6 = 20.</p>

```cpp
int perm(int n, int k) {
    return fact(n) / fact(n - k);
}
```

<p>Este algoritmo calcula P(n, k) en O(n).</p>



<h2>Geometria</h2>