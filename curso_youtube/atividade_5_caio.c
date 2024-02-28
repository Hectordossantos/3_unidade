#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info;
  struct no *prox;
}no;

typedef struct fila{
  no *inicio;
  no *final;
}fila;

void inserir(fila *f){
  int cpf;
  printf("digite o CPF que deseja inserir:");
  scanf("%d", &cpf);

  no *novono;
  novono = (no*)malloc(sizeof(no));
  novono->info = cpf;
  novono->prox = NULL;

  if(f->inicio == NULL){
  f->final = novono;
  f->inicio = novono;
  } else{
    f->final->prox = novono;
    f->final = novono;
  }
}

void listar(fila *f){
  no *aux;
  aux = (no*)malloc(sizeof(no));
  aux = f->inicio;
  printf("\nCPFs cadastrados:\n");
  if(f){
    while(aux){
      printf("%d\n", aux->info);
      aux = aux->prox;
    }
  if(f->inicio == NULL){
    printf("fila vazia !\n");
  }
  }
}

void remover(fila *f){
  no *aux;
  aux = (no*)malloc(sizeof(no));
  aux = f->inicio;
  f->inicio = f->inicio->prox;
  free(aux);
  printf("\nCPF removido\n");
}

int main(void){
  fila *fil;
  fil = (fila*)malloc(sizeof(fila));
  fil->final = NULL;
  fil->inicio = NULL;

  int num = 999;
  
  while(num != 0){
    printf("\nMENU\n");
    printf("1 - inserir\n2 - listar\n3 - remover\n0 - sair\n");
    printf("digite o numero correspodente a sua operacao: ");
    scanf("%d", &num);
    
    if (num == 1)
    {
      inserir(fil);
        
    }
    else if (num == 2)
    {
      listar(fil);
    }

    else if (num == 3)
    {

      remover(fil);
    }
    else if (num == 0)
    {
        printf("\nvocê encerrou o programa!\n");
    }
    else{
      printf("invalido");

    }
    
   
  }
  free(fil);

}