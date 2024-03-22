// 1. 27323 직사각형
/*#include <stdio.h>
int main() {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);

    printf("%d", A * B);
    return 0;
}*/

// 2. 1085 직사각형에서 탈출
/*#include <stdio.h>
int main() {
    int x, y, w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    // w, h = 10
    // x, y = 3  10-3 7
    int xpos = w - x;
    int ypos = h - y;

    if ((double)w/2 > x)
        xpos = x;
    else
        xpos = w - x;
    if ((double)h/2 > y)
        ypos = y;
    else
        ypos = h - y;

    int min = xpos;
    if (xpos > ypos)
        min = ypos;
    printf("%d\n", min);
}*/

// 3. 3009 네 번째 점
/*#include <stdio.h>
int main() {
    // (10, 20)  (30, 40)
    int xpos[2] = {0,};
    int xpos_dup[2] = {0,};
    int ypos[2] = {0,};
    int ypos_dup[2] = {0,};
    for (int i = 0; i < 3; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        for (int j = 0; j < 2; j++) {
            if (xpos[j] == 0 || xpos[j] == a) {
                xpos[j] = a;
                xpos_dup[j]++;
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            if (ypos[j] == 0 || ypos[j] == b) {
                ypos[j] = b;
                ypos_dup[j]++;
                break;
            }
        }        
    }
    int x_target = 0;
    int y_target = 0;
    for (int i = 0; i < 2; i++) {
        if (xpos_dup[i] == 1)
            x_target = i;
        if (ypos_dup[i] == 1)
            y_target = i;
    }

    printf("%d %d", xpos[x_target], ypos[y_target]);
    return 0;
}*/


// 4. 15894 수학은 체육과목입니다.
// 1 : 1 + 1   + 1 + 1   = 4
// 2 : 1 + 2.5 + 2 + 2.5 = 8
// 3 : 1 + 4   + 3 + 4   = 12
// 4 : 1 + 5.5 + 4 + 5.5 = 16
/*#include <stdio.h>
int main() {
    int N;
    unsigned long int A;

    scanf("%d", &N);

    A = (unsigned long int)N * 4; 
    printf("%lu", A);

    return 0;
}*/

// 5. 9063 대지
/*#include <stdio.h>
int main() {
    int N;
    int out_x1_min = 0, out_x2_max = 0;
    int out_y1_min = 0, out_y2_max = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (out_x1_min == 0)     out_x1_min = a;
        else if (out_x1_min > a) out_x1_min = a;
        if (out_x2_max == 0)     out_x2_max = a;
        else if (out_x2_max < a) out_x2_max = a;
        if (out_y1_min == 0)     out_y1_min = b;
        else if (out_y1_min > b) out_y1_min = b;
        if (out_y2_max == 0)     out_y2_max = b;
        else if (out_y2_max < b) out_y2_max = b;
    }

    printf("%d", (out_x2_max - out_x1_min) * (out_y2_max - out_y1_min));
    return 0;
}*/


// 6. 10101 삼각형 외우기
/*#include <stdio.h>
int main() {
    int N1, N2, N3, sum = 0;
    scanf("%d", &N1);
    scanf("%d", &N2);
    scanf("%d", &N3);

    int twoNsame = (N1 == N2) || (N1 == N3) || (N2 == N3) ? 1 : 0;
    if (N1 == N2 && N2 == N3) 
        twoNsame = 0;
    int notsame = (N1 != N2) && (N2 != N3) && (N1 != N3);
    
    if (N1 == 60 && N2 == 60 && N3 == 60)
        printf("Equilateral");
    else if (N1 + N2 + N3 == 180 && twoNsame)
        printf("Isosceles");
    else if (N1 + N2 + N3 == 180 && notsame)
        printf("Scalene");
    else if (N1 + N2 + N3 != 180)
        printf("Error");
    
    return 0;
}
*/

// 7. 5073 삼각형과 세 변
/*#include <stdio.h>
int main() {
    int N[3];
    int maxN;
    while(1) {
        scanf("%d %d %d", &N[0], &N[1], &N[2]);
        if (N[0] == 0 && N[1] == 0 && N[2] == 0)
            break;
        
        int maxid = 0;         
        maxN = N[0];        
        for (int i = 1; i < 3; i++) {
            if (N[i] > maxN) { maxN = N[i]; maxid = i; }
        }
        int otherid1 = (maxid + 1) % 3;
        int otherid2 = (maxid + 2) % 3;
        if (N[maxid] >= N[otherid1] + N[otherid2])
            printf("Invalid\n");            
        else if (N[0] == N[1] && N[1] == N[2])
            printf("Equilateral\n");
        else if (N[0] == N[1] || N[1] == N[2] || N[0] == N[2]) 
            printf("Isosceles\n");
        else //if (N[0] != N[1] && N[1] != N[2] && N[0] != N[2])
            printf("Scalene\n");
    }

    return 0;
}*/

// 8. 14215 세 막대
#include <stdio.h>
int main() {
    int N[3];
    
    scanf("%d %d %d", &N[0], &N[1], &N[2]);
    
    int maxid = 0, minid = 0;
    int maxN = N[0];
    int minN = N[0];
    for (int i = 1; i < 3; i++) {
        if (N[i] > maxN) { maxN = N[i]; maxid = i; }
        if (N[i] < minN) { minN = N[i]; minid = i; }
    }
    int otherid1 = (maxid + 1) % 3;
    int otherid2 = (maxid + 2) % 3;

    if (maxN >= N[otherid1] + N[otherid2])
        N[maxid] = N[otherid1] + N[otherid2] - 1;

    printf("%d", N[0] + N[1] + N[2]);
    return 0;
}
