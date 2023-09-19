#include <stdio.h>
#include <stdbool.h>
#define QTD 5

//Criar um sistema de cadastro de terrenos, o sistema devera ser criado para cadastrar os m2 de terrenos de clientes,
//pegando apenas a largura e altura do terreno. O sistema deverá usar structs para criar variaveis e devera ter um menu
// com as seguintes funções:
//- cadastrar novo terreno
//- listar terrenos cadastrados
//- calcular area do terreno
//- calcular perimetro do terreno
//- precifica terreno (o cálculo terá como base no valor de 320,00 reais o m2)
//- especificaçoes do terreno (todos os dados cadastrados do terreno)


typedef struct{
    float altura;
    float largura;
    float perimetro;
    float area;
    float preco;
}str;

int menu(){

    int m = 0;
    printf("\n");
    printf("\n-------MENU-------");
    printf("\n0 - Sair");
    printf("\n1 - Cadastrar novo terreno");
    printf("\n2 - Listar terrenos cadastrados");
    printf("\n3 - Calcular area de terreno");
    printf("\n4 - Calcular perimetro do terreno");
    printf("\n5 - Precificar terreno");
    printf("\n6 - Detalhes do terreno");
    printf("\n: ");
    scanf("%d", &m);

    return m;
}

str terrenos[QTD];

str terreno(float alt, float lar)
{
    str novo;

    novo.altura = alt;
    novo.largura = lar;
    novo.area = 0;
    novo.perimetro = 0;
    novo.preco = 0;

    return novo;
}


void criaTerreno()
{
    float alt, lar = 0;
    int cont = 0;

    printf("\nDigite a altura do terreno em Metros(m): ");
    scanf("%f", &alt);

    printf("\nDigite a largura do terreno em Metros(m): ");
    scanf("%f", &lar);

    for(int i=0; i<QTD; i++){
        if(terrenos[i].altura == 0 && terrenos[i].largura == 0){
            terrenos[i] = terreno(alt, lar);
            cont++;
            break;
        }
    }

    if(cont == 1){
        printf("\nTerreno cadastrado com sucesso!");
    }else{
        printf("\nErro de Cadastro! Espaco insuficiente.");
    }
}


void listaTerrenos()
{
    for(int i=0; i<QTD; i++){
        if(terrenos[i].altura != 0 && terrenos[i].largura != 0){
            printf("\n%d - Terreno Cadastrado", i);
        }else{
            printf("\n%d - Terreno Nao Cadastrado", i);
        }
    }
}


void calculaArea(str *lista, int num)
{
    int escolha = 0;

    for(int i=0; i<num; i++){
        if(terrenos[i].altura != 0 && terrenos[i].largura != 0){
            printf("\n%d - Terreno Cadastrado", i);
        }else{
            printf("\n%d - Terreno Nao Cadastrado", i);
        }
    }

    printf("\nDigite o indice do terreno para calcular a area: ");
    scanf("%d", &escolha);

    lista[escolha].area = lista[escolha].largura * lista[escolha].altura;

    printf("\nO terreno tem %.2f m2", lista[escolha].area);
}


void calculaPerimetro(str *lista, int num)
{
    int escolha = 0;

    for(int i=0; i<num; i++){
        if(terrenos[i].altura != 0 && terrenos[i].largura != 0){
            printf("\n%d - Terreno Cadastrado", i);
        }else{
            printf("\n%d - Terreno Nao Cadastrado", i);
        }
    }

    printf("\nDigite o indice do terreno para calcular o perimetro: ");
    scanf("%d", &escolha);

    lista[escolha].perimetro = (lista[escolha].largura*2) + (lista[escolha].altura*2);

    printf("\nO terreno tem %.2f metros de perimetro", lista[escolha].perimetro);
}


void precificaTerreno(str *lista, int num)
{
    int escolha = 0;

    for(int i=0; i<num; i++){
        if(terrenos[i].altura != 0 && terrenos[i].largura != 0){
            printf("\n%d - Terreno Cadastrado", i);
        }else{
            printf("\n%d - Terreno Nao Cadastrado", i);
        }
    }

    printf("\nDigite o indice do terreno para calcular o preco: ");
    scanf("%d", &escolha);

    lista[escolha].preco = lista[escolha].area * 320;

    printf("\nO terreno custa R$ %.2f", lista[escolha].preco);
}

void caracTerreno(str* lista, int num)
{
    int escolha = 0;

    for(int i=0; i<num; i++){
        if(terrenos[i].altura != 0 && terrenos[i].largura != 0){
            printf("\n%d - Terreno Cadastrado", i);
        }else{
            printf("\n%d - Terreno Nao Cadastrado", i);
        }
    }

    printf("\nDigite o indice do terreno para ver os detalhes: ");
    scanf("%d", &escolha);

    printf("\nTerreno de %.2f(A) x %.2f(L) com %.2f(m2) com perimetro de %.2f metros. Custo de R$ %.2f", lista[escolha].altura, lista[escolha].largura, lista[escolha].area, lista[escolha].perimetro, lista[escolha].preco);
}

int main() {

    bool loop = true;
    int esc = 0;

    while(loop == true){

       esc = menu();

        switch(esc){

            case 0:
                loop = false;
                break;

            case 1:
                criaTerreno();
                break;

            case 2:
                listaTerrenos();
                break;

            case 3:
                calculaArea(terrenos, QTD);
                break;

            case 4:
                calculaPerimetro(terrenos, QTD);
                break;

            case 5:
                precificaTerreno(terrenos, QTD);
                break;

            case 6:
                caracTerreno(terrenos,QTD);
                break;

            default:
                printf("Opcao invalida");
        }
    }


    return 0;
}
