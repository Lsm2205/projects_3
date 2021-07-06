#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) {

  if (n > 1) {
    for (int i = 2; i < n; i++)
      if (n % i == 0)
        return false;
    return true;
  } else
    return false;
}

int main() {

  int n;

  printf("Введите число: ");
  scanf("%d", &n);

  // выводим информацию о том, простое ли число n: 1 - да, 0 - нет
  if (isPrime(n) > 0) {
    printf("Введенное число простое \n");
  } else {
    printf("Введенное число не простое\n");
  }
  return 0;
}
