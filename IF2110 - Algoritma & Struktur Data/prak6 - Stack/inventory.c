# include "stack.h"
# include <stdio.h>

int main(){
    int n, i, sum, counter;
    infotype popd1, popd2, trash;
    Stack st;
    char c;
    CreateEmpty(&st);
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf(" %c", &c);
        sum = 0;
        if((c - '0') >= 0 && (c - '0') <= 9){
            Push(&st, (c - '0'));
        }
        else if(c == '+'){
            Pop(&st, &popd1);
            Pop(&st, &popd2);
            sum = popd1  + popd2;
            Push(&st, popd2);
            Push(&st, popd1);
            Push(&st, sum);
        }
        else if(c == 'X'){
            Pop(&st, &trash);
        }
        else if (c == 'S'){
            while(!IsEmpty(st)){
                Pop(&st, &popd1);
                sum += popd1;
            }
            Push(&st, sum);
        }
        else if(c == 'A'){
            counter = 0;
            if(!IsEmpty(st)){
                while(!IsEmpty(st)){
                counter++;
                Pop(&st, &popd1);
                sum += popd1;
            }
                sum = sum/counter;
            } 
            Push(&st, sum);
        }
    }
    sum = 0;
    while(!IsEmpty(st)){
        Pop(&st, &popd1);
        sum += popd1;
    }

    printf("%d\n", sum);
    return 0;
}