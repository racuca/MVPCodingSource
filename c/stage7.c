// 2738 행렬덧셈
/*#include <stdio.h>

int main() {

    int N, M;
    int matrixA[100][100];
    int matrixB[100][100];
    int matrixC[100][100];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
*/


// 2566 최대값
/*#include <stdio.h>
int main() {
    int matrix[9][9];
    int max=0, row = 0, col= 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &matrix[i][j]);

            if (max < matrix[i][j]) {
                max = matrix[i][j];
                row = i;
                col = j;
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d", row+1, col+1);
    return 0;
}
*/

/*// 10798 세로읽기
#include <stdio.h>
#include <string.h>
int main() {

    char matrix[5][16] = {{0}};    
    char oneline[16] = "";

    for (int i = 0; i < 5; i++) {
        scanf("%s", oneline);
        int len = strlen(oneline);
        for (int j = 0; j < len; j++) {
            matrix[i][j] = oneline[j];
        }        
    }    

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[j][i] != 0) {
                printf("%c", matrix[j][i]);
            }
        }
    }
}*/

// 2563 색종이
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {

    int N;
    int x, y;
    int colorpapers[100][2] = {0};
    int totalarea = 0;
    scanf("%d", &N);
    
    // 계산
    // 1. 전체 총합 넓이 = N * 100 - 겹쳐진 부분 넓이
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        colorpapers[i][0] = x;
        colorpapers[i][1] = y;
    }
    totalarea = N * 100;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (abs(colorpapers[i][0] - colorpapers[j][0]) >= 10)
                continue;
            if (abs(colorpapers[i][1] - colorpapers[j][1]) >= 10)
                continue;

            int overlaparea = (10 - abs(colorpapers[i][0] - colorpapers[j][0])) * (10 - abs(colorpapers[i][1] - colorpapers[j][1]));
            totalarea = totalarea - overlaparea;
        }
    }
    if (totalarea < 100)
        totalarea = 100;
        
    printf("%d", totalarea);
    return 0;
}
*/

// 2. 전체 타일을 10x10 으로 하고 색종이가 점유하면 1로 설정 아니면 0으로 설정.
//    1의 숫자를 전부 더한다.
/*#include <stdio.h>
int main() {

    int N;
    int x, y;
    int matrix[100][100] = {0};
    int totalarea = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        for (int k = x; k < x+10; k++) {
            for (int m = y; m < y+10; m++) {
                matrix[k][m] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (matrix[i][j] == 1)
                totalarea += 1;
        }
    }
    printf("%d", totalarea);

    return 0;
}
*/