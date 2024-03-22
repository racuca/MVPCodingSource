#include <stdio.h>


#define MAX_WEEK_ROWS 6
#define MAX_WEEK_DAYS 7

char* wdaysname[] = {"Sun", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat"};
int arraydaysofmonth[MAX_WEEK_ROWS * MAX_WEEK_DAYS] = {-1};

int Isleapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    return 0;
}

int getdaysofmonth(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (Isleapyear(year) == 1) 
        return 29;
    else
        return 28;
}

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

// zeller algorithm
int getstartwdayofyearmonth(int month, int year)
{
    int q = 1;
    int m = month;
    if (month < 3)
    {
        m = 12 + month;
        year = year - 1;
    }

    int k = year % 100;
    int j = year / 100;
    int h1 = ( q + (int)(13*(m + 1) / 5) + k + (int)(k / 4) + (int)(j / 4) -2*j);
    int h = mod(h1,7);
    
    // for debugging
    printf("q=%d m=%d k=%d j=%d h1=%d h=%d\n", q, m, k, j, h1, h);

    // h (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
    int realweekdays = h - 1;
    if (h == 0)
        realweekdays = 6;
        
    return realweekdays;    
}

void main()
{
    int month, year;

    for (;;) {
        // 년도 입력
        printf("year[if 0, exit] : ");
        scanf("%d", &year);
        // 월 입력
        printf("month[if 0, exit] : ");
        scanf("%d", &month);

        printf("\nMonth Year : %d %d\n", month, year);

        if (year == 0 && month == 0)
            return;

        // 년월의 시작요일을 가져온다.
        int startwdays = getstartwdayofyearmonth(month, year);
        // 년월의 일수를 가져온다.
        int monthdays = getdaysofmonth(month, year);
        printf("start wdays = %d %s  monthdays = %d\n", startwdays, wdaysname[startwdays], monthdays);

        printf("=====================================\n");
        for (int i = 0; i < MAX_WEEK_DAYS; i++) {
            printf(" %s ", wdaysname[i]);
        }
        printf("\n=====================================\n");

        // 월 배열 초기화
        for (int i = 0; i < MAX_WEEK_ROWS * MAX_WEEK_DAYS; i++) {
            arraydaysofmonth[i] = -1;
        }

        // 월 배열에 날짜들을 업데이트한다.
        for (int i = startwdays, daynum = 1; i < startwdays + monthdays; i++, daynum++) {
            arraydaysofmonth[i] = daynum;
            if (daynum >= monthdays)
            {
                break;
            }
        }
        
        // 배열을 하나씩 꺼내어 출력한다. 
        // 마지막 요일을 출력하면 종료한다. 
        for (int i = 0; i < MAX_WEEK_ROWS * MAX_WEEK_DAYS; i++) {
            int d = arraydaysofmonth[i];
            if (d > 0) {
                printf("%4d ", d);
            }
            else 
                printf("     ");
            
            if (i != 0 && i == 6 || i == 13 || i == 20 || i == 27 || i == 34)
                printf("\n");

            if (i > startwdays + monthdays)
                break;
        }
        printf("\n");
    }
}