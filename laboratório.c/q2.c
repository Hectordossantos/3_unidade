#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct fila {
    No *inicio;
    No *final;
} Fila;

Fila *filaCreate(void) {
    Fila *novafila = (Fila *)malloc(sizeof(Fila));
    novafila->inicio = NULL;
    novafila->final = NULL;
    return novafila;
}

void filaInsert(Fila *f, int valor) {
    No *novono = (No*)malloc(sizeof(No));
    novono->dado = valor;
    novono->proximo = NULL;

    if (f->inicio == NULL) {
        f->inicio = f->final = novono;
    } else {
        f->final->proximo = novono;
        f->final = novono;
    }
}

int filaRemove(Fila *f) {
    if (f->inicio) {
        int valor = f->inicio->dado;
        No *novo = f->inicio;
        f->inicio = f->inicio->proximo;
        free(novo);
        return valor;
    }
    return -1;
}

int filaIsEmpty(Fila *f) {
    return f->inicio == NULL;
}

void MostrarFila(Fila *f) {
    if (f) {
        No *aux = f->inicio;
        while (aux) {
            printf("%d\n ", aux->dado);
            aux = aux->proximo;
        }
    }
    printf("NULL\n");
}

int main(void) {
    Fila *f = NULL; 
    int num = 999;

    while (num != 0) {
        printf("\nMENU\n");
        printf("1 - Inicializar\n2 - Inserir\n3 - Remover\n4 - Exibir\n0 - Sair\n");
        printf("Digite o número correspondente à sua operação: ");
        scanf("%d", &num);

        if (num == 1) {
            if (f != NULL) {
                free(f);
            }
            f = filaCreate();
            printf("Fila inicializada.\n");
        } else if (num == 2) {
            if (f != NULL) {
                int valor;
                printf("Digite o valor que deseja inserir na fila: ");
                scanf("%d", &valor);
                filaInsert(f, valor);
            } else {
                printf("A fila não foi inicializada. Use a opção 1 para inicializá-la.\n");
            }
        } else if (num == 3) {
            if (f != NULL) {
                int valorRemovido = filaRemove(f);
                if (valorRemovido != -1) {
                    printf("Elemento removido: %d\n", valorRemovido);
                } else {
                    printf("Fila vazia, nenhum elemento para remover.\n");
                }
            } else {
                printf("A fila não foi inicializada. Use a opção 1 para inicializá-la.\n");
            }
        } else if (num == 4) {
            if (f != NULL) {
                MostrarFila(f);
            } else {
                printf("A fila não foi inicializada. Use a opção 1 para inicializá-la.\n");
            }
        } else if (num == 0) {
            if (f != NULL) {
                free(f);
            }
            printf("Você encerrou o programa.\n");
        } else {
            printf("Opção inválida.\n");
        }
    }


}
