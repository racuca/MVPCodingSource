// 24262. 알고리즘 - 알고리즘의 수행 시간 1
/*#include <stdio.h>
int main() {
    
    int n;
    scanf("%d", &n);
   
    printf("%d\n", 1);
    printf("%d", 0);
    return 0;
}*/

// 24263. 알고리즘 수업 - 알고리즘의 수행 시간 2
/*#include <stdio.h>
int main() {
    
    int n;
    scanf("%d", &n);
   
    printf("%d\n", n);
    printf("%d", 1);
    return 0;
}*/

// 24264. 알고리즘 수업 - 알고리즘의 수행 시간 3
/*#include <stdio.h>
int main() {
    
    unsigned long long int n;
    scanf("%llu", &n);
   
    printf("%llu\n", n*n);
    printf("%d", 2);
    return 0;
}*/

// 24265. 알고리즘 수업 - 알고리즘의 수행 시간 4
/*#include <stdio.h>
int main() {
    
    unsigned long long int n;
    scanf("%llu", &n);
    
    //printf("%llu\n", (n-1) + (n-2) + ... + 1);
    printf("%llu\n", (n-1)*(n-1+1)/2);
    printf("%d", 2);
    return 0;
}*/

// 24266. 알고리즘 수업 - 알고리즘의 수행 시간 5
/*#include <stdio.h>
int main() {
    
    unsigned long long int n;
    scanf("%llu", &n);
    
    //printf("%llu\n", (n-1) + (n-2) + ... + 1);    
    printf("%llu\n", n*n*n);
    printf("%d", 3);
    return 0;
}*/


// 24267. 알고리즘 수업 - 알고리즘의 수행 시간 6
#include <stdio.h>
int main() {
    
    unsigned long long int n;
    scanf("%llu", &n);
    // 7
    // 1 ~ 5                      (n-2)
    // 2 ~ 6(5), 3 ~ 6(4), ... 1  (n-2)
    // 3 ~ 7(5), 4 ~ 7(4), ..., 1, 4 ~ 7(4), ..., 1 = (n-2)*(n-2+1)/2 + (n-3)*(n-3+1)/2 + ..., 
    printf("%llu\n", n * (n-1) * (n-2) / 6 );
    printf("%d", 3);
    return 0;
}

