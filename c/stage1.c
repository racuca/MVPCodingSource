
// 1008 번 문제 정답  - C99
/*#include <stdio.h>
int main() {
    int a=0, b=0;
    double a1, b1, val=0;
    scanf("%d %d", &a, &b);
    a1 = a;
    b1 = b;
    val = a1/b1;
    printf("%.10f", val);
    return 0;
}*/

// 10869번 문제
/*#include <stdio.h>
int main() {
    int a=0, b=0;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    printf("%d\n", a / b);
    printf("%d", a % b);
    return 0;
}*/

// 10926번 문제
/*#include <stdio.h>
#include <string.h>
int main() {
    char idname[50] = {0};
    scanf("%s", &idname);
    strcat(idname, "??!");
    printf("%s", idname);
    return 0;
}*/

// 18108 번 문제 불기->서기년도 문제
/*#include <stdio.h>
int main() {
    int buda_year = 0;
    scanf("%d", &buda_year);    
    printf("%d", buda_year - 543);
    return 0;
}*/

// 10430 번 문제
/*#include <stdio.h>
int main(){
    int A=0, B=0, C=0;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", (A+B)%C);
    printf("%d\n", ((A%C) + (B%C))%C);
    printf("%d\n", (A*B)%C);
    printf("%d", ((A%C) * (B%C))%C);
    return 0;
}
*/

// 2588번 문제 두수의 곱 계산 과정
/*#include <stdio.h>
int main(){
    char A[4] = {0};
    char B[4] = {0};
    scanf("%s", A);
    scanf("%s", B);

    int int_a = atoi(A);
    char first_b = B[2] - '0';
    char sec_b = B[1] - '0';
    char third_b = B[0] - '0';

    int a3 = int_a * first_b;
    int a4 = int_a * sec_b;
    int a5 = int_a * third_b;
    int a6 = a3 + a4 * 10 + a5 * 100;

    printf("%d\n", a3);
    printf("%d\n", a4);
    printf("%d\n", a5);
    printf("%d", a6);

    return 0;
}
*/

// 11382번 세 수 더하기 + 값의 입력범위 
/*#include <stdio.h>
int main() {
    long int a=0, b=0, c=0;
    scanf("%ld %ld %ld", &a, &b, &c);
    printf("%ld", a + b + c);
    return 0;
}
*/

/* 10171 고양이
#include <stdio.h>
int main()
{
    printf("\\    /\\\n");
    printf(" )  ( ')\n");
    printf("(  /  )\n");
    printf(" \\(__)|");
    return 0;
}
*/


/* // 10172 개 
#include <stdio.h>
int main()
{
    printf("|\\_/|\n");
    printf("|q p|   /}\n");
    printf("( 0 )\"\"\"\\\n");
    printf("|\"^\"`    |\n");
    printf("||_/=\\\\__|");
    return 0;
}
*/
