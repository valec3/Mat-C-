#include <bits/stdc++.h>
using namespace std;
int main() {
    int n{}, k{};
    cin>>n>>k;
    int a[n];
    int meanP = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        meanP += a[i];
    }
    meanP /= n;
    for(int i=0;i<n;i++){
        if(a[i] >= meanP){
            cout<<i<<" ";
        }
    }
    cout<<(meanP<=k?meanP-1:k);
}