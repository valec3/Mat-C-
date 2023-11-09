#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void customSort(int arr[], int n) {
        int orderAsc[n], orderDesc[n];
        int asc = 0, desc = 0;
        asc = n/2;
        desc = n - asc;
        for(int i=0;i<asc;i++){
            orderAsc[i] = arr[i];
        }
        for(int i=0;i<desc;i++){
            orderDesc[i] = arr[i+asc];
        }
        sort(orderAsc, orderAsc+asc);
        sort(orderDesc, orderDesc+desc, greater<int>());
        for(int i=0;i<asc;i++){
            arr[i] = orderAsc[i];
        }
        for(int i=0;i<desc;i++){
            arr[i+asc] = orderDesc[i];
        }
    }
};