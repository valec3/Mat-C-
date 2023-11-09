#include<bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    void sortABS2(int A[],int N, int k)
    {
        // vector <resta, valueOrigin, idxOrigin>
        vector <tuple<int, int, int>> v;
        for(int i = 0; i < N; i++){
            v.push_back(make_tuple(abs(A[i] - k), A[i], i));
        }
        // order for the first element of the tuple, after order for the third element of the tuple
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size()-1; i++)
        {
            if (get<0>(v[i]) != get<0>(v[i+1]))
            {
                continue;
            }

            if (get<2>(v[i]) > get<2>(v[i+1]))
            {
                swap(v[i], v[i+1]);
            }
        }
        
        for(int i = 0; i < N; i++){
            A[i] = get<1>(v[i]);
        }
    }
    void sortABS(int A[],int N, int k)
    {
        // vector <resta, valueOrigin, idxOrigin>
        vector <pair<int, int>> v;
        int aux[N];
        for(int i = 0; i < N; i++){
            v.push_back(make_pair(abs(A[i] - k), A[i]));
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < N; i++){
            aux[i] = v[i].second;
        }
        for(int i = 0; i < N; i++){
            A[i] = aux[i];
        }

         vector<pair<int,int>>v;
           for(int i=0;i<n;i++){
               v.push_back({abs(arr[i]-k),i});
           }
           sort(v.begin(),v.end());
           int temp[n];
           for(int i=0;i<n;i++){
               temp[i]=arr[v[i].second];
           }
           for(int i=0;i<n;i++){
               arr[i]=temp[i];
           }

    }
    void sortABS3(int A[],int N, int k)
    {
        stable_sort(A, A+N, [k](int a, int b){
            return abs(a-k) < abs(b-k);
        });
    }
};