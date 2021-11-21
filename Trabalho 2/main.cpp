#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
  char nome[101];
  int cpf;
  int nDoses;
  Pessoa *prox;
};

//   ======================> BUSCAS <======================

Pessoa *buscaNome(Pessoa *lst, char *nome) {

  char nomeBuscado[101];
  strcpy(nomeBuscado, nome);

  if (lst->prox == NULL)
    return NULL;
  if (lst->prox->nome == nomeBuscado)
    return lst->prox;

  return buscaNome(lst->prox, nome);
}

Pessoa *buscaCPF(Pessoa *lst, int cpf) {

  if (lst->prox == NULL)
    return NULL;
  if (lst->prox->cpf == cpf)
    return lst->prox;
  return buscaCPF(lst->prox, cpf);
}

void insere(Pessoa *lst, char *nome, int cpf) {

  Pessoa *nova;

  nova = (Pessoa *)malloc(sizeof(Pessoa));
  strcpy(nova->nome, nome);
  nova->cpf = cpf;
  nova->nDoses = 0;
  nova->prox = lst->prox;

  lst->prox = nova;
    
}

//   ======================> REMOÇÃO <======================

bool removePorNome(Pessoa *lst, char *nome) {}
bool removePorCPF(Pessoa *lst, int cpf) {}

//   ======================> INCREMENTAR DOSES <======================

bool IncrementaDosesPorNome(Pessoa *lst, char *nome) {}
bool incrementaDosesPorCPF(Pessoa *lst, int cpf) {}

//   ======================> IMPRESSÃO <======================

void imprimePessoa(Pessoa *p) {
  Pessoa *pessoa;
  pessoa = p;
  printf("------------\nPessoa de nome: %s \nCPF: %d\nNum . de doses aplicadas "
         ": %d \n------------\n",
         pessoa->nome, pessoa->cpf, pessoa->nDoses);
  free(pessoa);
}

void imprimeLista(Pessoa *lst) {

  Pessoa *p;

  for (p = lst; p != NULL; p = p->prox)
    printf("------------\nPessoa de nome: %s \nCPF: %d\nNum . de doses "
           "aplicadas : %d \n------------\n",
           p->nome, p->cpf, p->nDoses);

  free(p);

}

//   ======================> Limpar Listas <======================

void limpaLista(Pessoa *lst) { free(lst); }

int main() {
  int n;
  scanf("%d", &n);
  char nome_pessoa[101];
  char op;
  char op2;
  int cpf;
  int finaliza = 0;
  Pessoa *lst;

  lst = (Pessoa *)malloc(sizeof(Pessoa));
  lst->prox = NULL;

  for (int i = 0; i < n; i++) {
    scanf(" %[^\n]s", nome_pessoa);
    scanf("%d", &cpf);
    insere(lst, nome_pessoa, cpf);
  }
  // while (finaliza != 1) {
  //   scanf(" %c", &op);
  //   scanf(" %c", &op2);
  //   printf("%c %c", op, op2);

    void (*pf) (Pessoa *p);
    pf = imprimePessoa;
    (*pf)(buscaCPF(lst, 112));
    
  // }

  imprimePessoa(buscaCPF(lst, 112));
  limpaLista(lst);

  return 0;
}