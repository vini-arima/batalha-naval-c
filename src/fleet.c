#include "fleet.h" 
#include "board.h"
#include <stdlib.h> 

//REQUISITO 1 - INICIALIZAR FROTA
void inicialize_fleet(Fleet *fleet){

    fleet -> count = 6 ; 
    fleet -> ships ; 

    Ship ships = malloc(fleet -> count * sizeof(Ship)); 

    // FROTA DE NAVIOS


} 

int place_ship(Board *board , Fleet *fleet , int row , int col , Orienta orient){
    // Verificar se a posição e valida 
    if (row < 0 && row < board -> rows ){
        return 0; 
    }
    if(col < 0 && col < board -> cols){
        return 0 ;
    }
        
    //Verificar se o navio cabe na posicao
    if(orient == ORIENT_H){
        if (col + ship -> length > board -> cols){
            return 0 ;
        } 
        else{
            if (row + ship -> length > board -> rows){
                return 0 ; 
            }
        }
    }

    //Verificar sobreposicao navios 
    for (int i = 0 ; i < ship -> length ; i++){
        int r = row ; 
        int c = col ; 

        if (orient == ORIENT_H){
            c = col + i ;
        }
        else {
            r = row + i ; 
        }

        Cell *cell = &board->cells[r * board->cols + c];
        if (cell->state == CELL_SHIP) {
            return 0; // Já tem navio aqui
        }

    }

    // Colocar navios no tabuleiro 
    for(int i = 0 ; i < ship -> length ; i++){
        int r = row ; 
        int c = col ; 

        if (orient == ORIENT_H){
            c = col + i ;
        }
        else {
            r = row + i ; 
        }

        Cell *cell = &board->cells[r * board->cols + c];
        cell->state = CELL_SHIP;
        cell->ship_id = ship - board->fleet.ships;

        ship->placed = 1;
        return 1;
    }

    bool check_ship(Fleet *fleet , int ship_index ){ 

        if (ship_index < 0 || ship_index >= fleet->ship_count) {
            printf("Erro: Índice de navio inválido!\n");
            return false;
        }

        // Verifica se o navio já foi marcado como afundado anteriormente
        if (ship -> sunk ){
            return 1 ;
        }
        
         // Verifica se o número de acertos é igual ao tamanho do navio
        if (ship->hits >= ship->size) {
            printf("Você afundou meu %s!\n", ship->name);
            return 1;
        }

        return 0;
        
    }
}

