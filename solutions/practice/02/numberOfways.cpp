#include<bits/stdc++.h>

using namespace std;
class Solution{
    public:
    long long int numberOfways(int a[], int n)
    {
        // Declaracion de variables
        int c=1,mx=0,ans=1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1]) 
                {   
                    c++;
                    ans+=c;
                }
                else
                {
                    ans++;
                    c=1;
                }
        }
        return ans;    
    }
};

int main(){
    int arr[] = {1, 5, 6, 7, 8, 9};
    
    Solution Obj;
    cout << Obj.numberOfways(arr, 6) << endl;
    return 0;
}