#include "functions.h"

int gcd(int a, int b){
    if (a == 0){
        return b;
    }   
    return gcd(b % a, a);
}

int calculateGCD(int arr[],int n){
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1){
           return 1;
        }
    }
    return result;
}

