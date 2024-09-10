#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *down;
};

struct Node *S = NULL;

void insertFirst(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = S;
  newNode->down = NULL;
  S = newNode;
}

void insertDown(struct Node *node, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->down = node->down;
  node->down = newNode;
}

void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  int data;
  int count1 = 0, count2 = 0;

  printf("Введите последовательность целых чисел, разделенных пробелами: ");
  while (scanf("%d", &data) != EOF) {
    if (data == 0) {
      count1++;
      count2 = 0;
    } else {
      count2++;
      if (count1 == 0) {
        insertFirst(data);
      } else {
        insertDown(S, data);
      }
    }
  }

  // Дополняем второй список нулями, если N < K
  if (count1 < count2) {
    for (int i = 0; i < count2 - count1; i++) {
      insertDown(S, 0);
    }
  }

  // Выводим списки
  struct Node *head1 = S;
  struct Node *head2 = S->down;

  printf("Первый список:\n");
  printList(head1);

  printf("Второй список:\n");
  printList(head2);

  return 0;
}