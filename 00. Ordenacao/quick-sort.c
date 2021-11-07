#include<stdio.h>
#include<stdlib.h>

void static Swap (int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*
 * Quick Sort
 * Quicksort é um método de ordenacao "dividir e conquistar".
 * Funciona particionando um arquivo em duas partes e, em seguida, 
 * ordenando as partes independentemente.
 *
 * O ponto crucial do método é o procedimento de partição, que deve 
 * reorganizar a matriz para fazer com que as três condições a seguir 
 * se mantenham:
 * (i) O elemento a[i] esta em seu lugar final na matriz dado algum i
 * (ii) Todos os elementos em a[l]...a[i-1] são menores ou iguais a[i]
 * (iii) Todos os elementos em a[i+1]...a[r] são maiores ou iguais a[i]
 */
void quickSort(int* a, int l, int r) {
  int v, i, j;
  if (r > l) {
    v = a[r];
    i = l - 1;
    j = r;
    
    // Particao
    for (;;) {
      while (a[++i] < v);
      while (a[--j] > v);
      if (i >= j) break;
      Swap(&a[i], &a[j]);
    }
    Swap(&a[i], &a[r]);

    // Chamada recursiva
    quickSort(a, l, i-1);
    quickSort(a, i+1, r);
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
  quickSort(a, 0, N-1);

  for (int i=0; i<N; i++) 
    printf("%d\n", a[i]);
  
  printf("\n");
  free(a);
}
