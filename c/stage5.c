// 27866 문자와 문자열
/*#include <stdio.h>
int main() {

    char word[1001] = "";
    int i;

    scanf("%s", word);
    scanf("%d", &i);
    printf("%c", word[i-1]);

    return 0;
}*/

// 2743 단어 길이 재기
/*#include <stdio.h>
int main() {
    
    char word[101] = {0};
    scanf("%s", word);
    printf("%d", strlen(word));

    return 0;
}*/

// 9086 문자열
/*#include <stdio.h>
int main() {
    int T;
    char word[1000] = {0};
    char result[10 * 10] = {0};

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", word);
        result[i*3] = word[0];
        result[i*3+1] = word[strlen(word)-1];
    }

    for (int i = 0; i < T; i++) {
        printf("%c%c\n", result[i*3], result[i*3+1]);
    }

    return 0;
}*/

// 11654 아스키코드
/*#include <stdio.h>
int main() {

    char ch;
    scanf("%c", &ch);
    printf("%d", ch);
    return 0;
}*/

// 11720 숫자의 합
/*#include <stdio.h>
int main() {
    int N;
    int sum = 0;
    char number[101] = "";

    scanf("%d", &N);
    scanf("%s", number);
    for (int i = 0; i < N; i++) {
        sum += number[i] - 48;
    }
    printf("%d", sum);
    return 0;
}*/

// 10809 알파벳찾기
/*#include <stdio.h>
int main() {
    
    char word[101] = "";
    int indexlist[27] = {0};
    for (int i = 0; i < 27; i++) {
        indexlist[i] = -1;
    }

    scanf("%s", word);
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == c) {
                indexlist[c - 'a'] = i;
                break;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        printf("%d ", indexlist[c - 'a']);
    }
    return 0;
}*/


// 2675 문자열반복
/*#include <stdio.h>
#include <string.h>
int main() {
    int T;
    int R;
    char word[21] = "";
    char newword[21 * 10] = "";

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %s", &R, word);
        int wordlen = strlen(word);
        int newwordidx = 0;
        for (int k = 0; k < wordlen; k++) {
            for (int j=0; j < R; j++) {
                newword[newwordidx++] = word[k];
            }
        }
        newword[newwordidx] = '\0';
        printf("%s\n", newword);
    }
    
    return 0;
}*/


// 1152 단어의 개수
/*#include <stdio.h>
#include <string.h>
char word[1000001] = "";
int main() {
    int wordlen = 0;
    int wordcount = 0;
    int isword = 0;

    //scanf("%s", word);
    scanf ("%[^\n]%*c", word);
    //fgets (word, 1000000, stdin);
    wordlen = strlen(word);
    for (int i = 0; i < wordlen; i++) {
        if (isword == 0 && word[i] != ' ')
        {
            wordcount++;
            isword = 1;
        }
        else if (isword == 1 && word[i] == ' '){
            isword = 0;
        }
    }
    printf("%d", wordcount);
    return 0;
}*/


// 2908 상수
/*#include <stdio.h>
int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int A100 = A / 100 * 100;
    int A10 = (A - A / 100 * 100) / 10 * 10;
    int A1 = A - A100 - A10;
    int reverse_A = A100 / 100 + A10 + A1 * 100;

    int B100 = B / 100 * 100;
    int B10 = (B - B / 100 * 100) / 10 * 10;
    int B1 = B - B100 - B10;
    int reverse_B = B100 / 100 + B10 + B1 * 100;

    if (reverse_A > reverse_B)
        printf("%d", reverse_A);
    else
        printf("%d", reverse_B);
    return 0;
}*/

// 5622 다이얼
/*#include <stdio.h>
int main() {
    
    char chars[16] = {0};
    int chlen = 0;
    int dialtime = 0;

    scanf("%s", chars);
    chlen = strlen(chars);
    for (int i = 0; i < chlen; i++) {
        if (chars[i] >= 'A' && chars[i] <= 'C')
            dialtime += 3;
        else if (chars[i] >= 'D' && chars[i] <= 'F')
            dialtime += 4;
        else if (chars[i] >= 'G' && chars[i] <= 'I')
            dialtime += 5;
        else if (chars[i] >= 'J' && chars[i] <= 'L')
            dialtime += 6;
        else if (chars[i] >= 'M' && chars[i] <= 'O')
            dialtime += 7;
        else if (chars[i] >= 'P' && chars[i] <= 'S')
            dialtime += 8;
        else if (chars[i] >= 'T' && chars[i] <= 'V')
            dialtime += 9;
        else if (chars[i] >= 'W' && chars[i] <= 'Z')
            dialtime += 10;
    }
    printf("%d", dialtime);

    return 0;
}*/


// 11718 그대로 출력하기
#include <stdio.h>
int main() {
    
    char inputstr[101] = "";
    int cont = 1;

    while(cont) {
        int result = scanf("%[^\n]%*c", inputstr);
        if (result != 1)
            cont = 0;
        else
            printf("%s\n", inputstr);
    }
    return 0;
}
