// You are given a string S, the task is to reverse the string using stack.
#include<bits/stdc++.h>
using namespace std;
void Reverse(stack<int> &St){
    // Your code here
    stack<int> aux;
    while(!St.empty()){
        aux.push(St.top());
        St.pop();
    }
    St = aux;
}