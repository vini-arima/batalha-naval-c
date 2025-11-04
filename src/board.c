// Estutura do Tabuleiro 
#include <stdio.h> 
#include <stdlib.h>
#include "board.h"

// CRIAR TABULEIRO - REQUISITO 1
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
   
//
    



