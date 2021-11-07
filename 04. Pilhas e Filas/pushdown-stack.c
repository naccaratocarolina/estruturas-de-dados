#include<stdio.h>
#include<stdlib.h>

/*
 * Pushdown Stacks
 * Apenas duas operações básicas estão envolvidas: 
 * push: empurrar um item para a pilha (inseri-lo no início); e
 * pop: remover um item da pilha (removê-lo do início)
 *
 * "last in,  first  out"
 */
struct Node {
  int key;
  struct Node *next;
};

static struct Node *head, *tail, *t;

void stackInit () {
  head = (struct Node *) malloc(sizeof *head);
  tail = (struct Node *) malloc(sizeof *tail);
  head->next = tail; // cabeca aponta para cauda
  head->key = 0;
  tail->next = tail; // cauda aponta para si mesma
}

void push (int value) {
  t = (struct Node *) malloc(sizeof *head);
  t->key = value;
  t->next = head->next; // insere no inicio da pilha (apos o noh cabeca)
  head->next = t;
}

int pop () {
  int x;

  t = head->next; // queremos deletar o noh head->next
  head->next = t->next; // noh cabeca agora aponta para t->next
  x = t->key;
  free(t);
  return x;
}

int isStackEmpty () {
  return head->next == tail;
}

void printStack () {
  t = head->next;
  while (t != tail) {
    printf("%d", t->key);
    t = t->next;
  }

  printf("\n");
}

int queryTop () {
  return head->next->key;
}

int querySize () {
  int size = 0;

  t = head->next;
  while (t != tail) {
    t = t->next;
    size++;
  }

  return size;
}

int main (int argc, char *argv[]) {
  // Inicializa a pilha
  stackInit();

  // Empilha 123
  push(1);
  push(2);
  push(3);

  // Imprime a pilha
  printStack();

  // Printa o primeiro elemento da pilha
  printf("%d\n", queryTop());

  // Printa o tamanho da pilha
  printf("%d\n", querySize());

  // Remove o primeiro elemento da pilha
  pop();

  // Imprime a pilha
  printStack();

  printf("%d\n", tail->key);
}
