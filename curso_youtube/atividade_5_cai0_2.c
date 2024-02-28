#include <stdio.h>
#include <stdlib.h>

#define n 100

int main(void){
  int fila[n];
  int num = 999, inicio = 0, fim = 0, cpf;

  while(num != 0){
    printf("\nMENU\n");
    printf("1 - inserir\n2 - listar\n3 - remover\n0 - sair\n");
    printf("digite o numero correspodente a sua operacao: ");
    scanf("%d", &num);
    if (num == 1)
    {
      
      printf("\ndigite o CPF a ser inserido:");
      scanf("%d", &cpf);
      fila[fim] = cpf;
      fim++;
      
    }
     else if (num == 2)
    {
      if(inicio > n){
        exit(0);
      }
      printf("\nCPFs cadastrados:\n");
      if(inicio == fim){
        printf("fila vazia !\n");
      }
    
      for(int i = inicio; i < fim; i++){
        printf("%d\n", fila[i]);
      }
    }

     else if (num == 3)
    {
      if(inicio > fim - 1){
        exit(1);
      }
      inicio++;
      printf("\nCPF removido\n");
      
    }
    else if (num == 0)
    {
        printf("\nprograma encerrado\n");
    }
    
    else{
      printf("\ninvalido\n");
   }
  }
}

