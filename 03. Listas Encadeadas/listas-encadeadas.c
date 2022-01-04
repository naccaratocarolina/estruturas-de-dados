#include<stdio.h>
#include<stdlib.h>

typedef struct celula Celula;

struct celula {
  int conteudo;
  Celula *prox;
};

Celula *ini = NULL; // lista vazia (= head)

/*
 * Imprime o conteudo de uma lista
 */
void imprime (Celula *ini) {
  Celula *p = ini;

  while (p != NULL) {
    printf("%d ", p->conteudo);
    p = p->prox;
  }

  puts("");
}

/*
 * Encontra um item pelo seu conteudo
 */
Celula *busca (Celula *ini, int conteudo) {
  Celula *p = ini;

  while (p != NULL && p->conteudo != conteudo) {
    p = p->prox;
  }

  return p;
}

/*
 * Pega o conteudo do k-esimo item
 */
Celula *selecao (Celula *ini, int k) {
  Celula *p = ini;
  int q = 0;

  while (p != NULL && q < k) {
    p = p->prox;
    q++;
  }

  return p;
}

/*
 * Insere um item na posicao k
 */
Celula *insere (Celula *ini, int conteudo) {
  Celula *nova;
  nova = malloc(sizeof(Celula));

  nova->conteudo = conteudo;
  nova->prox = ini;

  return nova;
}

/*
 * Remove a celula sucessora de p
 * supoe que p != NULL e p->prox != NULL
 */
void remove1 (Celula *p) {
  Celula *morta;
  morta = p->prox;
  p->prox = morta->prox;
  free(morta);
}

/*
 * Remove a celula apontada por p
 * supor que *p != NULL
 */
Celula *remove2 (Celula *p) {
  Celula *morta;
  morta = p;
  p = morta->prox;
  free(morta);
  return p;
}

/*
 * Busca x na lista e insere y logo antes de x
 * Se x nao esta na lista, insere y no final
 */
Celula *buscaInsere (Celula *ini, int x, int y) {
  Celula *p, *q, *nova; // celula anterior a x, celula x e nova celula (y)
  
  // Aloca espaco e inicializa nova celula
  nova = malloc(sizeof(Celula));
  nova->conteudo = y;

  // Se a lista estiver vazia ou x for a primeira celula
  if (ini == NULL || ini->conteudo == x) {
    nova->prox = ini; // nova vira a nova cabeca
    return nova;
  }

  // Se x estiver ao longo da lista
  p = ini;
  q = p->prox;
  // Percorre a lista ate encontrar x
  while (q != NULL && q->conteudo != x) {
    p = q;
    q = p->prox;
  }

  // Insere y antes de x (q)
  p->prox = nova; // celula anterior a x passa a apontar para y
  nova->prox = q; // y passa a apontar para x

  return ini;
}

int main (int argc, char *argv[]) {
  // Insere elementos na lista
  ini = insere(ini, 29);
  ini = insere(ini, 22);
  ini = insere(ini, 10);
  ini = insere(ini, 7);
  ini = insere(ini, 15);

  // Imprime lista
  imprime(ini);

  // Busca celula dado o seu conteudo
  Celula *p = busca(ini, 10);
  printf("Encontrei a celula de conteudo %d\n", p->conteudo);

  // Pega o conteudo da k-esima celula
  int k = 1;
  Celula *q = selecao(ini, k);
  printf("Celula na posicao %d possui conteudo %d\n", k, q->conteudo);

  // Remove celula sucessora a ini
  remove1(ini);
  imprime(ini);

  // Remove celula apontada por ini
  ini = remove2(ini);
  imprime(ini);

  // Insere 33 antes de 29
  ini = buscaInsere(ini, 29, 33);
  imprime(ini);
}
