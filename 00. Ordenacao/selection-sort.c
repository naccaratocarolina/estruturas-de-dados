#include<stdio.h>
#include<stdlib.h>

void static Swap (int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*
 * Selection Sort
 *
 * Para cada i de 1 a N-1, realiza a troca de
 * a[i] com o menor elemento em a[i] ... a[N]
 *
 */
void selectionSort(int* a, int N) {
  int i, j, min;

  for (i=1; i<N-1; i++) {
    min = i;

    for (j=i+1; j<N; j++) 
      if (a[j] < a[min])
        min = j;

    Swap(&a[min], &a[i]);
  }
}

int* initArray(int* N, int* a) {
  int size = 0;
  int input;

  while (scanf("%d", &input) == 1) {
    int *temp = realloc(a, ++size * sizeof *temp);

    a = temp;
    temp[size - 1] = input;
  }

  *N = size;

  return a;
}

int main (int argc, char *argv[]) {
  int N;
  int* a = NULL;

  a = initArray(&N, a);
  selectionSort(a,N);

  for (int i=0; i<N; i++) 
    printf("%d\n", a[i]);
  
  printf("\n");
  free(a);
}
