#include<stdio.h>
#include<stdlib.h>

/*
 * Insertion Sort
 * Os elementos à esquerda do índice i estão ordenados,
 * mas não estão em sua posição final, pois podem ter que 
 * ser movidos para abrir espaço para elementos menores 
 * encontrados posteriormente.
 */
void insertionSort(int* a, int N) {
  int i, j, v;

  for (j=2; j<N; j++) {
    v = a[j];
    i = j - 1;
    while (i > 0 && a[i] > v) {
      a[i + 1] = a[i];
      i--;
    }

    a[i + 1] = v;
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
  insertionSort(a, N);

  for (int i=0; i<N; i++) 
    printf("%d\n", a[i]);
  
  printf("\n");
  free(a);
}
