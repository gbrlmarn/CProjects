/*

Bubble sort implementation

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for rand seed

#define MAXLEN 10

int arr[MAXLEN];
int len = MAXLEN;

void swap(int*, int*);
void bubbleSort(int* , int);
void printArr(int*, int);
void randArr(int *, int);

void swap(int* x, int* y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int len)
{
  int i, j;

  for (i = 0; i < len; ++i)
    for (j = 0; j < len - 1 - i; ++j)
      if (arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
}

void randArr(int arr[], int len)
{
  int i;
  time_t t;
  srand((unsigned)time(&t));

  for (i = 0; i < len; ++i)
    arr[i] = rand() % 100;
}


void printArr(int arr[], int len)
{
  int i;

  for(i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}


int main(int argc, char *argv[])
{
  
  printArr(arr, len);
  randArr(arr, len);
  printArr(arr, len);
  bubbleSort(arr, len);
  printArr(arr, len);

  return 0;
}
