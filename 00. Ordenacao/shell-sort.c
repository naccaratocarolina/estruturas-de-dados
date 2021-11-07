#include<stdio.h>
#include<stdlib.h>

/*
 * Shell Sort
 * É uma simples extensão do insertion sort que ganha 
 * velocidade ao permitir trocas de elementos distantes.
 *
 * A ideia é reorganizar o arquivo para dar a ele a propriedade 
 * de que cada i-ésimo elemento (começando em qualquer lugar) 
 * produz um arquivo ordenado.
 */
void shellSort(int* a, int N) {
  int i, j, h, v;

  for (h=1; h<N; h=3*h+1); // calcula o h inicial
  while (h > 0) {
    h = (h-1)/3; // atualiza o valor de h
    for (i=1; i<N; i++) {
      v = a[i];
      j = i;

      // efetua comparacoes entre elementos com distancia h
      while (j > h && a[j-h] > v) {
        a[j] = a[j-h];
        j -= h;
      }
      a[j] = v;
    }
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
  shellSort(a, N);

  for (int i=0; i<N; i++) 
    printf("%d\n", a[i]);
  
  printf("\n");
  free(a);
}
