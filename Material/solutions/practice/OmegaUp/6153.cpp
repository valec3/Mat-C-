#include "ColaInteractivo.h"
#include <vector>
using namespace std;

vector<int> cola;
void agrega(int n) {
    cola.push_back(n);    
}

int saca() {
    if(cola.empty()) return -1; // Error (no hay elementos en la cola
    int n = cola[0];
    cola.erase(cola.begin());
    return n;
}