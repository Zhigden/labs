#include <stdio.h>

struct Date {
  int day;
  int month;
  int year;
};

int main() {
  int n;
  printf("Введите количество человек: ");
  scanf("%d", &n);

  struct Date dates[n];

  for (int i = 0; i < n; i++) {
    printf("Введите дату рождения человека №%d (день месяц год): ", i + 1);
    scanf("%d %d %d", &dates[i].day, &dates[i].month, &dates[i].year);
  }

  for (int i = 0; i < n; i++) {
    int decade = (dates[i].year / 10) % 10;
    int century = dates[i].year / 100 + 1;
    int season;

    if (dates[i].month >= 3 && dates[i].month <= 5) {
      season = 1;  // Весна
    } else if (dates[i].month >= 6 && dates[i].month <= 8) {
      season = 2;  // Лето
    } else if (dates[i].month >= 9 && dates[i].month <= 11) {
      season = 3;  // Осень
    } else {
      season = 4;  // Зима
    }

    printf("Человек №%d родился:\n", i + 1);
    printf("  В %d-й декаде\n", decade);
    printf("  В %d-м сезоне\n", season);
    printf("  В %d-м веке\n", century);
    printf("\n");
  }

  return 0;
}