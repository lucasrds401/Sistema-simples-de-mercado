#include <stdio.h>
#include <string.h>

char traco(int quantidade){
    for(int i = 0; i < quantidade; i++){
        printf("-");
    }
    printf("\n");
}

int main(){
    struct produtos{
        char nome[50];
        char codigo [5];
        float preco;
        int estoque;
    };
    int op, i, totalprod = 0;
    struct produtos prod[100];

    while(op != 4){
    traco(60);
    printf("[1] Cadastrar produto \n[2] Comprar produto \n[3] Listar produtos \n[4] Sair \n-> Digite a opção certa: ");
    scanf("%d", &op);
    traco(60);

    switch (op) {
    case 1: {
        int qntdprod;
        printf("Digite a quantidade de produtos que você deseja cadastrar: ");
        scanf("%d", &qntdprod);
        traco(60);
        totalprod += qntdprod;

        for(i = 0; i < qntdprod; i++){
            printf("Digite o nome do %dº produto: ", i+1);
            scanf("%s", prod[i].nome);
            printf("Digite o preço do produto %s: ", prod[i].nome);
            scanf("%f", prod[i].preco);
            printf("Digite a quantidade do produto %s em estoque: ", prod[i].nome);
            scanf("%d", &prod[i].estoque);
            printf("Digite o código do produto %s: ", prod[i].nome);
            scanf("%s", prod[i].codigo);
        }
        break;
    }

    case 2: {
        char verificacaocod[5];
        int qntdcomprada = 0;
        printf("Digite o código do produto que você quer comprar: ");
        scanf("%s", verificacaocod);

        for(i = 0; i < totalprod; i++){

            if (strcmp(verificacaocod, prod[i].codigo) == 0){ 
                printf("Digite a quantidade para ser comprada: ");
                scanf("%d", &qntdcomprada);

                if(qntdcomprada <= prod[i].estoque){
                    printf("Compra de %s registrada!\n", prod[i].nome);
                    prod[i].estoque -= qntdcomprada;
                }

                else{
                    printf("Quantidade insuficiente, temos apenas %d no estoque!\n", prod[i].estoque);
                }
        }
    }

        if(qntdcomprada = 0){
            printf("O Código não existe!\n");
        }
        break;
    }

    case 3:{
        for(i = 0; i < totalprod; i++){
            printf("%dº produto: %s\nEstoque: %d\n", (i+1), prod[i].nome, prod[i].estoque);
            traco(60);
        }
        break;
    }
    
    case 4:{
        printf("Fechando o sistema...");
        break;
    }
    
    default:{
        printf("Número inválido!\n");
        break;

    }
    }
}
}