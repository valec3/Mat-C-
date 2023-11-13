#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int maxReach = arr[0];
        int step = arr[0];
        int jump = 1;
        if (n == 1) //Cortar el caso en el que el arreglo es de un solo elemento
        {
            return 0;
        }
        else if (arr[0] == 0) //Cortar el caso en el que no se puede llegar al final
        {
            return -1;
        }
        else
        {
            for(int i = 1;i<n;i++){
                if (i == n-1)
                {
                    return jump;
                }
                // Maximo alcance que se puede tener desde el indice i
                maxReach = max(maxReach, i + arr[i]);
                step--;
                // Si se llega al final del alcance, se debe hacer un salto
                if (step == 0)
                {
                    jump++;
                    // Si el indice i es mayor o igual al maximo alcance, significa que no se puede llegar al final
                    if (i >= maxReach)
                    {
                        return -1;
                    }
                    // Se actualiza el alcance
                    step = maxReach - i;
                }
            }
        }
    }
    
    int minJumps2(int arr[], int n){
       int c=0;
       int f=0;
       int j=0;
       for(int i=0; i<n-1; i++){
           f=max(f,arr[i]+i);
           if(i==c){
               c=f;
               j++;
           }
       }
       if(c>=n-1){
           return j;
       }
       return -1;
    }
};