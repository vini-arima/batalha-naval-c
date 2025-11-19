#ifndef FLEET_H
#define FLEET_H 

typedef enum {ORIENT_H , ORIENT_V} Orienta ; 

typedef struct {
    char name[20]; // NOME
    int length; // TAMANHO
    int hits; // ACERTO
    int placed; // POSICAO
    bool sunk ; // STATUS DE AFUNDA OU NÃO 
} Ship ;

typedef struct{
    Ship *ships ; 
    int count ; 
} Fleet ;

typedef enum {
    SHIP_CARRIER,      // Porta-aviões (5 células)
    SHIP_BATTLESHIP,   // Encouraçado (4 células)
    SHIP_CRUISER,      // Cruzador (3 células)
    SHIP_DESTROYER     // Destroyer (2 células)
} ShipType

// Funções 

void inicialize_fleet() ; 
int place_ship() ;
bool check_ship() ;
void check_all_ship() ; 
void free_ship() ;

#endif

