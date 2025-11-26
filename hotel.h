#ifndef HOTEL_H
#define HOTEL_H

#define NUM_QUARTOS 10

struct Hotel {
    int numero;
    int status; // 0 = livre, 1 = ocupado
    char nome_hospede[50];
};

void inicializar_hotel(struct Hotel *quartoptr);

void listar_quartos(struct Hotel *quartoptr);

void reservar_quarto(struct Hotel *quartoptr);

void liberar_quarto(struct Hotel *quartoptr);

void alterar_nome(struct Hotel *quartoptr);

void salvar_hotel(struct Hotel *quartoptr);

void carregar_hotel(struct Hotel *quartoptr);

#endif
