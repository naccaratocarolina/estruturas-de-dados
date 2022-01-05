#include <stdio.h>
#include <stdlib.h>

#define N 100
int pilha[N];
int top; // topo da pilha (armazena os indices)

/*
 * Cria a pilha inicializando o seu topo
 */
void criaPilha (void) {
  top = 0;
}

/*
 * Adiciona um novo elemento no fim da sequencia
 */
void empilha (int k) {
  pilha[top++] = k;
}

/*
 * Remove o elemento no fim da sequencia
 * @return elemento removido
 */
int desempilha (void) {
  return pilha[--top];
}

/*
 * Analiza o indice guardado no topo da pilha
 * @return true, se a pilha estiver vazia; false c.c.
 */
int pilhaVazia (void) {
  return top <= 0;
}

/*
 * Imprime a pilha
 */
void imprime (void) {
  for (int i=0; i<top; i++)
    printf("%d ", pilha[i]);
  puts("");
}

int main (void) {
  // Cria a pilha
  criaPilha();

  // Realiza operacoes na pilha
  empilha(6);
  empilha(7);
  empilha(8);
  empilha(9);
  printf("Desempilhamos o elemento %d\n", desempilha());
  empilha(13);
  empilha(15);
  printf("Desempilhamos o elemento %d\n", desempilha());
  printf("Desempilhamos o elemento %d\n", desempilha());
  printf("Desempilhamos o elemento %d\n", desempilha());

  // Imprime
  imprime();
}
