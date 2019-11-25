#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct no {
    char nome[30];
    char telefone[15];
    struct no* prox;
};

struct no *incluirInicio(struct no *L) {
    setlocale(LC_ALL, "Portuguese");
    struct no *p;
    p = (struct no*) malloc(sizeof(struct no));
    system("cls");
    printf("Incluir no Inicio: \n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(p->nome);
    printf("Digite o telefone: ");
    gets(p->telefone);
    p->prox = L;
    L = p;
    return L;

}//Fim incluirInicio().
struct no *incluirFinal(struct no *L) {
    setlocale(LC_ALL, "Portuguese");
    struct no *p, *q;
    p = (struct no *) malloc(sizeof(struct no));
    system("cls");
    printf("Incluir no final\n");
    printf("\nDigite o nome: ");
    fflush(stdin);
    gets(p->nome);
    printf("Digite o telefone: ");
    fflush(stdin);
    gets(p->telefone);
    p->prox = NULL;

    if (L == NULL) { // se L é vazio.
        return p; //não havia nó, e este será o primeiro da lista.
    } else {//procura o ultimo nó
        q = L; // q apontara para o primeiro nó
        while (q->prox != NULL) {
            q = q->prox;
        }
        q->prox = p;
        system("cls");
        printf("\n%s - %s, cadastrado com sucesso!\n", p->nome, p->telefone);
        system("pause");
        return L;
    }
}

void *exibirLista(struct no *L) {
    setlocale(LC_ALL, "Portuguese");
    struct no *p;

    printf("Lista Atendentes -> ");
    if (L == NULL) {
        printf("Vazia!\n");
    } else {
        p = L;
        while (p != NULL) {
            printf("\n                 Nome: %s , Telefone: %s", p->nome, p->telefone);
            p = p->prox;
        }
    }
    printf("\n");
    system("pause");
    system("cls");

}//Fim exibirLista()


int main() {
    setlocale(LC_ALL, "Portuguese");

    char nome[30], tel[30];

    struct no *Lista;//Lista de atendentes
    Lista = NULL; // inicializa a lista

    int opc;
    do {
        printf("\n LISTA DO ATENDE-AQUI. \n");
        printf("\n 1) Incluir atendente no início da lista. ");
        printf("\n 2) Incluir atendente no final da lista. \n");
        printf("\n 3) Exibir atendentes cadastrados. ");
        printf("\n 0) Sair. \n");
        printf("\n Opção->  ");
        fflush(stdin);
        scanf("%i", &opc);

        switch (opc) {
        case 1 :
            Lista = incluirInicio(Lista);
            system("cls");
            printf("\n%s - %s, cadastrado com sucesso!\n", Lista->nome, Lista->telefone);
            break;
        case 2:
            Lista = incluirFinal(Lista);
            system("cls");
            break;
        case 3:
            system("cls");
            exibirLista(Lista);
            break;
        }//fim switch
    } while (opc != 0);


}
