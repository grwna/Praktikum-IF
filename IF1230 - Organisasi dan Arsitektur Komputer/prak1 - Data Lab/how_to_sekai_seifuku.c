unsigned how_to_sekai_seifuku(unsigned h){
    unsigned sign = (h >> 15) & 0x1;
    unsigned exponent = (h >> 10) & 0x1F;
    unsigned mantissa = h & 0x3FF;
    unsigned exponent_shift;
    unsigned result;

    // Step 1: Handle special cases
    if (exponent == 0) {  // Subnormal or zero
        if (mantissa == 0) {
            // Zero: just shift the sign bit into the 32-bit float position
            return sign << 31;
        } else {
            // Subnormal: Convert to normalized single-precision float
            while ((mantissa & 0x400) == 0) { // Shift until the leading 1 is at bit 10
                mantissa = mantissa << 1;
                exponent_shift = exponent_shift - 1;
            }
            mantissa = mantissa & 0x3FF; // Mask out leading 1
            exponent = 1 + exponent_shift;
        }
    } 

    exponent = exponent + (127 - 15);
    result = (sign << 31) | (exponent << 23) | (mantissa >> 13);

    if (exponent == 0x1F) {  // Inf or NaN
        if (mantissa == 0) {
            // Infinity
            if (sign == 1) return 0xFF800000;
            else return 0x7F800000;
        } 
        // NaN
        return 0x7F800001;
    }
    
    return result;
}