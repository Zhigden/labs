#include <stdio.h>
#include <stdbool.h>

int main() {//программа проверяет является ли данное число a простым
    int a;
    scanf("%d", &a);

    bool isPrime = true;

    for (int n = 2; n < a; n++) {
        if (a % n == 0) {//проверяем, делится ли a на текущее число n. Если a делится на n, мы устанавливаем isPrime в false и прерываем цикл с помощью break.
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        puts("Good");
    } else {
        puts("Bad");
    }

    return 0;
}