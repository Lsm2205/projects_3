#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define SIZE 20

  // Пример быстрой сортировки на основанный на принципе обмена

void sort (int* array, int left, int right)

     {
	int i = left, j = right;
	int temp, pivot = array[ (left+right)/2 ];
	while (i <= j)
    {
	while (array[i] < pivot) i++;
	while (array[j] > pivot) j--;
	if (i <= j)
	{
	if (array[i] > array[j])
	{
	temp = array[i]; array[i] = array[j]; array[j] = temp;
	}
	i++; j--;
    }
 }

	if (left < j) sort (array, left, j);
	if (i < right) sort (array, i, right);
	}

    int main() {
	int array[SIZE];
       for (int i = 0; i<SIZE; i++) 
       array[i] = rand()%50;
      for (int i = 0; i<SIZE; i++) 
      printf("%3d ", array[i]); 
      printf("\n");
      sort(array, 0, SIZE-1); 
    for (int i = 0; i<SIZE; i++) 
    printf("%3d ", array[i]); printf("\n");

     
     return 0;

}
