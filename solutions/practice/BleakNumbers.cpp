// Given an integer, check whether it is Bleak or not.
// A number n is called Bleak if it cannot be represented as sum of a 
// positive number x and set bit count in x, i.e., x + countSetBits(x) 
// is not equal to n for any non-negative number x.

#include<bits/stdc++.h>
using namespace std;

unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int is_bleak(int n){
    int i=1,j=n-1;
    while(i<=j){
        if(i+countSetBits(i)==n || j+countSetBits(j)==n){
            return 0;
        }
        i++;
        j--;
    }    
    return 1;
}
int main(){
    int n;
    cin>>n;
    cout<<is_bleak(n);
    return 0;
}