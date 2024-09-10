#include <stdio.h>
#include <stdlib.h>

float average(int nums[], int n, int sum) {
  if (n == 0) {
    return (float)sum;
  } else {
    return average(nums, n - 1, sum + nums[n - 1]);
  }
}

int main() {
  int n;
  printf("Введите количество случайных чисел: ");
  scanf("%d", &n);

  int nums[n];
  for (int i = 0; i < n; i++) {
    nums[i] = rand() % 100 + 1;
  }

  float avg = average(nums, n, 0);

  printf("Среднее арифметическое: %.2f\n", avg);

  return 0;
}