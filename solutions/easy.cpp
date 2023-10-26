#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    cin>>n;
    if (n%2==0)
    {
        cout<<n/2<<" "<<n/2;
    }else if(isPrime((n+1)/2) || isPrime((n-1)/2)){
        cout<<(n+1)/2+1<<" "<<(n-1)/2-1;
    }
    else{
        cout<<(n+1)/2<<" "<<(n-1)/2;
    }

    return 0;
}