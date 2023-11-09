//Problem 01 : Reverse the array

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int isReversible(string str, int n) { 
    for (int i = 0; i < n; i++){
        if(str[i] != str[n - i - 1])
            return 0;
    }
    return 1;
} 

vector<string> subString(char str[], int n) 
{
    vector<string> v;
    // Pick starting point
    for (int len = 1; len <= n; len++) 
    {    
        // Pick ending point
        for (int i = 0; i <= n - len; i++) 
        {
            //  Print characters from current
            // starting point to current ending
            // point.  
            int j = i + len - 1;            
            for (int k = i; k <= j; k++) 
                v.push_back(str[k]);
        }
    }
}
int main(){
    int n = 2;
    string str = "ab";
    cout<<isReversible(str, n)<<endl;
    return 0;
}