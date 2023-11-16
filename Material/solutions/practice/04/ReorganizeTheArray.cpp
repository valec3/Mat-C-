#include<bits/stdc++.h>
using namespace std;


int * Rearrange(int *arr,int n){
    // Complete the functionint i=0
    int i=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=-1 && arr[i]!=i){
            int x=arr[i];
            while(arr[x]!=-1 && arr[x]!=x){
                int y=arr[x];
                arr[x]=x;
                x=y;
            }
            arr[x]=x;
            if(arr[i]!=i){
                arr[i]=-1;
            }
        }
    }
    

    return arr;
}