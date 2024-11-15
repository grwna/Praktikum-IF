#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "stack.h"

void decodeString(char* str, char* result) {
    Stack s;
    CreateEmpty(&s);
    int i, j, k, copy, copyCnt = -1;
    char temp[10000], ch;
    int copies[10000];

    i = j = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            copy = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                copy = copy * 10 + (str[i] - '0');
                i++;
            }
            copyCnt++;
            copies[copyCnt] = copy;
        } 
        else if (str[i] == '[') {
            Push(&s, '[');
            i++;
        } 
        else if (str[i] == ']') {
            j = 0;
            
            while (InfoTop(s) != '[') {
                temp[j++] = InfoTop(s);
                Pop(&s, &ch);
            }
            temp[j] = '\0';
            Pop(&s, &ch);
            copy = copies[copyCnt];
            copyCnt--;

            for (k = 0; k < copy; k++) {
                for (j = strlen(temp) - 1; j >= 0; j--) {
                    Push(&s, temp[j]);
                }
            }
            i++;
        } 
        else {
            Push(&s, str[i]);
            i++;
        }
    }

    j = 0;
    while (!IsEmpty(s)) {
        result[j++] = InfoTop(s);
        Pop(&s, &ch);
    }
    result[j] = '\0';

    for (i = 0, j = strlen(result) - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

int main(){
    int N;
    char encoded[10001], decoded[10001];

    scanf("%d", &N);
    if (N == 0) {
        printf("\n");
        return 0;
    }
    scanf("%s", encoded);

    decodeString(encoded, decoded);
    printf("%s\n", decoded);

    return 0;
}
