#include <bits/stdc++.h>
using namespace std;

int getDivisors(int a){
    int divisors{};
    for (int i = 1; i <= sqrt(a); i++)
    {
        if(a%i==0){
            if (a/i == i) 
                divisors++;
            else 
                divisors += 2;
        }
    }
    return divisors;
}

int main() {
    int n{};
    int ans{};
    cin >> n;
    int persons[n+1];
    int countJ{};
    for (int i = 0; i < n; i++)
    {
        cin>>persons[i];
        if(persons[i] == 1){
            countJ++;
        }
    }

    // verify if index
    for(int i=0;i<n;i++){
        if (getDivisors(i) == 3 && persons[i] == 1)
        {
            ans++;
        }
        
    }

    if (getDivisors(countJ) == 3)
    {
        ans++;
    }
    
    cout<<ans;
}

