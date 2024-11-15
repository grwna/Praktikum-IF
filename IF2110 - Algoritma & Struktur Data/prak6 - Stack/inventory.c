# include "stack.h"
# include <stdio.h>

int main(){
    int n, i;
    infotype popd1, popd2, trash;
    Stack st;
    char c;
    CreateEmpty(&st);
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf(" %c", &c);
        if(c == '+'){
            Pop(&st, &popd1);
            Pop(&st, &popd2);
            Push(&st, popd2);
            Push(&st, popd1);
            Push(&st, popd1  + popd2);
        }
        else if(c == 'X'){
            Pop(&st, &trash);
        }
        else if (c == 'S'){
            if(!IsEmpty(st)){
                int sum = 0;
                while(!IsEmpty(st)){
                    Pop(&st, &popd1);
                    sum += popd1;
            }
            Push(&st, sum);
            }
            
        }
        else if(c == 'A'){
            
            if(!IsEmpty(st)){
                int counter = 0;
                int sum = 0;
                while(!IsEmpty(st)){
                    Pop(&st, &popd1);
                    sum += popd1;
                    counter++;
            }
                sum /= counter;
                Push(&st, sum);
            } 
        }
        else {
            Push(&st, (c - '0'));
        }
    }
    int result = 0;
    while(!IsEmpty(st)){
        Pop(&st, &popd1);
        result += popd1;
    }

    printf("%d\n", result);
    return 0;
}