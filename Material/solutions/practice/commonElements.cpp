#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            int i = 0, j = 0, k = 0;
            while(i < n1 && j < n2 && k < n3){
                // Si los tres son iguales
                if(A[i] == B[j] && B[j] == C[k]){
                    ans.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                // Si no son iguales, incrementamos el menor
                else if(A[i] < B[j]){
                    i++;
                }
                // Si no son iguales, incrementamos el menor
                else if(B[j] < C[k]){
                    j++;
                }
                // Si no incrementamos el otro
                else{
                    k++;
                }

                // Si hay repetidos, los saltamos
                while(i > 0 && i < n1 && A[i] == A[i - 1]){
                    i++;
                }
                while(j > 0 && j < n2 && B[j] == B[j - 1]){
                    j++;
                }
                while(k > 0 && k < n3 && C[k] == C[k - 1]){
                    k++;
                }
            }  
            return ans; 
        }

};