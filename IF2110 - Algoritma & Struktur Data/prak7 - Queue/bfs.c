#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;

int dRow[] = {0, 0, 1, -1};
int dCol[] = {1, -1, 0, 0};



boolean isValid(int N, int row, int col, char arr[MXN][MXN], int visited[MXN][MXN]){
     return (row >= 0 && row < N && col >= 0 && col < N && arr[row][col] != '#' && !visited[row][col]);
}
int main()
{   char arr[MXN][MXN];
    int visited[MXN][MXN];
    int distance[MXN][MXN];
    int N;
    scanf("%d", &N);
    ElType start, end;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'A'){
                start.row = i;
                start.col = j;
            }
            else if (arr[i][j] == 'B') {
                end.row = i;
                end.col = j;
            }
        }
    }

    // Initialize
    Queue q;
    CreateQueue(&q);
    enqueue(&q,  start);
    visited[start.row][start.col] = 1;
    distance[start.row][start.col] = 0;

    while(!isEmpty(q)){
        ElType current;
        dequeue(&q, &current);
        int currRow = current.row;
        int currCol = current.col;

        if(currRow == end.row && currCol == end.col){
            printf("Ya\n%d\n", distance[currRow][currCol]);
            return 0;
        }
        // 4 directions
        for(int i = 0; i < 4; i++){
            int newRow = currRow + dRow[i];
            int newCol = currCol + dCol[i];

            if(isValid(N, newRow, newCol, arr, visited)) {
                visited[newRow][newCol] = 1;
                distance[newRow][newCol] = distance[currRow][currCol] + 1;
                ElType newPoint;
                newPoint.row = newRow;
                newPoint.col = newCol;
                enqueue(&q, newPoint);
            }
        }
    }

    printf("Tidak\n");
    return 0;
}