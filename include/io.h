#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include "board.h"
#include "fleet.h"

// tira o lixo do buffer do teclado pra o scanf não bugar
void clean_buffer();

// da aquele trato na tela, limpando tudo
void clear_screen();

// mostra o menu principal e devolve o numero que o cara escolheu
int show_main_menu();

// pergunta o vulgo (apelido) do jogador
void read_player_name(char *buffer, int max_size);

// vê qual tamanho de tabuleiro a galera quer jogar (entre 6 e 26)
int read_board_size();

// descobre se o cara quer posicionar na mao (m) ou no automatico (a)
char read_placement_mode();

// a parte chata: ler "b5" e transformar em numeros pro array
// devolve true se conseguiu ler, false se o cara digitou besteira
bool read_coordinate(int *row, int *col);

// pergunta se o barco vai ficar deitado ou em pe
Orienta read_orientation_input();

// manda uma ideia (mensagem) na tela
void print_message(const char *msg);

// segura o programa até o user apertar enter
void wait_enter();

#endif
