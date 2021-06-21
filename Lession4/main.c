#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void myBin(int number)
{
    if (number != 0) {
        myBin(number / 2);
        printf("%i", number % 2);
    }
}
 
int main () {
    int numb;
    //system("chcp 1251 > nul");
 
    printf("Введите число в десятичном виде: "); 
    scanf("%d", &numb);
    printf("Число в двоичном представлении:"); 
    myBin(numb);
    printf("\n");
    //system("pause > nul");
    
    
    
    return 0;
}
