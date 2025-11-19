#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fleet.h"

typedef struct {
    Player p1, p2;
    int current_player;
    int game_over;
} Game;

typedef struct {
    Board board;
    Board shots;
    Fleet fleet;
    char nickname[40];
 } Player;



void create_game(); // Inicializa jogo 
void destroy_game(); //Libera a memoria 
void game_switch_turn() ; // Alterna o turno entre os jogadores
void game_shoot(); // Realiza um disparo em uma coordenada
void game_is_over() ; // Verifica se o jogo acabou
void game_place_ship() ; // Posiciona um navio no tabuleiro do jogador atual
void game_auto_place_ship() ; // Posiciona todos os navios automaticamente
