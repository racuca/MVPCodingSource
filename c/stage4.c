//1. 10807 개수세기
/*#include <stdio.h>
#include <string.h>
int main() {
    int N;
    char enterkeypass;
    int valuelist[100] = {0};
    int v;
    int count = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &valuelist[i]);
    }
    scanf("%d", &v);

    for (int i = 0; i < N; i++) {
        if (valuelist[i] == v)
            count++;
    }

    printf("%d", count);
    return 0;
}
*/


//2. 10871 X보다 작은 수
/*#include <stdio.h>
#include <string.h>
int main() {
    int N = 0, X = 0;
    char v1[100 * 100] = "";
    int resultarray[10000] = {0};
    int i = 0;
    int resultcount = 0;

    int result = scanf("%99[^\n]%*c", v1);        
    char* pch = strtok(v1, " ");    
    for (i = 0; pch != NULL; i++) {
        int a = atoi(pch);
        pch = strtok (NULL, " ");
        if (i == 0)
            N = a;
        else
            X = a;
    }

    for (i = 0; i < N; i++) {
        int A = 0;
        scanf("%d", &A);
        if (X > A)
            resultarray[resultcount++] = A;
    }

    // 출력
    for (i = 0; i < 10000; i++)
    {
        if (resultarray[i] == 0)
            break;

        if (i < 10000 - 1) {
            if (resultarray[i] != 0 && resultarray[i+1] != 0)
                printf("%d ", resultarray[i]);
            else
                printf("%d", resultarray[i]);
        }
        else {
            if (resultarray[i] != 0)
                printf("%d", resultarray[i]);
        }
    }
    return 0;
}
*/


//3. 10818 최소, 최대
/*#include <stdio.h>
int main() {
    int N;
    int minmax[2] = {1000000, -1000000};
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);

        if (minmax[0] > a)
            minmax[0] = a;
        if (minmax[1] < a)
            minmax[1] = a;
    }

    printf("%d %d", minmax[0], minmax[1]);
    return 0;
}*/

//4. 2562 최대값
/*#include <stdio.h>
int main() {

    int values[9] = {0};
    int max = -1;
    int idx = -1;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &values[i]);
        if (max < values[i])
        {
            max = values[i];
            idx = i + 1;
        }
    }

    printf("%d\n", max);
    printf("%d", idx);
    return 0;
}*/

//5. 10810 공넣기
/*#include <stdio.h>
int main() {

    int N, M;
    int i, j, k;
    int bags[100] = {0};

    scanf("%d %d", &N, &M);
    for (int nn = 0; nn < M; nn++) {
        scanf("%d %d %d", &i, &j, &k);
        for (int bb = i; bb <= j; bb++) {
            bags[bb] = k;
        }
    }

    for (int r = 1; r <= N; r++) {
        printf("%d ", bags[r]);
    }

    return 0;
}*/

// 10813 공 바꾸기
/*#include <stdio.h>
int main() {

    int N, M;
    int i, j, k;
    int bags[100] = {0};

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        bags[i] = i;
    }

    for (int nn = 0; nn < M; nn++) {
        scanf("%d %d", &i, &j);
        // 교환
        int temp = bags[i];
        bags[i] = bags[j];
        bags[j] = temp;
    }

    for (int r = 1; r <= N; r++) {
        printf("%d ", bags[r]);
    }

    return 0;
}*/

// 5597 과제 안내신 분?
/*#include <stdio.h>
int main() {

    int success = 28;
    int numbers[31] = {0};
    for (int i = 0; i < 28; i++)
    {
        int a = 0;
        scanf("%d", &a);
        numbers[a] = a;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (numbers[i] == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}*/


// 3052 나머지
/*#include <stdio.h>
int main() {

    int values[10] = {0};
    int rest[42] = {-1};
    int diffcount = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &values[i]);
        values[i] = values[i] % 42;  // 0 ~ 41
        rest[values[i]] = 1;
    }
    // 서로 다른 값이 몇 개 있는지 확인
    for (int i = 0; i < 42; i++) {
        if (rest[i] == 1) {
            diffcount++;
        }
    }
    printf("%d", diffcount);
    return 0;
}*/


// 10811 바구니 뒤집기
/*#include <stdio.h>
int main() {

    int N, M;
    int i, j;
    int bags[101] = {0};

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        bags[i] = i;
    }

    // 역순 재배열
    for (int nn = 0; nn < M; nn++) {
        scanf("%d %d", &i, &j);
        // 역순 
        for (int ii = i, jj=j; ii < jj; ii++, jj--)
        {
            int temp = bags[ii];
            bags[ii] = bags[jj];
            bags[jj] = temp;
        }
    }

    for (i = 1; i <= N; i++) {
        printf("%d ", bags[i]);
    }

    return 0;
}*/


// 1546 평균 조작
#include <stdio.h>
int main() {
    int N;
    int points[1000] = {0};
    float fnewpoints[1000] = {0};
    int maxpoint = 0;
    float newsum = 0;

    scanf("%d", &N);
    // 최고점수 구하기
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i]);
        if (maxpoint < points[i]) {
            maxpoint = points[i];
        }
    }
    // 새로운 점수 구하기
    for (int i = 0; i < N; i++) {
        fnewpoints[i] = (float)points[i] / (float)maxpoint * (float)100;
        newsum += fnewpoints[i];
    }
    
    printf("%f", newsum / (float)N);

    return 0;
}

