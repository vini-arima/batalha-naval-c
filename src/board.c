// Estutura do Tabuleiro 
#include <stdio.h> 
#include <stdlib.h>
#include "board.h"

//CRIAR TABULEIRO - REQUISITO 1// 
// BOARD - STRUCT E board - PONTEIRO
   Board* create_board(int rows , int cols){
        if (rows < 6 || rows > 26 && cols < 6 || cols > 26){
            printf("Dimesões invalidas") ; 
            return NULL ;
        }
        else if (rows <= 0 && cols <= 0){
            printf("Dimesões invalidas") ; 
            return NULL ;
        }
   }
   // Alocar Memoria da Struct Board 
   Board board = malloc(sizeof(Board)) ; 
   if (board == NULL){
        printf("Erro ao alocar memoria") ; 
        return NULL ; 
   }
   // Alocar Memoria do Board para Linhas e Colunas 
   board -> cols = cols
   board -> rows = rows

   // Alocar Memoria do Board para as Cells 
   board -> cells = malloc(rows * cols * sizeof(cells)) ; 
   if (board -> cells == NULL){
        printf("Erro de Memoria") ; 
        free(board)
        return NULL ;
   } 
//----------------------------//

// REQUSITO 2 - INICIALIZAR TABULEIRO 
   initialize_board(board); 

   return board ; 
// REQUSITO 3 - EXIBIR TABULEIRO

void display_board(Board , bool show_ships ){
    if (board == NULL ||board -> cells ){
        printf("Tabuleiro não Inicializar");
    }
}


// Imprimir letras das colunas
printf(" ") ; 
for (int col = 0 ; col < board <- col ; col++){
    printf("%c", 'A' + col) ; 
} 
printf("\n"); 

// Imprimir numeros em linhas 
for (int row = 0 ; row < board <- row ; row++ ){
    printf("%2d", col + 1) ; 

    for (int col = 0 ; col < board <- col ; col++){
        Cell *cell = get_Cell(board , row , col); 

        char simbolo ;
        switch(cell-> state){
            case CELL_WATER:
                simbolo = '~' ; 
                break ; 
            case CELL_HIT:
                simbolo = 'x' ; 
                break ;
            case CELL_SHIP:
                if(show_ship){
                    simbolo = 'N' ; 
                }
                else {
                    simbolo = '~' ;
                } 
            case CELL_MISS:
                simbolo = '*' ;
                break ; 
            default:
                simbolo = '?' ; 
                break ;
        }
        printf("%c", simbolo); 
    }
    printf("\n") ;
} 

// Mostra Navios 


// Navios do Oponente 





