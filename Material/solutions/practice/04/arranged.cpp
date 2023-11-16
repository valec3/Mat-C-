#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> arranged(int a[],int n)
    {
        vector<int>v(n);
        for(int i=0,pindex=0,nindex=1;i<n;i++){
            if(a[i]>0){
                v[pindex] = a[i];
                pindex+=2;
            }
            else{
                v[nindex] =a[i];
                nindex+=2;
            }
        }
        return v;
    }
};