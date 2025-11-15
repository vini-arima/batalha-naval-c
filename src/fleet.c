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
    for (int i = 0 ; i < ship -> legth ; i++){
        
    }

}