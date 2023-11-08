#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getNum(int arr[] , int N) {
        sort(arr, arr + N);
        int min = arr[0];
        int max = arr[N - 1];
        int resp = min*max;
        
        
        if (max==min)
        {
            resp = max;
        }else if( max%min == 0){
            resp = lcd(max,min);
        }
        
        return resp;
    }
    int gcd(int a,int b){
        return __gcd(a,b)
    }
    int lcd(int a,int b){
        return a*b/gcd(a,b)
    }
};



int main(){
    cout<<mcd(8, 2)<<endl;
}