#include <stdio.h>

int main() {//вычисляет сумму элементов массива A на четных позициях и вычитает сумму элементов массива на нечетных позициях
    int n; //длина массива
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int s = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            s += A[i];
        } else {
            s -= A[i];
        }
    }

    printf("%d\n", s);

    return 0;
}