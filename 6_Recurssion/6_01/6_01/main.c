   //
//  main.c
//  6_01
//
//  Created by Wonkeun No on 2020-04-15.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>

int factorial(int n) {
    int ret = 0;
    
    if (n <= 1) {
        ret = 1;
    } else {
        ret = n*factorial(n-1);
    }
    return ret;
}
int factorial_iter(int n) {
    int ret=1;
    int i=1;
    
    for (i=n; i>1; i--) {
        ret = ret *i;
    }
    return ret;
}
int fib(int n) {
    int ret = 0;
    
    if (n == 0) {
        ret = 0;
    } else if (n == 1) {
        ret = 1;
    } else {
        ret = fib(n-1) + fib(n-2);
    }
    return ret;
}
int fib_iter(int n) {
    int ret = 0;
    
    if (n < 2) {
        ret = n;
} else {
    int i =0, temp = 0, current = 1, last = 0;
    for (i=2; i<=n; i++) {
        temp = current;
        current += last;
        last = temp;
    }
    ret = current;
}
    return ret;
}
void hanoi_tower(int n, char from , char temp, char to) {
    if (n == 1){
        printf("원판 1을 %c에서 %c로 옮겼습니다\n", from, to);
    } else {
        hanoi_tower(n-1, from, to, temp);
        printf("원판 %i를 %c에서 %c로 옮겼습니다\n", n, from, to);
        hanoi_tower(n-1, temp, from, to);
    }
}
void hanoi_tower_iter() {
    int i =0;
    if (i == 1) {
        i++;
    }
}
void recursive(int n) {
    if (n > 1) {
        recursive(n/2);
        recursive(n/2);
    }
    printf("%i\n", n);
}
int acculNum1(int n) {
    int total = 0;
    if (n > 0) {
        total = n + acculNum1(n-1);
    }
    return total;
}
float acculNum2(int n) {
    float total = 0;
    if (n >= 1) {
        total = 1/n + acculNum2(n-1);
    }
    return total;
}
int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n-1);
    }
}
int sum_iter(int n) {
    int i=0;
    int total =0;
    for (i=1; i <= n; i++) {
        total += i;
    }
    return total;
}
/* int main(int argc, const char * argv[]) {
    int input_value = 3;
    int result = 0;
    
    result = factorial(input_value);
    
    printf("%d! = %d\n", input_value, result);
    
    char from = 'A';
    char temp = 'B';
    char to = 'C';
    
    hanoi_tower(4, from, temp, to);
    
    recursive(5);
    
    printf("%d\n", acculNum1(9));
    printf("%f\n", acculNum2(4));
    printf("%f\n", 1 + 1/2 + 1/3 + 1/4);
    
    printf("%d\n", sum(5));
    printf("%d\n", sum_iter(5));
}
*/
