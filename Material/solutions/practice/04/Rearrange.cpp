#include <bits/stdc++.h>
using namespace std;

vector<int> pos;
int count=0;

class Solution
{
    public:
        void Rearrange(int arr[],int n){
            vector<int> nonNegative;
            for(int i=0;i<n;i++){
                if(arr[i]<0){
                    arr[count]=arr[i];
                    count++;
                }
                else{
                    nonNegative.push_back(arr[i]);
                }
            }
            for(int i=0;i<nonNegative.size();i++){
                arr[count++]=nonNegative[i];
            }
        }
};

