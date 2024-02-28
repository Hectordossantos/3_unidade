#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct lista {
    No *cabeca;
} Lista;

void InicializarLista(Lista *lista) {
    lista->cabeca = (No *)malloc(sizeof(No));
    lista->cabeca->proximo = NULL;
}

void InserirElemento(Lista *lista, int x, int y) {
    No *p = lista->cabeca;
    No *q = p->proximo;

    No *novono = (No *)malloc(sizeof(No));
    novono->dado = x;

    while (q != NULL && q->dado != y) {
        p = q;
        q = q->proximo;
    }

    novono->proximo = q;
    p->proximo = novono;
}

void RemoverElemento(Lista *lista, int x) {
    No *p = lista->cabeca;
    No *q = p->proximo;

    while (q != NULL && q->dado != x) {
        p = q;
        q = q->proximo;
    }

    if (q != NULL) {  
        p->proximo = q->proximo;
        free(q);
    }
}

No *BuscarElemento(Lista *lista, int x) {
    No *p = lista->cabeca->proximo; 

    while (p != NULL && p->dado != x) {
        p = p->proximo;
    }

    return p;
}

void ExibirLista(Lista *lista) {
    No *p = lista->cabeca->proximo;  

    while (p != NULL) {
        printf("%d\n ", p->dado);
        p = p->proximo;
    }
}

int main(void) {
    Lista lista;
    int num = 999;

    while (num != 0) {
        printf("\nMENU\n");
        printf("1 - Inicializar\n2 - Inserir\n3 - Remover\n4 - Buscar\n5 - Exibir\n0 - Sair\n");
        printf("Digite o número correspondente à sua operação: ");
        scanf("%d", &num);

        if (num == 1) {
            InicializarLista(&lista);  

        } else if (num == 2) {
            int x;
            int y;
            printf("Digite o elemento que deseja inserir:\n ");
            scanf("%d", &x);
            printf("Digite o valor de referência y:\n ");
            scanf("%d", &y);
            InserirElemento(&lista, x, y);

        } else if (num == 3) {
            int x;
            printf("Digite o elemento que deseja remover:\n ");
            scanf("%d", &x);
            RemoverElemento(&lista, x);

        } else if (num == 4) {
            int x;
            printf("Digite o elemento que deseja buscar:\n ");
            scanf("%d", &x);
            No *resultado = BuscarElemento(&lista, x);
            if (resultado) {
                printf("Elemento encontrado: %d\n", resultado->dado);
            } else {
                printf("Elemento não encontrado.\n");
            }

        } else if (num == 5) {
            ExibirLista(&lista);

        } else if (num == 0) {
            printf("\nVocê encerrou o programa!\n");
        } else {
            printf("Opção inválida\n");
        }
    }

    No *p = lista.cabeca->proximo;
    while (p != NULL) {
        No *temp = p;
        p = p->proximo;
        free(temp);
    }

    free(lista.cabeca);

}
