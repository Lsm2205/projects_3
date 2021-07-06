#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *array, int length);
void printArray(int array[], int length);

void printArray(int array[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", array[i]);
  }
  printf("\n");
}

void bubbleSort(int *array, int length) {
  int counter = 1;
  while (counter != 0) {
    counter = 0;
    for (int i = 0; i < length - 1; i++) {
      if (array[i] > array[i + 1]) {
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
        counter = 1;
      }
    }
  }
}

double f(double x) { return (sqrt(fabs(x)) + 5 * pow(x, 3)); }

int main() {
  // int array[2][6] = {{1,7,8,9,3,4},{3,4,10,4,2,7}};
  int array[] = {1, 7, 8, 9, 3, 4, 3, 4, 10, 4, 2, 7};
  int length = sizeof(array) / sizeof(array[0]);

  printArray(array, length);
  bubbleSort(array, length);
  printArray(array, length);

  printf("\n");

  int e;
  double A[11], y;
  printf("Введите 11 чисел\n");
  for (int e = 0; e < 11; e++)
    scanf("%lf", &A[e]);

  for (e = 10; e >= 0; e--) {
    y = f(A[e]);
    if (y > 400.0) {
      printf("%d TOO LARGE\n", e);
    } else {
      printf("%d %f\n", e, y);
    }
  }

  return 0;
}
