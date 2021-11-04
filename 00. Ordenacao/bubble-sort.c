#include<stdio.h>
#include<stdlib.h>

void static Swap (int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


/*
 * Bubble Sort
 * Continua passando pelos elementos do arquivo,
 * trocando elementos subjacentes, se necessario;
 * Quando nenhuma troca eh necessaria dada uma
 * passagem, o arquivo esta ordenado.
 */
void bubbleSort(int* a, int N) {
  int i, j;

  for (i=1; i<N; i++) 
    for (j=0; j< N-1; j++)
      if (a[j] > a[j+1])
        Swap(&a[j], &a[j+1]);
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
  bubbleSort(a, N);

  for (int i=0; i<N; i++) 
    printf("%d\n", a[i]);
  
  printf("\n");
  free(a);
}
