#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array, int length);
void printArray(int array[2][6], int length);

void printArray(int array[2][6], int length) {
  for (int i = 0; i < length; i++)
    for (int j = 0; j < length; j++) {
      printf("%d", array[i][j]);
    }
  printf("\n");
}

void bubbleSort(int array, int length, int lengthn) {
  int counter = 1;
  while (counter != 0) {
    counter = 0;
    for (int i = 0; i < length - 1; i++)
      for (int j = 0; j < length - 1; j++) {
        if (array[i][j] > array[i + 1][j + 1])
        // if (array[j] >  array[j + 1])
        {
          int tmp = array[i][j];
          // int tmp2 = array[j];
          array[i][j] = array[i + 1][j + 1];
          array[i + 1][j + 1] = tmp;
          // array[j] =  array[j +1];
          // array[j + 1]= tmp2;
          counter = 1;
        }
      }
  }
}

int main() {
  int array[2][6] = {{1, 7, 8, 9, 3, 4}, {3, 4, 10, 4, 2, 7}};
  // int array[] = { 1,7,8,9,3,4,3,4,10,4,2,7 };
  int length = sizeof(array) / sizeof(array[0][0]);
  // int lengthn = sizeof(array) / sizeof(array[0][0]);

  printArray(array, length);
  bubbleSort(array, length);
  printArray(array, length);

  return 0;
}
