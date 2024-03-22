// 1. 5086. 배수와 약수
/*#include <stdio.h>
int main() {
    
    int A, B;
    
    while(1) {
        int fm = 0;
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0)
            break;

        if (B % A == 0) {
            printf("factor\n");
            fm = 1;
        }
        if (A % B == 0) {
            printf("multiple\n");
            fm = 1;
        }
        if (fm == 0) {
            printf("neither\n");
        }
    }
}*/

// 2. 2501. 약수 구하기
/*#include <stdio.h>
int main() {
    int N, K;

    scanf("%d %d", &N, &K);
    
    int pos = 0;
    int t = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            pos++;
            if (pos == K) {
                t = i;
                break;
            }
        }
    }
    printf("%d", t);
}*/


// 3. 9506. 약수들의 합
/*#include <stdio.h>
int main() {
    int N, K;
    while(1) {
        int divisor[10000] = {0};
        scanf("%d", &N);
        if (N == -1)
            break;       
        
        int sum = 0;
        int dividx = 0;
        for (int i = 1; i < N; i++) {
            if (N % i == 0) {
                sum += i;
                divisor[dividx++] = i;
            }
        }

        if (sum == N) {
            printf("%d = ", N);
            for (int i = 0; i < dividx; i++)
            {
                if (i == dividx - 1)
                    printf("%d", divisor[i]);
                else
                    printf("%d + ", divisor[i]);
            }
            printf("\n");
        }else {
            printf("%d is NOT perfect.\n", N);
        }
    }

    return 0;
}*/

// 4. 1978. 소수 찾기
/*#include <stdio.h>
int main() {
    int N, C, K;
    scanf("%d", &N);
    int num = N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        if (K < 2)
            num--;
        else {
            for (int j = 2; j < K; j++) {
                if (K % j == 0) {
                    num--;
                    break;
                }
            }
        }
    }

    printf("%d", num);
}*/

// 5. 2581. 소수
/*#include <stdio.h>
int main() {
    int M, N;
    int primenumbersum = 0;
    int primenumbermin = 0;
    scanf("%d", &M);
    scanf("%d", &N);
    primenumbermin = N;
    for (int i = M; i <= N; i++) {
        if (i == 1)
            continue;
        int primenumber = 1; 
        for (int j = 2; j < i; j++) {            
            if (i % j == 0) {
                primenumber = 0;
                break;
            }
        }
        if (primenumber) {
            if (i < primenumbermin)
                primenumbermin = i;
            primenumbersum += i;
        }
    }
    if (primenumbersum == 0)
        primenumbersum = -1;
    printf("%d\n", primenumbersum);
    if (primenumbersum != -1)
        printf("%d", primenumbermin);
}*/

// 6. 2581. 소인수분해
/*#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);

    while(N != 1) {
        for (int i = 2; i <= N; i++) {
            if (N % i == 0) {
                N = N / i;
                printf("%d\n", i);
                break;
            }
        }
    }
}*/