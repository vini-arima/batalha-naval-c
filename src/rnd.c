#include <stdlib.h>
#include <time.h>
#include "rnd.h"

void setup_random() {
    // pega a hora atual pra garantir que cada jogo seja unico
    // sem isso o pc joga sempre igual, maior paia
    srand((unsigned int)time(NULL));
}

int get_random_number(int min, int max) {
    // matemágica pra pegar um numero dentro do intervalo q a gente quer
    return min + (rand() % (max - min + 1));
}

Orienta get_random_orientation() {
    // gera 0 ou 1. se der 0 é horizontal, se der 1 é vertical. simples assim.
    int val = rand() % 2;
    if (val == 0) {
        return ORIENT_H;
    } else {
        return ORIENT_V;
    }
}
