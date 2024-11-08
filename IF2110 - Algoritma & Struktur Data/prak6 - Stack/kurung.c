#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main(){
    int N, i;
    char ch;
    Stack s;
    infotype popd;
    CreateEmpty(&s);
    boolean valid = true;
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        if (ch == '(' || ch == '{' || ch == '['){
            Push(&s, ch);
        }
        else {
            if (IsEmpty(s)) {
                valid = false;
                break;
            }
            
            Pop(&s, &popd);
            
            // Check for matching pairs
            if ((ch == ')' && popd != '(') ||
                (ch == '}' && popd != '{') ||
                (ch == ']' && popd != '[')) {
                valid = false;
                break;
            }
        }
    }
    if(!IsEmpty(s)) valid = false;
    if(valid) printf("Valid\n");
    else printf("Invalid\n");
    return 0;
}