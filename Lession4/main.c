#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void myBin(int number) {
  if (number != 0) {
    myBin(number / 2);
    printf("%i", number % 2);
  }
}

double power(float a, int b) {
  int i = b;
  float k = 1;

  if (b > 0) {
    k = a * power(a, b - 1);
  }
  return k;
}

int main() {

  // 1 Задание

  int numb;
  // system("chcp 1251 > nul");

  printf("Введите число в десятичном виде: ");
  scanf("%d", &numb);
  printf("Число в двоичном представлении:");
  myBin(numb);
  printf("\n\n");
  // system("pause > nul");

  // 2 Задание

  int a = 0.0;
  int b = 0;

  printf("Введиет число a: ");
  scanf("%d", &a);
  printf("Введите число b: ");
  scanf("%d", &b);

  printf("Результат: %lf", power(a, b));
  printf("\n\n");

  // 3 Задание

  // 4 Задание
  return 0;
}
