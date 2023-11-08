#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void rearrangeArray(int arr[], int n) {
        int aux[n+1];
        for (int i = 0; i < n; i++)
        {
            aux[i] = arr[i];
        }
        sort(aux, aux+n);
        
        int max_idx = n - 1;
    	int min_idx = 0;
    	int max_elem = arr[n - 1] + 1;
    	
    	for(int i = 0; i < n; i++){
    	    if(i % 2 == 0){
    	        arr[i] += (arr[max_idx] % max_elem) * max_elem;
    	        max_idx--;
    	    }
    	    else{
    	        arr[i] += (arr[min_idx] % max_elem) * max_elem;
    	        min_idx++;
    	    }
    	}
    	
    	for(int i = 0; i < n; i++){
    	    arr[i] /= max_elem;
    	} 
};

int main(){
    int a[10] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int n = 10;
    Solution obj;
    obj.rearrangeArray(a, n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}