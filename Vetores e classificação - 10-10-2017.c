#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int op, n, i, j, direita, esquerda, achou, meio, AUX, nr;
int vetor[100];

void inserir(){
    printf("Quantos numeros voce deseja inserir?\n");
    scanf("%d",&n);

    for(i = 1; i <= n;i++) {
        printf("Numero %d: ",i);
        fflush(stdin);
        scanf("%d",&vetor[i]);
    }
}

void classificar(){
    for (i = 1; i <= n; i++){
        for (j = 1; j < n; j++){
            if (vetor[j] > vetor[j+1]){
                AUX = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = AUX;
            }
        }
    }
}

void pesq_binaria(){
    printf("===================================================\n");
    direita = n;
    esquerda = 0;
    meio = 0;
    achou = 0;

    printf("Informe o codigo a ser procurado: ");
    scanf("%d",&nr);

    while(esquerda <= direita && achou == 0){
        meio = esquerda + ((direita - esquerda) / 2);

        if (vetor[meio] < nr){
            esquerda = meio+1;
        }
        else if (vetor[meio] > nr){
            direita = meio - 1;
        }
        else {
            achou = 1;
        }
    }

    if (achou == 0){
        printf("O elemento nao foi encontrado!\n");
    }
    else {
        printf("O elemento foi encontrado na posicao: %d\n",meio);
    }
    system("pause");
}

void pesq_seq(){
    int num, i, encontrado = 0;
    printf("informe o numero que voce deseja pesquisar: ");
    scanf("%d", &num);

    for (i = 1; i <= n; i++){
        if (num == vetor[i]){
            printf("Encontrado na posicao: %d\n\n",i);
            encontrado = 1;
        }
    }
    if (encontrado == 0){
        printf("Numero nao encontrado\n\n");
    }
    system("pause");
}

void exibir(){
    for (i = 1; i <= n; i++){
        fflush(stdin);
        printf("%d\n",vetor[i]);
    }
    system("pause");
}

int sair(){
    return 0;
}

int main(){
    int op;
    do{
        system("cls");
        printf("-------- Menu de opcoes --------\n");
        printf("[1] Inserir\n");
        printf("[2] Classificar\n");
        printf("[3] Pesquisa binaria\n");
        printf("[4] Pesquisa sequencial\n");
        printf("[5] Exibir todos os dados\n");
        printf("[0] Sair\n\n");

        printf("Informe a opcao: ");
        scanf("%d",&op);

        switch (op){
            case 1:
                    inserir();
                    break;
            case 2:
                    classificar();
                    break;
            case 3:
                    pesq_binaria();
                    break;
            case 4:
                    pesq_seq();
                    break;
            case 5:
                    exibir();
                    break;
            case 0:
                    sair();
                    break;
            default:
                    printf("Valor digitado nao e valido");
                    break;
        }
    } while(op != 0);
}
