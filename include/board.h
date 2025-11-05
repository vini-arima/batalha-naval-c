#ifndef BOARD_H  
#define BOARD_H  

typedef enum { 
    CELL_WATER,     // 0 - Água
    CELL_SHIP,      // 1 - Navio
    CELL_HIT,       // 2 - Acertado
    CELL_MISS       // 3 - Água com tiro
} CellState;

typedef struct {
    CellState state;
    int ship_id;    
} Cell;

typedef struct {
    int rows, cols;
    Cell *cells;    
} Board;

//Funções 
Board* create_board(int rows , int cols) ; // CRIA O TABULEIRO
void initialize_board(Board *board); // INICIALIZA O TABULEIRO 
void destroy_board(Board *board) ; // DESTROI O TABULEIRO
bool valid_position(Board *board , int cols , int rows) ; // VALIDA A POSICAO 
void display_board(Board , bool show_ships);  // MOSTRA O TABULEIRO 
void get_Cell() // PEGA A CELULAR
#endif