#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // iniciar i en n-2 porque i+1 debe existir
        int i = n-2;
        // Iterar hasta que nums[i] < nums[i+1]
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        // Si i es negativo, significa que el arreglo esta ordenado de forma descendente
        if(i>=0){
            // Buscar el primer elemento que sea mayor a nums[i]
            int j = n-1;
            // Iterar hasta que nums[j] > nums[i]
            while(j>=0 && nums[j]<=nums[i]) j--;
            // Intercambiar nums[i] y nums[j]
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());        
    }
};