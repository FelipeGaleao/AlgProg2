#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
  char nome[];
  int cpf;
  int nDoses;
  Pessoa *prox;
};

//   ======================> BUSCAS <======================

Pessoa *buscaNome(Pessoa *lst, char *nome) {}
Pessoa *buscaCPF(Pessoa *lst, int cpf) {}

void insere(Pessoa *lst, char *nome, int cpf){}

//   ======================> REMOÇÃO <======================

bool removePorNome(Pessoa *lst, char *nome){}
bool removePorCPF(Pessoa *lst, int cpf){}

//   ======================> INCREMENTAR DOSES <======================

bool IncrementaDosesPorNome(Pessoa *lst, char *nome){}
bool incrementaDosesPorCPF(Pessoa *lst, int cpf){}

//   ======================> IMPRESSÃO <======================

void imprimePessoa(Pessoa *p){}
void imprimeLista(Pessoa *lst){}

//   ======================> Limpar Listas <======================

void limpaLista(Pessoa **lst){}


int main() {
    int n;

    scanf("%d", &n);

    Pessoa *lst = new Pessoa[n];

    return 0;
}