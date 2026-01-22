#include <stdio.h>
#include <string.h>

char traco(int quantidade){ //Creation of the "dash" function, to make the code more organized
    for(int i = 0; i < quantidade; i++){
        printf("-");
    }
    printf("\n");
}

int main(){
    struct produtos{ //Creation of a Struct for the products
        char nome[50];
        char codigo [5];
        float preco;
        int estoque;
    };
    int op, i, totalprod = 0;
    struct produtos prod[100];

while(op != 4){
    traco(60);
    printf("[1] Cadastrar produto \n[2] Comprar produto \n[3] Listar produtos \n[4] Sair \n-> Digite a opção certa: "); //Main
    scanf("%d", &op);
    traco(60);

    switch (op) {
    case 1: { //register product
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

    case 2: { //buy product
        char verificacaocod[5];
        int qntdcomprada = 0;
        printf("Digite o código do produto que você quer comprar: ");
        scanf("%s", verificacaocod);

        for(i = 0; i < totalprod; i++){ 

            if (strcmp(verificacaocod, prod[i].codigo) == 0){ //Product code validation
                printf("Digite a quantidade para ser comprada: ");
                scanf("%d", &qntdcomprada);

                if(qntdcomprada <= prod[i].estoque){ //Checking if there is stock for purchase
                    printf("Compra de %s registrada!\n", prod[i].nome);
                    prod[i].estoque -= qntdcomprada;
                }

                else{ //Insufficient stock
                    printf("Quantidade insuficiente, temos apenas %d no estoque!\n", prod[i].estoque);
                }
        }
            else{ //Nonexistent code
                printf("O código do produto não existe!\n");
            }
    }
        break;
    }

    case 3:{ //list product
        for(i = 0; i < totalprod; i++){
            printf("%dº produto: %s\nEstoque: %d\n", (i+1), prod[i].nome, prod[i].estoque);
        }
        break;
    }
    
    case 4:{ //close
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