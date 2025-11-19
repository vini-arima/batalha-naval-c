#include "game.h"
#include "rnd.h"
#include <stdlib.h>
#include <string.h>

Game* create_game(int board_size , const char p1_name , const char p2_name){
        Game* game = malloc(sizeof(Game)) ;

        game->p1 = player_create(p1_name, board_size);
        game->p2 = player_create(p2_name, board_size);

        game -> current_player = 1; 
        game -> game_over = 0;

        return game;

}

void destroy_game(Game *game){
        if(game){
             player_destroy(&game->p1);
             player_destroy(&game->p2);
             free(game);    
        }
}

void game_switch_turn(Game* game) {
        if(game -> current_player == 1){
           game->current_player = 2;
        }
        else{
           game->current_player = 1;
        }
} 

void game_shoot(){
        void* current = game_get_current_player(game) ;
        void* opponent = game_get_opponent(game);

        Cell* cell = &opponent->board.cells[row * opponent->board.cols + col];

        // Verifica se o tiro é válido
        if (row < 0 || row >= opponent->board.rows || col < 0 || col >= opponent->board.cols) {
            return -1; // Tiro inválido
        } 

        // Verifica se já atirou aqui
        if (cell->state == CELL_HIT || cell->state == CELL_MISS) {
                return -2; // Já atirou aqui
        }
        
        // Processa o tiro
        if (cell->state == CELL_SHIP) {
                cell->state = CELL_HIT;
    
        // Busca direta pelo navio na frota
        for (int i = 0; i < opponent->fleet.ship_count; i++) {
                if (opponent->fleet.ships[i].id == cell->ship_id) {
                        opponent->fleet.ships[i].hits_received++;
                        break;
                }
        }
        return 1;
}

}


int game_is_over(Game* game) {
      void* current = game_get_current_player(game) ;
      void* opponent = game_get_opponent(game);
    // Verifica se a frota do oponente foi completamente destruída
      for (int i = 0; i < opponent->fleet.count; i++) {
         if (opponent->fleet.ships[i].hits < opponent->fleet.ships[i].length) {
            return 0; // Ainda há navios não afundados
         }
    }
    
    game->game_over = 1;
    return 1; // Jogo terminou
}

void game_place_ship(){
        
} 

void game_auto_place_ship(){
        
}