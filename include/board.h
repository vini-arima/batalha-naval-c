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
Board* create_board(int rows , int cols) ; // Retorna o ponteiro Board diretamente
void initialize_board(Board *board);
void destroy_board(Board *board) ; 
bool valid_position(Board *board , int cols , int rows) ; 
#endif