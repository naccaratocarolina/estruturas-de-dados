#include<stdio.h>
#include<stdlib.h>

/*
 * Priority Queues
 *
 * Filas de prioridade são um tipo abstrato de dados
 * em que cada elemento está associado a um valor que 
 * indica sua prioridade. Pode generalizar tanto filas
 * quanto pilhas. 
 *
 * Operacoes permitidas:
 * -> construct: constroi uma fila de prioridade a partir
 *               de N itens fornecidos
 * -> insert: inserção de um elemento com um certo valor de 
 *            prioridade
 * -> remove: remove o item de maior (ou menor) prioridade
 * -> replace: substitui o item maior (ou menos) por um novo 
 *             item (a menos que o novo item seja maior/menor)
 * -> change: edição da prioridade de um elemento
 * -> delete: exclui um item especificado arbitrariamente
 * -> join: junta duas priority queues em uma grande
 *
 * Heap de maximos ou minimos é uma estrutura de dados eficiente 
 * para implementar Filas de Prioridades.
 *
 * Os algoritmos de fila de prioridade em heaps funcionam fazendo 
 * primeiro uma modificação estrutural simples que poderia violar 
 * a condição de heap e, em seguida, viajando através do heap, 
 * modificando-a, para garantir que a condição da heap seja satisfeita 
 * em todos os lugares.
 */

#define max 100

static int a[max+1], N;

void upheap (int k) {
  int v;

  v = a[k];
  a[0] = max;

  while (a[k/2] <= v) {
    a[k] = a[k/2];
    k = k/2;
  }

  a[k] = v;
}

void downheap (int k) {
  int j, v;

  v = a[k];

  while (k <= N/2) {
    j = k + k;
    if (j < N && a[j] < a[j+1]) j++;
  }
}

void insert (int v) {
  a[++N] = v; // adiciona v a heap
  upheap(N); // chamada para corrigir violação de condição de heap em N
}

int main (int argc, char *argv[]) {
}
