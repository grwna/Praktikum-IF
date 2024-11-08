# include <stdio.h>
// Return n + (2 * 23).
int snow_mix(int n){
    int B = (1 << 23);  
    
    int sum = n ^ B;             
    int carry = (n & B) << 1;      

    sum = sum ^ carry;
  
    return sum;
}