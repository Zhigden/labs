#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Route {
  char startPoint[50];
  char endPoint[50];
  int number;
};

int main() {
  // Создаем файл Spravka.dat
  FILE *outFile = fopen("Spravka.dat", "w");
  int numRoutes;
  printf("Введите количество маршрутов: ");
  scanf("%d", &numRoutes);

  for (int i = 0; i < numRoutes; i++) {
    struct Route route;
    printf("Введите начальный пункт маршрута №%d: ", i + 1);
    scanf("%s", route.startPoint);
    printf("Введите конечный пункт маршрута №%d: ", i + 1);
    scanf("%s", route.endPoint);
    printf("Введите номер маршрута №%d: ", i + 1);
    scanf("%d", &route.number);

    fwrite(&route, sizeof(struct Route), 1, outFile);
  }

  fclose(outFile);

  // Считываем номер маршрута с клавиатуры
  int routeNumber;
  printf("Введите номер маршрута, который хотите найти: ");
  scanf("%d", &routeNumber);

  // Ищем маршрут в файле
  FILE *inFile = fopen("Spravka.dat", "r");
  int found = 0;

  while (fread(&route, sizeof(struct Route), 1, inFile)) {
    if (route.number == routeNumber) {
      printf("Найден маршрут №%d:\n", route.number);
      printf("Начальный пункт: %s\n", route.startPoint);
      printf("Конечный пункт: %s\n", route.endPoint);
      found = 1;
      break;
    }
  }

  fclose(inFile);

  if (!found) {
    printf("Маршрут с номером %d не найден\n", routeNumber);
  }

  return 0;
}