#include "mesinkata.h"
# include <stdio.h>


int main(){
    int term = 1;
    int digit = 0;
    boolean isLead;
    boolean is4lay = true;
    START();
    while(!EOP){
        if(isLead) term++;
        if(currentChar == '@' || currentChar == ' ') {
            isLead = true;
            digit = 0;
        }

        if(!((currentChar >= 48 && currentChar <= 57) || currentChar == '@' || currentChar == ' ' )) is4lay = false;

        if(currentChar >= 48 && currentChar <= 57){
            digit *= 10;
            digit += currentChar - '0';
        }
        if(isLead && digit == 0) is4lay = false;
        if(currentChar != '@') isLead = false;

        if (digit > 255) is4lay = false;


        if(is4lay) printf("true :-> %d\n",term);
        else printf("false :-> %d\n", term);
        ADV();
        
        if((currentChar == ' ' || currentChar == MARK) && term == 4){
            term = 1;
            if(is4lay) printf("4Lay\n");
            else printf("ewh\n");
            is4lay = true;
        } else if((currentChar == ' ' || currentChar == MARK) && term != 4){
             term = 1;
             printf("ewh\n");
             is4lay = true;
        }
    }
    return 0;
}