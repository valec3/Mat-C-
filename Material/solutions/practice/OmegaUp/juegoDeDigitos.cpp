#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
const ll MOD = 1e9 + 7;

int sumDigits(int n){
    ll sum{};
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    uintmax_t  n{};
    cin>>n;
    uintmax_t  sumTotal{};
    if(n<=9){
        sumTotal=n*(n+1)/2;
    }else{
        sumTotal=45;
        uintmax_t groupsExt=(n-9)/10;
        int resExt=(n-9)%10;
        cout<<"groupsExt:"<<groupsExt<<endl;
        cout<<"resExt:"<<resExt<<endl;
        sumTotal+=groupsExt*45;
        for(int i=0;i<resExt;i++){
            sumTotal+=i;
        }
    }
    cout<<"Sum:" <<sumTotal<<endl;
    while(sumTotal>9){
        sumTotal=sumDigits(sumTotal);
    cout<<"Sum:" <<sumTotal<<endl;
    }
    cout<<sumTotal<<endl;
}