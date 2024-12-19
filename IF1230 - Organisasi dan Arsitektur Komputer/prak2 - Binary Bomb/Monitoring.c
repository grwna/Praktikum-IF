#include <stdio.h>
void Monitoring(char* input){
    int var1, var2, var3, var4, var5, var6;
    sscanf(input, "%d %d %d %d %d %d", &var1, &var2, &var3, &var4, &var5, &var6);
    if (var1 == 3) {
        if (var2 == 5){
            if (var3 == 7){
                if (var4 == 11){
                    if (var5 == 13){
                        if (var6 == 14){
                            stage_complete();
                        }
                    }
                }
            }
        }
    }
    trap();
}