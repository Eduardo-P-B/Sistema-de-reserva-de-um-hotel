#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"

int main()
{
    struct Hotel quartos[NUM_QUARTOS];
    int escolha=0;
    inicializar_hotel(quartos);
    while(escolha != 7)
    {
        printf("O Que fazer?");
        printf("\n1- Listar Quartos");
        printf("\n2- Reservar Quarto");
        printf("\n3- Liberar Quarto");
        printf("\n4- Alterar Nome do Hospede");
        printf("\n5- Salvar Hotel");
        printf("\n6- Carregar Hotel");
        printf("\n7- Desligar Programa\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            listar_quartos(quartos);
            break;
        case 2:
            reservar_quarto(quartos);
            break;
        case 3:
            liberar_quarto(quartos);
            break;
        case 4:
            alterar_nome(quartos);
            break;
        case 5:
            salvar_hotel(quartos);
            break;
            case 6:
            carregar_hotel(quartos);
            break;
        case 7:
            printf("Desligando Programa!\n");
            break;
        default:
            printf("Numero Invalido\n");
            break;
        }
    }
    return 0;
}
