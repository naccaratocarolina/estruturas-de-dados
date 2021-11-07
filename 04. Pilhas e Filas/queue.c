#include<stdio.h>
#include<stdlib.h>

/*
 * Queue
 * Outra estrutura de dados de acesso restrito fundamental é chamada de queue (fila). 
 * Novamente, apenas duas operações básicas estão envolvidas: 
 * insert: pode-se inserir um item na fila no início; e 
 * remove: remover um item do final.
 *
 * "first in,  first  out", ou seja, inserimos no final e removemos do inicio
 */

#define max 100

static int queue[max+1], head, tail;

int isQueueFull ();

void queueInit () {
  head = 0;
  tail = 0;
}

void enqueue (int value) {
  if (isQueueFull()) { // verifica se a fila esta cheia
    printf("A fila esta cheia! Nao eh possivel adicionar mais itens.\n");
    return;
  }

  queue[tail++] = value;
  if (tail > max) tail = 0;
}

int dequeue () {
  int t = queue[head++];
  if (head > max) head = 0;
  return t;
}

int isQueueEmpty () {
  return head == tail;
}

int isQueueFull () {
  return (tail + 1) % max == head;
}

int querySize () {
  if (head <= tail)
    return tail - head;
  return (max - head) + (tail - 0);
}

void printQueue () {
  int i;

  if (head <= tail)
    for (i=head; i<tail; i++) 
      printf("%d", queue[i]);
  else {
    for (i=head; i<max; i++) 
      printf("%d", queue[i]);
    for (i=0; i<tail; i++)
      printf("%d", queue[i]);
  }

  printf("\n");
}

int main (int argc, char *argv[]) {
  // Inicializa Queue
  queueInit();
  
  // Enfila 123
  enqueue(1);
  enqueue(2);
  enqueue(3);

  // Printa a fila
  printQueue();

  // Remove o primeiro item
  printf("Item removido -> %d\n", dequeue());

  // Printa a fila novamente
  printQueue();
}
