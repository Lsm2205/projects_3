#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define arr 8
#define stack_len 6


//1. Задание

typedef struct {
    int priority;
    int item;
} Element;

Element *array[arr];
int start;
int end;
int quantity_elements;

void init() {
    for (int i = 0; i < arr; i++) {
        array[i] = NULL;
    }

    start = 0;
    end = 0;
    quantity_elements = 0;
}

void insert(int priority, int item) {
    Element *el = (Element *) malloc(sizeof(Element));
    el->priority = priority;
    el->item = item;
    int flag;

    if (quantity_elements == 0) {
        array[end++] = el;
        quantity_elements++;
    } 
    else if (quantity_elements == arr) {
        printf("%s \n", "Очередь заполнена");
        return;
    } 
    else {
        int i = 0;
        int index = 0;
        Element *tmp;

        for (i = start; i < end; ++i) {
            index = i % arr;

            if (array[index]->priority > priority) {
                break;
            } 
            else {
                index++;
            }
        }
        flag = index % arr;
        i++;
        while (i <= end) {
            index = i % arr;
            tmp = array[index];
            array[index] = array[flag];
            array[flag] = tmp;
            i++;
        }
        array[flag] = el;
        quantity_elements++;
        end++;
    }
}

Element *removal() {
    if (quantity_elements == 0) {
        return NULL;
    } 
    else {
        int index = start++ % arr;
        Element *tmp = array[index];
        array[index] = NULL;
        quantity_elements--;
        return tmp;
    }
}

void printQueue() {
    printf("[");
    for (int i = 0; i < arr; ++i) {
        if (array[i] == NULL) {
            printf("[*, *] ");
        } 
        else {
            printf("[%d, %d] ", array[i]->priority, array[i]->item);
        }
    }
    printf(" ]\n");
}

// 2. Задание

int cursor = -1;

int push_stack(int *stack, int item) {
    if (cursor < stack_len) {
        stack[++cursor] = item;
    } 
    else {
        cursor = -1;
        stack[++cursor] = item;
    }
}

void rec_decimal_to_binary(int *stack, int number) {
    int spam_number = 0;
    while (number != 0) {
        spam_number = number % 2;
        push_stack(stack,spam_number == 0 ? 0 : 1);
        number /= 2;
    }
}

void print_int_stack(int *stack, int len) {
    for (int i = len - 1; i > -1; i--) {
        printf("%2d ", stack[i]);
    }
    printf("\n");
}


int main() {
//1. 
    init();
    insert(1,1);
    insert(3,2);
    insert(4,3);
    insert(2,4);
    insert(3,5);
    insert(5,7);
    insert(1,8);
    insert(6,10);
    printQueue();
    printf("\n");
    removal();
    removal();
    printQueue();
    printf("\n");
    
// 2.
    int c;
    int array_stack[stack_len];
    printf("Введите десятичное число\n");
    scanf("%d", &c);
    rec_decimal_to_binary(array_stack, c);
    print_int_stack(array_stack, stack_len);

    return 0;
}
