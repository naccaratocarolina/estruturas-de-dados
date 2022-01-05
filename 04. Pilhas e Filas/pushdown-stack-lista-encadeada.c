#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;

struct celula {
  int conteudo;
  Celula *prox;
};

/*
 * Cria pilha com noh cabeca
 * @return ponteiro para a pilha
 */
Celula *criaPilhaCNC (void) {
  Celula *s; // noh cabeca
  s = (Celula *) malloc(sizeof(Celula));
  s->prox = NULL;
  return s;
}

/*
 * Insere um item no fim da sequencia (apos
 * o noh cabeca)
 * @return ponteiro para a celula criada
 *
 */
void empilhaCNC (Celula *s, int conteudo) {
  Celula *nova;
  nova = malloc(sizeof(Celula));

  nova->conteudo = conteudo;
  nova->prox = s->prox;
  s->prox = nova;
}

/*
 * Remove um item do fim da sequencia (ou
 * seja, remove a celula sucessora do noh
 * cabeca)
 * @return conteudo da celula removida
 */
int desempilhaCNC (Celula *s) {
  int conteudo;
  Celula *morta;

  morta = s->prox;
  conteudo = morta->conteudo;
  s->prox = morta->prox;
  free(morta);
  morta = NULL;

  return conteudo;
}

/*
 * Retorna o conteudo da celula no topo
 * da pilha (ou seja, head->prox)
 * @return inteiro armazenado no topo da sequencia
 */
int consultaTopoCNC (Celula *s) {
  return s->prox->conteudo;
}

/*
 * Veridica se a pilha esta vazia analizando a celula
 * apontada pela cabeca
 * @return true, se a pilha estiver vazia; false, c.c.
 */
int pilhaVaziaCNC (Celula *s) {
  return s->prox == NULL;
}

/*
 * Imprime os elementos armazenados na sequencia
 */
void imprimeCNC (Celula *s) {
  Celula *p;
  p = s->prox; // topo
  while (p != NULL) {
    printf("%d ", p->conteudo);
    p = p->prox;
  }
  puts("");
}

/*
 * Retorna a quantidade de elementos na pilha
 * (desconsidera o noh cabeca)
 * @return quantidade de elementos na pilha
 */
int tamPilhaCNC (Celula *s) {
  Celula *p;
  int tam = 0;

  p = s->prox;
  while (p != NULL) {
    p = p->prox;
    tam++;
  }

  return tam;
}

/*
 * Percorre a pilha, liberando memoria de cada
 * elemento armazenado na mesma
 * @return NULL
 */
Celula *liberaPilhaCNC (Celula *s) {
  Celula *p, *morta;

  p = s;
  while (p != NULL) {
    morta = p;
    p = p->prox;
    free(morta);
  }

  return NULL;
}

int main (void) {
  Celula *s;

  // Inicializa a pilha
  s = criaPilhaCNC();

  // Empilha 
  empilhaCNC(s, 15);
  empilhaCNC(s, 6);
  empilhaCNC(s, 2);
  empilhaCNC(s, 9);

  // Imprime a pilha
  imprimeCNC(s);

  // Desempilha e armazena em x
  int x = desempilhaCNC(s);
  printf("Elemento removido = %d\n", x);

  // Imprime a pilha
  imprimeCNC(s);

  // Consulta topo da pilha
  printf("Topo = %d\n", consultaTopoCNC(s));

  // Tamanho da sequencia
  printf("Tamannho da sequencia: %d\n", tamPilhaCNC(s));

  // Libera pilha
  s = liberaPilhaCNC(s);

  return 0;
}
