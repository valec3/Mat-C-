#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

typedef long long ll;

ll contarTriplets(vector<ll>& A, ll n, ll X) {
    ll count = 0;
    sort(A.begin(), A.end());
    
    for (auto it = A.begin(); it != A.end(); ++it) {
        auto low = next(it);
        auto high = prev(A.end());

        while (low < high) {
            if (*it + *low + *high == X) {
                count++;
                low++;
                high--;
            } else if (*it + *low + *high < X) {
                low++;
            } else {
                high--;
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    // vector<ll> lista(n);
    set<ll> listaSet;
    int elemento;
    for(int i = 0; i < n; i++) {
        cin >> elemento;
        if(elemento <= 5000) listaSet.insert(elemento);
    }
    // pass to vector
    vector<ll> lista(listaSet.begin(), listaSet.end());

    ll resultado = contarTriplets(lista, n, 5000ll);
    cout << resultado << endl;

    return 0;
}
