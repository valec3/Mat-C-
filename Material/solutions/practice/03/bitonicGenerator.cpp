#include<bits/stdc++.h>
using namespace std;

void bitonicGenerator(int arr[], int n){
    vector <int> evens; 
    vector <int> odds;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            evens.push_back(arr[i]);
        }else{
            odds.push_back(arr[i]);
        }
    }
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end(), greater<int>());
    int j = 0;
    for(int i = 0; i < evens.size(); i++){
        arr[j] = evens[i];
        j++;
    }
    for(int i = 0; i < odds.size(); i++){
        arr[j] = odds[i];
        j++;
    }
}