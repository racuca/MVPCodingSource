// 1330 문제
/*#include <stdio.h>
int main() {
    int A=0, B=0;
    scanf("%d %d", &A, &B);

    if (A > B) printf(">");
    if (A < B) printf("<");
    if (A == B) printf("==");
    return 0;
}*/

/*9498 문제 
# include <stdio.h>
int main() {
    int exam = 0;
    scanf("%d", &exam);
    if (exam >= 90 && exam <=100) printf("A");
    else if (exam >= 80 && exam <= 89) printf("B");
    else if (exam >= 70 && exam <= 79) printf("C");
    else if (exam >= 60 && exam <= 69) printf("D");
    else printf("F");
    return 0;
}*/

/*2753 윤년문제 
#include <stdio.h>
int main() {
    int year = 0;
    scanf("%d", &year);
    int result = 0;
    if (year % 4 == 0 && ((year % 100) != 0 || year % 400 == 0))
        result = 1;

    printf("%d", result);
    return 0;
}
*/

/*14681 사분면고르기 
#include <stdio.h>
int main() {
    int x, y = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    if (x > 0 && y > 0) printf("1");
    else if (x < 0 && y > 0) printf("2");
    else if (x < 0 && y < 0) printf("3");
    else if (x > 0 && y < 0) printf("4");
    return 0;
}*/

/*2884 알람 시계 
#include <stdio.h>
int main() {
    int H, M = 0;
    int result_H, result_M;
    scanf("%d", &H);
    scanf("%d", &M);

    result_M = ((M + 60) - 45) % 60;
    if (M < 45)
        result_H = (H - 1 + 24) % 24;
    else 
        result_H = H;

    printf("%d %d", result_H, result_M);
    return 0;
}*/

/* 2525 오븐시계 
#include <stdio.h>
int main() {
    int h, m, t = 0;
    int result_h, result_m = 0;
    scanf("%d %d", &h, &m);
    scanf("%d", &t);

    result_m = (m + t) % 60;
    if (m + t >= 60)https://order.pay.naver.com/home
        result_h = (h + ((m + t) / 60)) % 24;
    else
        result_h = h;
    printf("%d %d", result_h, result_m);
    return 0;
}*/


/* 2480 주사위 세개 */
#include <stdio.h>
int main() {
    int x, y, z = 0;
    scanf("%d %d %d", &x, &y, &z);
    if (x == y && y == z) printf("%d", 10000 + x * 1000);
    if (x == y && y != z) printf("%d", 1000 + x * 100);
    if (x != y && y == z) printf("%d", 1000 + y * 100);
    if (x == z && y != z) printf("%d", 1000 + z * 100);
    if (x != y && y != z && x != z) {
        int max = x;
        if (max < y) max = y;
        if (max < z) max = z;
        printf("%d", max * 100);
    }
    return 0;
}
