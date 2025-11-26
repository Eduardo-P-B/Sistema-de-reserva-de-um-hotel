#include <stdio.h>
#include "hotel.h"

void inicializar_hotel(struct Hotel *quartoptr){
    for(int i = 0; i < NUM_QUARTOS; i++)
    {
        quartoptr[i].numero = i+1;
        quartoptr[i].status = 0;
        strcpy(quartoptr[i].nome_hospede, " ");
    }
}

void listar_quartos(struct Hotel *quartoptr)
{
    for(int i=0; i < NUM_QUARTOS; i++)
    {
        printf("Quarto %d: ", i+1);
        if(quartoptr[i].status==0)
        {
            printf("Livre\n");
        }
        else
        {
            printf("Ocupado por: %s\n", quartoptr[i].nome_hospede);
        }
    }
}

void reservar_quarto(struct Hotel *quartoptr)
{
    int numero=0;
    printf("Digite o numero do quarto que deseja reservar: ");
    scanf("%d", &numero);
    if (numero < 11 && numero > 0)
    {
        if (quartoptr[numero-1].status == 0)
        {
            quartoptr[numero-1].status = 1;
            printf("Digite seu nome: ");
            scanf(" %49[^\n]", quartoptr[numero-1].nome_hospede);
            printf("Quarto Reservado!\n");
        }
        else
        {
            printf("O quarto %d ja esta reservado\n", numero);
        }
    }
    else
    {
        printf("Numero Invalido!\n");
    }
}

void liberar_quarto(struct Hotel *quartoptr)
{
    int numero;
    printf("Digite o quarto que deseja liberar: ");
    scanf("%d", &numero);
    if(numero < 11 && numero > 0)
    {
        numero=numero-1;
        if(quartoptr[numero].status == 1)
        {
            quartoptr[numero].status=0;
            strcpy(quartoptr[numero].nome_hospede, " ");
            printf("Quarto %d liberado com sucesso!\n", numero+1);
        }
        else
        {
            printf("O quarto %d ja esta vazio!\n", numero+1);
        }
    }
    else
    {
        printf("Numero Invalido!\n");
    }

}

void alterar_nome(struct Hotel *quartoptr)
{
    int numero;
    printf("Digite o numero do quarto que tera o nome do hospede alterado: ");
    scanf("%d", &numero);
    if(numero > 0 && numero < 11)
    {
        if (quartoptr[numero-1].status == 1)
        {
            numero=numero-1;
            printf("Digite o nome alterado: ");
            scanf(" %49[^\n]", quartoptr[numero].nome_hospede);
            printf("Nome alterado com sucesso!\n");
        }
        else
        {
            printf("O quarto %d esta vazio!\n", numero);
        }
    }
    else
    {
        printf("Numero Invalido!\n");
    }
};

void salvar_hotel(struct Hotel *quartoptr)
{
    FILE *numeros = fopen("hotel.txt", "w");
    FILE *hospedes = fopen("hospedes.txt", "w");
    for(int i=0; i<10; i++)
    {
            fprintf(numeros, "%d\n", quartoptr[i].status);
            fprintf(hospedes, "%s\n", quartoptr[i].nome_hospede);
    }
    fclose(numeros);
    fclose(hospedes);
    printf("Hotel Salvo!\n");
}

void carregar_hotel(struct Hotel *quartoptr)
{
    int numero=0;
    FILE *hotel = fopen("hotel.txt", "r");
    FILE *hospedes = fopen("hospedes.txt", "r");
    while (fgets(quartoptr[numero].nome_hospede, 50, hospedes) != NULL)
    {
        quartoptr[numero].nome_hospede[strcspn(quartoptr[numero].nome_hospede, "\n")] = '\0';
        numero=numero+1;
    }
    numero=0;
    while (fscanf(hotel, "%d", &quartoptr[numero].status) == 1) {
        numero=numero+1;
    }
    printf("Hotel Carregado!\n");
}

