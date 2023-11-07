#include<bits/stdc++.h>
using namespace std;

string reverseWithSpacesIntact (string s){
    int n = s.length();
    string ans = "";
    // Remove spaces from the end
    for(int i=n-1;i>=0;i--){
        if(s[i]!=' '){
            ans += s[i];
        }
    }
    int m = ans.length();
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            ans.insert(i," ");
        }
    }
    return ans;
}

int main(){
    string S = "Help others";
    cout<<reverseWithSpacesIntact(S)<<endl;
}