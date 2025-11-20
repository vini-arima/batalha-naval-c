#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "io.h"

// funcao pra limpar a sujeira que sobra no teclado
void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen() {
    // tenta limpar a tela dependendo se é windows ou linux
    // se não funcionar, paciência, mas deve ir
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int show_main_menu() {
    int option = 0;
    printf("\n=== BATALHA NAVAL ===\n"); 
    printf("1) Novo Jogo\n");
    printf("2) Sair\n"); // simplifiquei o menu pro basico
    printf("> ");
    
    // le o numero e ja limpa o buffer pra nao dar ruim dps
    scanf("%d", &option);
    clean_buffer(); 
    return option;
}

void read_player_name(char *buffer, int max_size) {
    printf("qual seu nick, jogador? "); 
    if (fgets(buffer, max_size, stdin) != NULL) {
        // remove o enter (\n) que vem junto no final da string
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int read_board_size() {
    int size = 0;
    do {
        printf("tamanho do tabuleiro (6 a 26): "); 
        scanf("%d", &size);
        clean_buffer();
        
        // validação basica, se o cara for zoeiro a gente pede de novo
        if (size < 6 || size > 26) {
            printf("po, ajuda ai! tem que ser entre 6 e 26.\n");
        }
    } while (size < 6 || size > 26);
    
    return size;
}

char read_placement_mode() {
    char mode;
    do {
        printf("quer posicionar (M)anual ou (A)utomatico? > "); 
        scanf("%c", &mode);
        clean_buffer();
        mode = toupper(mode); // deixa maiusculo pra facilitar a vida
    } while (mode != 'M' && mode != 'A');
    
    return mode;
}

bool read_coordinate(int *row, int *col) {
    char input[10];
    printf("manda a coordenada do tiro (tipo A5): "); 
    
    if (fgets(input, sizeof(input), stdin) == NULL) return false;

    // se o cara digitou só enter ou algo curto demais, ignora
    if (strlen(input) < 2) return false;

    // 1. processa a letra (coluna)
    char letter = toupper(input[0]);
    if (letter < 'A' || letter > 'Z') {
        printf("opa, essa coluna ai nao existe. usa de A a Z.\n");
        return false;
    }
    *col = letter - 'A'; // truque: 'A' - 'A' = 0, 'B' - 'A' = 1...

    // 2. processa o numero (linha)
    // o atoi pega a partir do segundo caractere da string
    int number = atoi(&input[1]); 
    
    if (number <= 0) {
        printf("linha invalida, meu parceiro.\n");
        return false;
    }
    *row = number - 1; // usuario digita 1, mas no c a gente começa do 0

    return true;
}

Orienta read_orientation_input() {
    char c;
    printf("vai colocar (H)orizontal ou (V)ertical? > ");
    scanf("%c", &c);
    clean_buffer();
    c = toupper(c);
    
    if (c == 'V') return ORIENT_V;
    // se o cara digitar qualquer outra coisa, vai horizontal mesmo
    return ORIENT_H; 
}

void print_message(const char *msg) {
    // só pra imprimir uma linha bonitinha
    printf("%s\n", msg);
}

void wait_enter() {
    printf("\naperta ENTER pra continuar...");
    getchar(); // fica travado aqui esperando o enter
}
