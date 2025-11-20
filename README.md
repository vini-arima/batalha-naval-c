🚢 Batalha Naval (C)

Projeto da disciplina PIFSI 2025.2 (CESAR School)
Professor: João Victor Tinoco

📋 Sobre o Projeto

Implementação do clássico Batalha Naval em C com interface CLI, destacando:

Alocação dinâmica de memória

Uso de structs e ponteiros

Modularização

Lógica de jogo sem bibliotecas externas

👥 Equipe
Aluno	Email	Responsabilidades
Gabriel Tenório	gtlt@cesar.school
	Interface (io), Aleatoriedade (rnd), Documentação
Vinícius Cardoso	vca4@cesar.school
	Lógica (game), Tabuleiro (board), Frota (fleet), main e Makefile
🛠️ Tecnologias

Linguagem: C (C99+)

Bibliotecas: stdio.h, stdlib.h, string.h, time.h, ctype.h, stdbool.h

Build: GNU Make

🚀 Execução
make
./batalha_naval

make clean   # opcional

🎮 Resumo do Jogo

Jogadores definem apelidos e tamanho do tabuleiro

Posicionamento da frota: manual ou automático

Turnos alternados informando coordenadas de ataque

Vence quem afundar todos os navios do oponente

⚓ Frota

1 Porta-aviões (5 células)

1 Encouraçado (4 células)

2 Cruzadores (3 células)

2 Destroyers (2 células)

🏗️ Estrutura do Código

main.c — entrada do programa

game.h/c — fluxo da partida

board.h/c — gerenciamento do tabuleiro

fleet.h/c — definição e estado dos navios

io.h/c — entrada/saída

rnd.h/c — posicionamento aleatório
