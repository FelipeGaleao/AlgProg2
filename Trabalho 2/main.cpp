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

  if (lst == NULL)
    return NULL;

  if (strcmp(lst->nome, nome) == 0)
    return lst;

  return buscaNome(lst->prox, nome);
}

Pessoa *buscaCPF(Pessoa *lst, int cpf) {

  if (lst == NULL)
    return NULL;

  if (lst->cpf == cpf)
    return lst;

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

bool removePorNome(Pessoa *lst, char *nome) {

  Pessoa *nova, *aux;
  nova = lst;
  aux = lst->prox;

  while (aux != NULL && strcmp(aux->nome, nome) != 0) {
    nova = aux;
    aux = aux->prox;
  }
  if (aux != NULL) {
    nova->prox = aux->prox;
    free(aux);
    return true;
  }
  

  return false;
}

bool removePorCPF(Pessoa *lst, int cpf) {

  Pessoa *nova, *aux;
  nova = lst;
  aux = lst->prox;

  while (aux != NULL && aux->cpf != cpf) {
    nova = lst;
    aux = aux->prox;
  }
  if (aux != NULL) {
    nova->prox = aux->prox;
    free(aux);
    return true;
  }
  return false;
}

//   ======================> INCREMENTAR DOSES <======================

bool IncrementaDosesPorNome(Pessoa *lst, char *nome) {
  Pessoa *pessoa = lst;
  while (pessoa != NULL && strcmp(pessoa->nome, nome) != 0) {
    pessoa = pessoa->prox;
  }
  if (pessoa != NULL && pessoa->nDoses < 2) {
    pessoa->nDoses++;
    return true;
  }

  free(pessoa);

  return false;
}
bool incrementaDosesPorCPF(Pessoa *lst, int cpf) {
  Pessoa *pessoa = lst;
  while (pessoa != NULL && pessoa->cpf != cpf) {
    pessoa = pessoa->prox;
  }
  if (pessoa != NULL && pessoa->nDoses < 2) {
    pessoa->nDoses++;
    return true;
  } 
  return false;
}

//   ======================> IMPRESSÃO <======================

void imprimePessoa(Pessoa *p) {
  Pessoa *pessoa;
  pessoa = p;

  if(p->nome != NULL){
  printf("------------\nPessoa de nome: %s \nCPF: %d\nNum. de doses aplicadas"
         ": %d \n------------\n",
         pessoa->nome, pessoa->cpf, pessoa->nDoses);
  }else{
      printf("------------\nPessoa de nome: null \nCPF: null\nNum. de doses aplicadas"
         ": null \n------------\n");
  }
}

void imprimeLista(Pessoa *lst) {

  Pessoa *p;

  for (p = lst->prox; p->nome != NULL; p = p->prox)
    printf("------------\nPessoa de nome: %s \nCPF: %d\nNum. de doses "
           "aplicadas: %d \n------------\n",
           p->nome, p->cpf, p->nDoses);

}

//   ======================> Limpar Listas <======================

void limpaLista(Pessoa **lst) {
  Pessoa *p = *lst;
  while (p != NULL) {
    Pessoa *aux = p->prox;
    free(p);
    p = aux;
  }
}

int main() {
  int n;
  char nome_pessoa[101];
  char op;
  char op2;
  int cpf;

  Pessoa *lst;

  /* Descobre a qtde de pessoas que serão inseridas na lista */
  scanf("%d", &n);

  lst = (Pessoa *)malloc(sizeof(Pessoa));
  lst->prox = NULL;

  for (int i = 0; i < n; i++) {
    scanf(" %[^\n]s", nome_pessoa);
    scanf("%d", &cpf);
    insere(lst, nome_pessoa, cpf);
  }
  while (op != 'x') {
    bool resultado;

    scanf(" %c", &op);
    scanf(" %c", &op2);

    switch (op) {

    // Opção de Impressão de lista
    case 'i':
      switch (op2) {

      // Opção Imprimir por Nome
      case 'n':
        scanf(" %[^\n]s", nome_pessoa);
        imprimePessoa(buscaNome(lst, nome_pessoa));
        break;
        
        // Opção Imprimir por CPF
      case 'c':
        scanf("%i", &cpf);
        imprimePessoa(buscaCPF(lst, cpf));
        break;
      }
      break;

    // Opção para Remover da Lista
    case 'r':
      switch (op2) {

        // Opção Remover por Nome
      case 'n':
        scanf(" %[^\n]s", nome_pessoa);
        resultado = removePorNome(lst, nome_pessoa);
        if (resultado) {
          printf("OK! \n");
        } else {
          printf("FAIL! \n");
        }
        break;
        // Opção Remover por CPF
      case 'c':
        scanf("%i", &cpf);
        resultado = removePorCPF(lst, cpf);
        if (resultado) {
          printf("OK! \n");
        } else {
          printf("FAIL! \n");
        }
        break;
      }
      break;

    // Incrementar dose
    case 'd':
      switch (op2) {

        // Incrementar dose por Nome
      case 'n':
        scanf(" %[^\n]s", nome_pessoa);
        resultado = IncrementaDosesPorNome(lst, nome_pessoa);
        if (resultado) {
          printf("OK! \n");
        } else {
          printf("FAIL! \n");
        }
        break;
      // Incrementar dose por CPF
      case 'c':
        scanf("%i", &cpf);
        resultado = incrementaDosesPorCPF(lst, cpf);
        if (resultado) {
          printf("OK! \n");
        } else {
          printf("FAIL! \n");
        }
        break;
      }
      break;
    }
  }
    imprimeLista(lst);
    limpaLista(&lst);
  return 0;
}