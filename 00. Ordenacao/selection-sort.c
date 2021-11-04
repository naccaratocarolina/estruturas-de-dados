#include<stdio.h>
#include<stdlib.h>

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
  int N, i;
  int* a = NULL;

  a = initArray(&N, a);

  for (int i=0; i<N; i++) 
    printf("%d\n", a[i]);
  
  printf("\n");
  free(a);
}
