#include <stdlib.h>
#include <stdio.h>

typedef struct pessoa
{
    char nome[50];
    int idade;

}Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;
}No;
 
Pessoa lerpessoa(){
    Pessoa p;
    printf("digite o nome da pessoa \n");
    scanf(" %[^\n]s", p.nome);

    printf("digite a idade da pessoa \n");
    scanf("%d", &p.idade);
}

void mostrapessoa(Pessoa pessoa){
    printf(" o nome é da pessoa %s \n", pessoa.nome);
    printf(" a idade da pessoa é %d \n", pessoa.idade);
 
}

No* empilhar(No *topo){
No *novo = malloc (sizeof(No));
novo ->p = lerpessoa();
novo-> proximo = topo;
return novo;
}

int main(void){
Pessoa pessoa;
No *topo = NULL;

int number = 0;

while (number == 0)
{
    int verification;
    printf("digite a função que deseja");
    scanf("%d", &verification);
    if (verification == 1)
    {
       topo = empilhar(topo);
    }
    else if(verification == 2){
        mostrapessoa(pessoa);
       
    }
}



}