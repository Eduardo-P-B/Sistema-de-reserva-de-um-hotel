#ifndef HOTEL_H
#define HOTEL_H

#define NUM_QUARTOS 10

struct Hotel {
    int numero;
    int status; // 0 = livre, 1 = ocupado
    char nome_hospede[50];
};

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
