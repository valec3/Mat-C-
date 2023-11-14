#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void Rearrange(int arr[],int n){
            int contPos = 0;
            int contNeg[n+1];
            for (int i = 0; i < n; i++)
            {
                if(arr[i]>0){
                    contPos++;
                }
                else{
                    contNeg[i] = arr[i];
                }
            }
            
        }
        bool areRotations(string s1,string s2)
        {
            if(s1.length()!=s2.length()){
                return false;
            }
            string temp = s1+s1;
            return (temp.find(s2)!=string::npos);
        }
};