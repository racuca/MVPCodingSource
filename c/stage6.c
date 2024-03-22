// 25083 새싹
/*#include <stdio.h>
int main() {
    printf("         ,r'\"7\n");
    printf("r`-_   ,'  ,/\n");
    printf(" \\. \". L_r'\n");
    printf("   `~\\/\n");
    printf("      |\n");
    printf("      |");
    return 0;
}*/

// 25083 킹, 퀸, 룩, 비숍, 나이트, 폰
/*#include <stdio.h>
int main() {
    int king = 1, queen = 1, rook = 2, bishop = 2;
    int knight = 2, fone = 8;
    int k, q, r, b, n, f = 0;
    scanf("%d %d %d %d %d %d", &k, &q, &r, &b, &n, &f);
    printf("%d %d %d %d %d %d", king - k, queen - q, rook - r, 
                                bishop - b, knight - n, fone-f);
    return 0;
}*/

// 25083 별 찍기 - 7
/*#include <stdio.h>
int main() {

    int N;
    scanf("%d", &N);

    // N = 5
    // ____*____
    // ___***___
    // __*****__
    // _*******_
    // *********
    // space 의 개수 : N - row => 0
    // * 의 개수 : row * 2 - 1
    for (int row = 1; row <= N; row++) {
        for (int s = 0; s < N - row; s++) {
            printf(" ");
        }
        for (int a = 0; a < row * 2 - 1; a++) {
            printf("*");
        }
        //for (int s = 0; s < N - row; s++) {
        //    printf(" ");
        //}
        printf("\n");
    }
    // _*******_
    // __*****__
    // ___***___
    // ____*____
    // space 의 개수 : row - N 
    // * 의 개수 : (2N-1)-2(row-N)
    for (int row = N + 1; row <= 2*N-1; row++) {
        for (int s = 0; s < row - N; s++) {
            printf(" ");
        }
        for (int a = 0; a < (2*N-1)-2*(row-N); a++) {
            printf("*");
        }
        //for (int s = 0; s < row - N; s++) {
        //    printf(" ");
        //}
        printf("\n");
    }

    return 0;
}*/

// 10988 팰린드롬 확인하기
/*#include <stdio.h>
#include <string.h>
int main() {
    
    char words[101] = "";
    int wordlen = 0;
    int startidx = 0;
    int palindrome = 1;

    scanf("%s", words);
    wordlen = strlen(words);

    while(startidx < wordlen) {
        if (words[startidx] == words[wordlen-1]) {
                startidx++;
                wordlen--;
        }
        else {
            palindrome = 0;
            break;
        }
    }

    printf("%d", palindrome);
}*/

// 1157 단어공부
/*#include <stdio.h>
#include <string.h>
int main() {
    char words[1000001] = "";
    int alpha[26] = {0};
    int len = 0;
    int maxalpha = 0, alphaidx = 0;
    int maxcount = 0;
    scanf("%s", words);
    len = strlen(words);
    
    for (int i = 0; i < len; i++) {
        int tempidx = 0;
        if (words[i] >= 'A' && words[i] <= 'Z') {
            alpha[words[i] - 'A']++;
            tempidx = words[i] - 'A';
        }
        else if (words[i] >= 'a' && words[i] <= 'z') {
            alpha[words[i] - 'a']++;
            tempidx = words[i] - 'a';
        }

        if (alpha[tempidx] > maxalpha)
        {
            maxalpha = alpha[tempidx];
            alphaidx = tempidx;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] == maxalpha) {
            maxcount++;
        }
    }

    if (maxcount == 1)
        printf("%c", 'A' + alphaidx);
    else
        printf("?");
}*/


// 2941 크로아티아 알파벳
/*#include <stdio.h>
#include <string.h>
int main() {
    char convertalpha[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    char words[101] = "";
    scanf("%s", words);
    int len = strlen(words);
    int widx = 0;
    int finalcharnum = 0;
    while (widx < len) {
        int same = 0;

        // 각 단어와 비교해서 같은지 체크
        for (int j = 0; j < 8; j++) {
            int ca = strlen(convertalpha[j]);
            int samecount = 0;
            for (int k = 0; k < ca && widx+k < len; k++) {
                if (words[widx+k] == convertalpha[j][k])
                    samecount++;
            }
            if (samecount == ca)
            {
                same = 1;
                widx += ca;

                // 단어수 증가
                finalcharnum++;
                break;
            }            
        }

        if (same == 0) {
            widx++;
            // 단어수 증가
            finalcharnum++;
        }
    }

    printf("%d", finalcharnum);
}*/

// 1316 그룹단어체커
/*#include <stdio.h>
#include <string.h>
int main() {
    int N = 0;    
    char word[101] = "";
    int groupwordcount = 0;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", word);
        int groupword = 1;
        int len = strlen(word);
        
        int alphacounts[26] = {0};  // a ~ z 0 ~ 25
        // groupword 체크
        char prev_char = 0;
        for (int j = 0; j < len; j++) {
            if (prev_char != word[j]) {
                if (alphacounts[word[j] - 'a'] > 0) {
                    groupword = 0;
                    break;
                }
            }
            alphacounts[word[j] - 'a']++;
            prev_char = word[j];            
        }

        // groupword 개수 증가
        if (groupword) {
            groupwordcount++;
        }
    }

    printf("%d", groupwordcount);
}*/


// 25206 너의 평점은
#include <stdio.h>
#include <string.h>
int main() {
    char gradelist[9][3] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
    float gradeconverted[9] = {4.5,  4.0,  3.5,  3.0, 2.5,   2.0, 1.5,  1.0,  0.0};
    char subject[51] = "";
    char point[4] = "";  // 학점
    char grade[3] = "";  // 등급
    float sumpoint = 0;
    float sumgradepoint = 0;
    for (int i = 0; i < 20; i++) {
        scanf("%s %s %s", subject, point, grade);
        float pointfloat = (float)atoi(point);
        for (int j = 0; j < 9; j++) {
            int same = 1;            
            int gradelen = strlen(gradelist[j]);
            for (int k = 0; k < gradelen; k++) {
                if (gradelist[j][k] != grade[k]) {
                    same = 0;
                    break;
                }
            }

            if (grade[0] == "P")
                continue;

            if (same == 1) {
                sumgradepoint += pointfloat * gradeconverted[j];
                sumpoint += pointfloat;
                break;
            }
        }
    }

    printf("%f", sumgradepoint / sumpoint);
}