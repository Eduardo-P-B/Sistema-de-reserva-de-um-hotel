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
