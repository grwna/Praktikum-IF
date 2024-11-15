#include <stdio.h>
#include "boolean.h"
#include "stack.h"

const int MXN = 1e4 + 7;

int main()
{
    int N, i;
    scanf("%d", &N);
    int powers[N];
    int maxPower[N + 1];

    for (i = 0; i < N; i++) scanf("%d", &powers[i]);
    for (i = 0; i <= N; i++) maxPower[i] = 0;
    
    Stack s;
    CreateEmpty(&s);

    int left[N], right[N];
    for (i = 0; i < N; i++) {
        while (!IsEmpty(s) && powers[InfoTop(s)] >= powers[i]) {
            int temp;
            Pop(&s, &temp);
        }
        left[i] = IsEmpty(s) ? 0 : InfoTop(s) + 1;
        Push(&s, i);
    }

    CreateEmpty(&s);

    for (i = N - 1; i >= 0; i--) {
        while (!IsEmpty(s) && powers[InfoTop(s)] >= powers[i]) {
            int temp;
            Pop(&s, &temp);
        }
        right[i] = IsEmpty(s) ? N - 1 : InfoTop(s) - 1;
        Push(&s, i);
    }

    for (i = 0; i < N; i++) {
        int width = right[i] - left[i] + 1;
        maxPower[width] = powers[i] > maxPower[width] ? powers[i] : maxPower[width];
    }

    for (i = N - 1; i > 0; i--) {
        maxPower[i] = maxPower[i] > maxPower[i + 1] ? maxPower[i] : maxPower[i + 1];
    }

    for (i = 1; i < N; i++) {
        printf("%d ", maxPower[i]);
    }
    printf("%d\n", maxPower[N]);

    return 0;
} 