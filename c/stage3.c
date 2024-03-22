// 2739번 구구단
/*#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++)    
        printf("%d * %d = %d\n", N, i, N*i);
    return 0;
}*/


// 10950 A+B-3
/*#include <stdio.h>
int main() {
    int T;
    int A[100] = {0};
    int B[100] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }
    for (int i = 0; i < T; i++) {
        printf("%d\n", A[i] + B[i]);
    }

    return 0;
}*/

// 8393 합
/*#include <stdio.h>
int main() {
    int N;
    int sum = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    printf("%d", sum);

    return 0;
}*/

// 25304 영수증
/*#include <stdio.h>
int main() {
    int X, N = 0;
    int sum = 0;
    int a, b = 0;
    scanf("%d", &X);
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        sum += a * b;
    }
    if (X == sum) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}*/

// 25314 코딩은 체육과목입니다. 
/*#include <stdio.h>
int main() {
    int N = 0;
    scanf("%d", &N);

    int long_num = N / 4;
    for (int i = 0; i < long_num; i++) {
        printf("long ");
    }       
    printf("int");

    return 0;
}*/

// 15552 빠른 A+B
/*#include <stdio.h>
#define MAX_ARRAY 1000000
int main() {
    int T;
    int A = 0;
    int B = 0;

    short SUM1[MAX_ARRAY] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        SUM1[i] = A + B;
    }
    for (int i = 0; i < T; i++) {
        printf("%d\n", SUM1[i]);
    }
    return 0;
}*/

// 11021 A+B-7
/*#include <stdio.h>
#define MAX_ARRAY 1000000
int main() {
    int T;
    int A = 0;
    int B = 0;

    short SUM1[MAX_ARRAY] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        SUM1[i] = A + B;
    }
    for (int i = 0; i < T; i++) {
        printf("Case #%d: %d\n", i+1, SUM1[i]);
    }
    return 0;
}*/

// 11022 A+B-8
/*#include <stdio.h>
#define MAX_ARRAY 100000
int main() {
    int T;
    int A[MAX_ARRAY] = {0};
    int B[MAX_ARRAY] = {0};
    short SUM1[MAX_ARRAY] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A[i], &B[i]);
        SUM1[i] = A[i] + B[i];
    }
    for (int i = 0; i < T; i++) {
        printf("Case #%d: %d + %d = %d\n", i+1, A[i], B[i], SUM1[i]);
    }
    return 0;
}*/


// 2438 별 찍기 - 1
/*#include <stdio.h>
int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) { 
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}*/

// 2439 별 찍기 - 2
/*#include <stdio.h>
int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) { 
        for (int j = N; j >= i+1; j--) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}*/

// 10952 A+B-5
/*#include <stdio.h>
int main() {
    int A, B = 0;
    int SUM[1000] = {0};
    int cont = 1;
    int input_count = 0;
    while(cont) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0)
            cont = 0;
        else
            SUM[input_count++] = A + B;
    }

    for (int i = 0; i < input_count; i++)
        printf("%d\n", SUM[i]);

    return 0;
}*/


// 10951 A+B-4
#include <stdio.h>
#include <string.h>
int main() {
    char inputstr[10] = {0};
    int SUM[1000] = {0};
    int cont = 1;
    int input_count = 0;
    while(cont) {
        int result = scanf("%99[^\n]%*c", inputstr);
        printf("input %s", inputstr);
        if (result != 1)
            cont = 0;
        else {
            int NUMS[2];
            char* pch = strtok (inputstr," ");
            for (int i = 0; pch != NULL; i++) {
                NUMS[i] = atoi(pch);
                pch = strtok (NULL, " ");
            }
            SUM[input_count++] = NUMS[0] + NUMS[1];
        }
    }

    for (int i = 0; i < input_count; i++)
        printf("%d\n", SUM[i]);

    return 0;
}