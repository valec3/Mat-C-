#include<bits/stdc++.h>

using namespace std;

int contarTriplets(vector<int>& lista, int n) {
    int count = 0;
    sort(lista.begin(), lista.end());

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int suma = lista[i] + lista[j] + lista[k];

            if (suma == 5000) {
                count++;
                j++;
                k--;
            }
            else if (suma < 5000) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> lista(n);
    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }
    int resultado = contarTriplets(lista, n);
    cout << resultado << endl;

    return 0;
}
