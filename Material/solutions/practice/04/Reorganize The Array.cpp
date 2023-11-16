#include<bits/stdc++.h>
using namespace std;

int * Rearrange(int *arr,int n){
    set<int> s;
    for(int i = 0;i<n;i++){
        s.insert(arr[i]);
    }
    for(int i = 0;i<n;i++){
        if(s.find(i)!=s.end()){
            arr[i] = i;
        }
        else{
            arr[i] = -1;
        }
    }
    return arr;
}