//Problem 01 : Reverse the array

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string reverseArray(string str){
    int n = str.length();
    for (int i = 0; i < n/2; i++)
    {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    return str;
}

int main(){
    string s{};
    cin>>s;
    s = reverseArray(s);
    cout<<s<<endl;

    return 0;
}