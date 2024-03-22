// 수학적 사고력

// 1. 2745.  진법변환
// B 진법, 수 N 
/*#include <stdio.h>
#include <math.h>
int main() {

    char N[100] = {0};
    int B;
    long long int sum = 0;
    int Nlen = 0;
    scanf("%s %d", N, &B);

    Nlen = strlen(N);
    // 1010 2
    // 0 * (2 ** 0)
    // 1 * (2 ** 1) = 2
    // 0 * (2 ** 2)
    // 1 * (2 ** 3) = 8 
    // 10

    for (int i = Nlen-1, j=0; i >= 0; i--, j++) {
        char n = N[i];
        char charn = 0;
        if ('0' <= n && n <='9') 
            charn = n - '0';
        else if ('A' <= n && n <= 'Z')
            charn = n - 'A' + 10;

        long long int digit10 = charn * pow(B, j);
        if (digit10 > 1000000000)
            digit10 = 1000000000;
        sum += digit10;
    }

    if (sum > 1000000000)
        sum = 1000000000;

    printf("%ld", sum);

    return 0;
}
*/

// 2. 11005.  진법변환 2
/* #include <stdio.h>
void rvereseArray(char arr[], int start, int end) 
{ 
    while (start < end) 
    { 
        char temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
}  

int main() {
    int N, B;

    int share, reminder = 0;
    char Btarget[100] = {0};
    int idx = 0;
    scanf("%d %d", &N, &B);

    // 10 -> B 
    // 10 -> 2진수
    // 10 / 2 % = 5, 0
    // 5 / 2 %  = 2, 1
    // 2 / 2 %  = 1, 0
    // 1 / 2 %  = 0, 1
    share = N; 
    
    while (share != 0) {
        int temp_share = share / B;
        reminder = share % B;
        char charn = 0;
        if (0 <= reminder && reminder <= 9) 
            charn = reminder + '0';
        else if (10 <= reminder && reminder <= 35)
            charn = reminder - 10 + 'A';

        Btarget[idx++] = charn;
        share = temp_share;
    }
    
    // Btarget Reverse
    rvereseArray(Btarget, 0, idx-1);

    printf("%s", Btarget);
}
*/

// 3. 2720.  세탁소 사장 동혁
/*#include <stdio.h>
int main() {
    int N = 0;
    int change = 0;
    
    scanf("%d", &N);
    

    for (int i = 0; i < N; i++) {
        scanf("%d", &change);

        int sharequater = change / 25;
        if (sharequater > 0) {
            change = change - sharequater * 25;
        }
        int sharedime = change / 10;
        if (sharedime > 0) {
            change = change - sharedime * 10;
        }
        int sharenickel = change / 5;
        if (sharenickel > 0) {
            change = change - sharenickel * 5;
        }
        int sharepenny = change / 1;
        if (sharepenny > 0) {
            change = change - sharepenny * 1;
        }
        printf("%d %d %d %d\n", sharequater, sharedime, sharenickel, sharepenny);
    }
    return 0;
}
*/

// 4. 2903. 중앙 이동 알고리즘
/*#include <stdio.h>
#include <math.h>
int main() {
    int N = 0;
    int maxpos = 0;
    int onelinepointnum = 2;

    scanf("%d", &N);
    maxpos = pow(2, N);
    
    for (int i = 1; i <= N; i++) {
        onelinepointnum += onelinepointnum - 1;
    }
    printf("%d", onelinepointnum * onelinepointnum);
    return 0;
}*/

// 5. 2292. 벌집
//     N  nsum  path    
// 1 ~ 1  (1)    : 1
// 2 ~ 7  (6*1)  : 2
// 8 ~ 19 (6*2)  : 3
// 20 ~ 37(6*3)  : 4
// 38 ~ 61(6*4)  : 5
/*#include <stdio.h>
int main() {

    int N = 0;
    scanf("%d", &N);

    int nsum = 1;
    int path = 1;
    while (nsum < N) {
        nsum += 6 * path;
        path += 1;
    }

    printf("%d", path);
    return 0;
}*/


// 6. 1193. 분수 찾기
// 1/1  1/2  1/3 ...
// 2/1  2/2  2/3 ...
// 분수  순서   colindx   rowidx
// 1/1  : 1       1        1

// 1/2  : 2       2        1
// 2/1  : 3       1        2

// 3/1  : 4       1        3
// 2/2  : 5       2        2
// 1/3  : 6       3        1

// 1/4  : 7       4        1
// 2/3  : 8       3        2
// 3/2  : 9       2        3
// 4/1  : 10      1        4

// 5/1  : 11      1        5
// 1/5  : 15      5        1

// 1/6  : 16      6        1
// 6/1  : 21      1        6
/*
#include <stdio.h>
int main() {
    int X = 0;
    int numerator = 0;  // 분자
    int denominator = 0; // 분모

    scanf("%d", &X);
    
    int idxmax = 1, idx = 1;
    while (idxmax < X) {
        idxmax = idxmax + idx + 1;
        idx = idx + 1;
    }
    if (idx % 2 == 0) {
        denominator= (idxmax - X) + 1;
        numerator = idx - (idxmax - X);
    }
    else {
        denominator= idx - (idxmax - X);
        numerator = (idxmax - X) + 1;
    }

    printf("%d/%d", numerator, denominator);
}
*/

// 7. 2869. 달팽이는 올라가고 싶다. 난이도 상
#include <stdio.h>
int main() {
    
    int A, B, V;

    scanf("%d %d %d", &A, &B, &V);

    int days = 1;
    int X = 0;
    if (V == A) {
        days = 1;
    }
    else{
        X = (V-A)/(A-B);
        if ((V-A)%(A-B) != 0) 
            days += 1;
    }

    days += X;

    printf("%d", days);
}