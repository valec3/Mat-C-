#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<string> findString(int n, int k) {
       string ans="";
       unordered_set<string>st;
       for(int i=0;i<n;i++)ans+='0';
       st.insert(ans);
       string temp;
       for(int i=k-1;i>=0;i--){
            // Obtenemos los ultimos n-1 caracteres de ans 
           temp=ans.substr(ans.size()-n+1,n-1);
           temp+=to_string(i);
           if(st.find(temp)==st.end()){
               ans+=to_string(i);
            // Reiniciamos el valor de i para que vuelva a iterar desde k-1
               i=k;
               st.insert(temp);
           }
       }
       return st;
    }
    
};

int main(){

    int k{2},n{2};
    Solution s;
    unordered_set<string>st=s.findString(n,k);
    for(auto i:st){
        cout<<i<<endl;
    }
    return 0;
}