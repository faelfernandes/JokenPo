#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int player_win = 0, cpu_win = 0;
int escolha, cpu, player;
int Continuar;

void inicializar(){
    printf ("\n");

    printf ("       __    ______    __  ___  _______  __   __   ______     ______   \n");
    printf ("      |  |  /  __  \\  |  |/  / |   ____||  \\ |  | |   _  \\   /  __  \\  \n");
    printf ("      |  | |  |  |  | |  '  /  |  |__   |   \\|  | |  |_)  | |  |  |  | \n");
    printf (".--.  |  | |  |  |  | |    <   |   __|  |  . `  | |   ___/  |  |  |  | \n");
    printf ("|  `--'  | |  `--'  | |  .  \\  |  |____ |  |\\   | |  |      |  `--'  | \n");
    printf (" \\______/   \\______/  |__|\\__\\ |_______||__| \\__| | _|       \\______/  \n");
    printf ("                                                  by: Rafael Fernandes \n");
}

void placar(){
    printf ("\n");
    printf (" #-------- PLACAR --------#\n");
    printf (" #   %d Jogador X CPU %d    #\n", player_win, cpu_win);
    printf (" #------------------------#\n");
}

void game(){

    placar();
    printf ("\n");
    printf (" Escolha uma jogada:\n");
    printf ("\n");
    cout << " 0. Pedra" << "\n";
    cout << " 1. Papel" << "\n";
    cout << " 2. Tesoura" << "\n";
    cout << " 3. Sair" << "\n";

    srand(time(NULL));
    cpu = rand() % 3;

    printf ("\n");
    cin >> player;
    printf ("\n");

    if (player < 0 || player >= 3){
        exit(0);
    }

    switch(player){
        case 0: printf (" -> Voce escolheu Pedra\n");
        break;
        case 1: printf (" -> Voce escolheu Papel\n");
        break;
        case 2: printf (" -> Voce escolheu Tesoura\n");
        break;
    }
    switch(cpu){
        case 0: printf (" -> CPU escolheu Pedra\n");
        break;
        case 1: printf (" -> CPU escolheu Papel\n");
        break;
        case 2: printf (" -> CPU escolheu Tesoura\n");
        break;
    }


    if ((player == 0 && cpu == 2) || (player == 1 && cpu == 0) || (player == 2 && cpu == 1)){
        printf (" \n #----------- Voce ganhou! ----------#\n");
        player_win++;
    }else if (player == cpu){
        printf (" \n #---------- Houve um empate! ----------#\n");
    }else {
        printf (" \n #---------- Voce perdeu! ----------#\n");
        cpu_win++;
    }
}

int main(){
    inicializar();
    game();

    int newgame;
    while (newgame != 1)
    {
        cout<<"\n Deseja jogar novamente?\n ";
        cout<<"\n 0. Sim";
        cout<<"\n 1. Nao \n";
        cin>>newgame;
        system("cls");
        if(newgame == 0){
               inicializar();
               game();
        }else{
            inicializar();
            placar();

            if (player_win > cpu_win){
                printf (" \n Parabens, voce saiu vitorioso.\n");
            }else if (player_win == cpu_win){
                printf (" \n Oh nao, parece que ficaram empatados.\n");
            }else {
                printf (" \n Que pena, voce saiu como um perdedor.\n");
            }
        }
    }
}
