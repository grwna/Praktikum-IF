int kitsch(int x){
    int big = x & (~63);
    int small = x & 63;
    int isNeg = (x >> 31);

    int smallMul = (small << 4) + small;
    int bigDiv = (big >> 6);

    int negSmallMul = ~small + 1;
    int isneg64multiple = ((smallMul | negSmallMul) >> 31) & 1; 
    int rounding = isNeg & isneg64multiple;

    int resSmall =  (smallMul >> 6) + rounding;
    int resBig = (bigDiv << 4) + bigDiv;
    return resBig + resSmall;
}