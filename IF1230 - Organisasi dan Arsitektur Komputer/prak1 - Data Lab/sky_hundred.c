# include <stdio.h>
int sky_hundred(int N){
    int is_negative = N >> 31;      // MSB is 1 if N is negative
    
    // Step 2: Calculate N % 4 (for non-negative N)
    int mod = N & 3;  // This gives N % 4
    // Step 3: Pre-calculate the XOR results based on N % 4:
    int res_0 = N;        // Case N % 4 == 0 -> result is N
    int res_1 = 1;        // Case N % 4 == 1 -> result is 1
    int res_2 = N + 1;    // Case N % 4 == 2 -> result is N + 1
    int res_3 = 0;        // Case N % 4 == 3 -> result is 0

    // Step 4: Create masks using bitwise operations for mod
    int mask_0 = ((!(mod ^ 0)) << 31) >>31;   // Mask all 1s if mod == 0
    int mask_1 = ((!(mod ^ 1))<< 31) >> 31;   // Mask all 1s if mod == 1
    int mask_2 = ((!(mod ^ 2)) << 31) >> 31;   // Mask all 1s if mod == 2
    int mask_3 = ((!(mod ^ 3)) << 31) >> 31 ;   // Mask all 1s if mod == 3

    // Step 5: Combine the results based on the masks
    int result = (res_0 & mask_0) | (res_1 & mask_1 ) | (res_2 & mask_2 ) | (res_3 & mask_3);
    printf("%d\n", result);
    // Step 6: Return 0 if N is negative, otherwise return the result
    return result & ~is_negative;  // Clears the result if N is negative
}