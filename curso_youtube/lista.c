#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no* proximo;
    
}No;

typedef struct fila
{
    No *inicio;
    No *fim;
}Fila;

void insere(Fila *fila){
    int cpf;
    printf("digite o cpf que deseja inserir na fila\n");
    scanf("%d", &cpf);

    No *novono;
    novono = (No*) malloc(sizeof(No));
    novono->valor = cpf;
    novono ->proximo = NULL;
    if (fila->inicio == NULL)
    {
            fila->inicio = novono;
            fila->fim = novono;
    }
    else{

        fila->fim->proximo = novono;
        fila->fim = novono ;
    }


}



int main(void){

Fila *fila;
fila = (Fila*) malloc(sizeof(Fila));


}