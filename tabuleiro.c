#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define linha 60
#define coluna 120
#define VERMELHO   "\e[0;31m"
#define VERDE "\e[0;32m"
#define AMARELO "\e[0;33m"
#define AZUL "\e[0;34m"


char V[linha][coluna];
char MENU[30][30];
char MANUAL[100][50];
char j1[10], j2[10], j3[10], j4[10];
int fim_jogo = 0;
int r1, r2, r3, r4, y1, y2, y3, y4, b1, b2, b3, b4, g1, g2, g3, g4;
r1 = 0;
r2 = 0;
r3 = 0;
r4 = 0;
y1 = 0;
y2 = 0;
y3 = 0;
y4 = 0;
b1 = 0;
b2 = 0;
b3 = 0;
b4 = 0;
g1 = 0;
g2 = 0;
g3 = 0;
g4 = 0;


void apagar_log() {
    int i, j;

    for (j= 31; j <= linha - 3; j++) {
    for (i= 81; i<= 117; i++) {
        V[j][i] = ' ';
    }
    }
}

void escrever_string(char string[], int line, int column) {
    int i, j, tamanho;

    tamanho = strlen(string) - 1;

    for (i = column, j= 0; i <= column + tamanho; i++, j++) {
        V[line][i] = string[j];
    }

}

void escrever_string_menu(char string[], int line, int column) {
    int i, j, tamanho;

    tamanho = strlen(string) - 1;

    for (i = column, j= 0; i <= column + tamanho; i++, j++) {
        MENU[line][i] = string[j];
    }

}

void escrever_string_instrucoes(char string[], int line, int column) {
    int i, j, tamanho;

    tamanho = strlen(string) - 1;

    for (i = column, j= 0; i <= column + tamanho; i++, j++) {
        MANUAL[line][i] = string[j];
    }

}

void zerar_dados () {
     int i, j;

     for (j = 6; j<=8; j++) {
         for (i = 97; i<= 101; i++) {
             V[j][i] = ' ';
         }
     }
}

int jogar_dado1() {
    int n_random;
    zerar_dados();

    srand(time(NULL));
    n_random = rand()%6+1;


    switch (n_random) {
        case 1:
            V[7][99] = '#';
            break;
        case 2:
            V[6][97] = '#';
            V[8][101] = '#';
            break;
        case 3:
            V[6][97] = '#';
            V[8][101] = '#';
            V[7][99] = '#';
            break;
        case 4:
            V[6][97] = '#';
            V[8][101] = '#';
            V[8][97] = '#';
            V[6][101] = '#';
            break;
        case 5:
            V[6][97] = '#';
            V[8][101] = '#';
            V[8][97] = '#';
            V[6][101] = '#';
            V[7][99] = '#';
            break;
        case 6:
            V[6][97] = '#';
            V[8][101] = '#';
            V[8][97] = '#';
            V[6][101] = '#';
            V[7][97] = '#';
            V[7][101] = '#';
            break;
}

    return n_random;
}

void desenhar_dado () {
    int i, j;

    for (j= 5; j <= 9; j++) {
        for (i= 95; i<= 103 ; i++) {
            if (j == 5 || j==9) {
                V[j][i] = '-';
            } else if (i == 95 || i == 103) {
                    V[j][i] = '|';}
            }
    }

}

void quadrado_final() {
    int i, j;

    for (j= 10; j<= 59; j++) {
        V[47][j] = '-';
        V[54][j] = '-';
    }
    for (j= 48; j <= 53; j++) {
        V[j][10] = '|';
        V[j][59] = '|';
    }

    for (i=22; i<= 48; i = i+12){
    for (j=48; j<= 53; j++) {
        V[j][i] = '|';
    }}

    for (j = 49; j<= 52; j++ ){
        escrever_string("__", j, 15);
        escrever_string("__", j, 27);
        escrever_string("__", j, 38);
        escrever_string("__", j, 50);
    }

    escrever_string("RED", 48, 15);
    escrever_string("BLUE", 48, 27);
    escrever_string("GREEN", 48, 38);
    escrever_string("YELLOW", 48, 50);
}

void casas_verticais(int line , int column) {
    int j;

    for (j = line; j <= line + 40; j= j+3){
            V[j][column +2] = '-';
            V[j][column + 3] = '-';
            V[j+1][column +1] = '|';
            V[j+1][column +4] = '|';
            V[j+2][column +2] = '-';
            V[j+2][column +3] = '-';

}}

void casas_especiais() {

    if (V[5][11] == ' ' || V[23][11] == ' ' || V[44][11] == ' ') {
        V[5][11] = '*';
        V[5][12] = '*';
        V[23][11] = '*';
        V[23][12] = '*';
        V[44][11] = '*';
        V[44][12] = '*';
    }
    if (V[5][27] == ' ' || V[23][27] == ' ' || V[44][27] == ' ') {
        V[5][27] = '*';
        V[5][28] = '*';
        V[23][27] = '*';
        V[23][28] = '*';
        V[44][27] = '*';
        V[44][28] = '*';
    }
    if (V[5][43] == ' ' || V[23][43] == ' ' || V[44][43] == ' ') {
        V[5][43] = '*';
        V[5][44] = '*';
        V[23][43] = '*';
        V[23][44] = '*';
        V[44][43] = '*';
        V[44][44] = '*';
    }
    if (V[5][59] == ' ' || V[23][59] == ' ' || V[44][59] == ' ') {
        V[5][59] = '*';
        V[5][60] = '*';
        V[23][59] = '*';
        V[23][60] = '*';
        V[44][59] = '*';
        V[44][60] = '*';
    }

}

void desenho_tabuleiro(int line, int column) {
    int j, i;

    for (j = 0; j <= line; j++) {
        if (j == 0 || j == line) {
            for (i = 0; i<= column; i++) {
                V[j][i] ='#';
            }
        } else {
            for (i = 0; i < 1 ; i++) {
                V[j][i] = '#';
                V[j][column] = '#';
            }
            for (i = 1; i < column; i++) {
                V[j][i] = ' ';
            }
    }}

    //


    casas_verticais(4, 9);
    casas_verticais(4, 25);
    casas_verticais(4, 41);
    casas_verticais(4, 57);
    quadrado_final();
    escrever_string("R1 B1 G1 Y1", 3, 7);
    escrever_string("R2 B2 G2 Y2", 3, 23);
    escrever_string("R3 B3 G3 Y3", 3, 39);
    escrever_string("R4 B4 G4 Y4", 3, 55);
    desenho_log();
    casas_especiais();


}



void desenho_log() {
    int j;

    escrever_string("MENU DE JOGADAS", 18, 92);
    escrever_string("JOGADOR ", 21, 82);
    escrever_string("RED", 21, 110);
    escrever_string("JOGADOR ", 23, 82);
    escrever_string("BLUE", 23, 110);
    escrever_string("JOGADOR ", 25, 82);
    escrever_string("GREEN", 25, 110);
    escrever_string("JOGADOR ", 27, 82);
    escrever_string("YELLOW", 27, 110);
    escrever_string("VEZ DO JOGADOR ", 11, 88);
    escrever_string("VEZ DO JOGADOR ", 29, 88);

    for (j = 81; j<= coluna - 2; j++) {
        V[16][j] = '#';
    }

    for (j = 1; j <= linha - 3; j++) {
        V[j][80] = '#';

    desenhar_dado();


}}

void printar_tela() {
    int i, j;

    system("cls");

    printf("\n\n\n\n\n\n");

    for (j = 0; j <= linha - 2; j++) {
        for (i = 0; i<= coluna - 2; i++) {
            printf("%c", V[j][i]);
    }
        printf("\n");}
}

void limpar_casa_atual (char jogador[], char l_c) {

    int j;

    V[2][11] = ' ';
    V[2][12] = ' ';


    for (j = 2; j <= 44; j++){
        if (V[j][l_c] == jogador[0] && V[j][l_c+1] == jogador[1]) {
            V[j][l_c] = ' '; V[j][l_c+1] = ' ';
            break;
    }}
}

void verificar_casa(int line, int colun) {

    if (V[line][colun] == 'R') {

        if (colun == 11) {
            r1 = 0;
            V[3][7] = 'R';
            V[3][8] = '1';
        } else if (colun == 27) {
            r2 = 0;
            V[3][23] = 'R';
            V[3][24] = '2';
        } else if (colun == 43) {
            r3 = 0;
            V[3][39] = 'R';
            V[3][40] = '3';
        } else if (colun == 59) {
            r4 = 0;
            V[3][55] = 'R';
            V[3][56] = '4';
        }

    } else if (V[line][colun] == 'B') {

        if (colun == 11) {
            b1 = 0;
            V[3][10] = 'B';
            V[3][11] = '1';
        } else if (colun == 27) {
            b2 = 0;
            V[3][26] = 'B';
            V[3][27] = '2';
        } else if (colun == 43) {
            b3 = 0;
            V[3][42] = 'B';
            V[3][43] = '3';
        } else if (colun == 59) {
            b4 = 0;
            V[3][58] = 'B';
            V[3][59] = '4';
        }
    } else if (V[line][colun] == 'G') {

        if (colun == 11) {
            g1 = 0;
            V[3][13] = 'G';
            V[3][14] = '1';
        } else if (colun == 27) {
            g2 = 0;
            V[3][29] = 'G';
            V[3][30] = '2';
        } else if (colun == 43) {
            g3 = 0;
            V[3][45] = 'G';
            V[3][46] = '3';
        } else if (colun == 59) {
            g4 = 0;
            V[3][61] = 'G';
            V[3][62] = '4';
        }
    } else if (V[line][colun] == 'Y') {

        if (colun == 11) {
            y1 = 0;
            V[3][16] = 'Y';
            V[3][17] = '1';
        } else if (colun == 27) {
            y2 = 0;
            V[3][32] = 'Y';
            V[3][33] = '2';
        } else if (colun == 43) {
            y3 = 0;
            V[3][48] = 'Y';
            V[3][49] = '3';
        } else if (colun == 59) {
            y4 = 0;
            V[3][64] = 'Y';
            V[3][65] = '4';
        }
    }

    casas_especiais();
}

void andar_casas_verticais(char jogador[], int casa_atual, int casas_adicionais, int l_c) {
    int casa_final = casa_atual + casas_adicionais;
    int calculo;
    calculo = (3 * casa_final -1) + 3;

    verificar_casa(calculo, l_c);
    V[calculo][l_c] = jogador[0];
    V[calculo][l_c+1] = jogador[1];
}

int verificar_casas_especiais(int colun, int c_final) {
    int i, j;
    int result = 0;

    if (colun == 11) {
        if (c_final == 1) {
            if (V[5][11] != '*') {
                result = 1;
        }}
        else if (c_final == 7) {
            if (V[23][11] != '*') {
                result = 1;
            }
        }
        else if (c_final == 14) {
            if (V[44][11] != '*') {
                result = 1;
            }
        }

    } else if (colun == 27) {
        if (c_final == 1) {
            if (V[5][27] != '*') {
                result = 1;
            }}
        else if (c_final == 7) {
            if (V[23][27] != '*') {
                result = 1;
            }
        }
        else if (c_final == 14) {
            if (V[44][27] != '*') {
                result = 1;
            }
        }

    } else if (colun == 43) {
        if (c_final == 1) {
            if (V[5][43] != '*') {
                result = 1;
            }}
        else if (c_final == 7) {
            if (V[23][43] != '*') {
                result = 1;
            }
        }
        else if (c_final == 14) {
            if (V[44][43] != '*') {
                result = 1;
            }
        }

    } else if (colun == 59) {
        if (c_final == 1) {
            if (V[5][59] != '*') {
                result = 1;
            }}
        else if (c_final == 7) {
            if (V[23][59] != '*') {
                result = 1;
            }
        }
        else if (c_final == 14) {
            if (V[44][59] != '*') {
                result = 1;
            }
        }

    }

    return result;


}

void desenho_menu() {

    int i, j;

    printf("\n\n\n\n\n");

    for (j = 0; j <= 15; j++) {
        if (j == 0 || j== 15) {
        for (i = 0; i<= 30; i++) {
            MENU[j][i] = '#';
        }} else {
            MENU[j][0] = '#';
            MENU[j][30] = '#';
        }
    }



    escrever_string_menu("1 - Iniciar Jogo", 5, 3);
    escrever_string_menu("2 - Como Jogar", 7, 3);
    escrever_string_menu("3 - Sair", 9, 3);

    for (j = 0; j <= 15; j++) {
        for (i = 0; i<=30; i++) {
            printf("%c", MENU[j][i]);
        }
        printf("\n");
    }
}

void manual_instrucoes() {
    int i, j;

    printf("\n\n\n\n\n");

    for (j = 0; j<=60; j++) {
        if (j == 0 || j == 60) {
            for (i = 0; i<= 49; i++) {
                MANUAL[j][i] = '#';
            }
    }
    }

    escrever_string_instrucoes("** Instrucoes do jogo: ", 5, 5);

    escrever_string_instrucoes("> O jogo tera 4 jogadores, cada um com 4 pecas, totalizando assim 16 pecas.", 6, 5);
    escrever_string_instrucoes("> As pecas serao distribuidas automaticamente pelo jogo para cada jogador, e serao indicadas no MENU DE JOGADAS.", 8, 5);
    escrever_string_instrucoes("> O tabuleiro contem 4 divisoes verticais, e cada peca dos jogadores podera se deslocar verticalmente por uma das divisoes, como por exemplo, as pecas de numero 1 dos jogadores poderao se deslocar dentro da primeira divisao, as pecas de numero 2 poderao se deslocar dentro da segunda divisao e assim sucessivamente.", 11, 5);
    escrever_string_instrucoes("> Cada divisao contem 15 casas, e o objetivo do jogo e que o jogador consiga deslocar todas as suas pecas ate a decima quinta casa, sendo que o jogo so terminara quando o penultimo colocado conseguir levar todas as suas pecas para a ecima quinta casa, estabelecendo assim um ranking de primeiro, segundo, terceiro e quarto colocado.", 18, 5);
    escrever_string_instrucoes("** Regras: ", 28, 5);
    escrever_string_instrucoes("> Cada jogador tem 1 chance de jogar a cada rodada.", 29, 5);
    escrever_string_instrucoes("> Nao e possivel dois jogadores ocuparem a mesma casa, portanto, quando um jogador se desloca para uma casa que ja esta ocupada por outro, ele entao 'rouba' seu lugar e manda sua peça de volta para a casa 0.", 31, 5);
    escrever_string_instrucoes("> As casas marcadas com asteriscos são casas especiais, dispondo da seguinte vantagem: um jogador que esta numa casa especial nao pode ter seu lugar roubado, ou seja, sua peca estara protegida enquanto estiver dentro da casa em questao.", 36, 5);
    escrever_string_instrucoes("> Quando um jogador tem uma ou mais pecas proximas a casa final e o numero de casas que deve se deslocar, segundo o dado, exceder o numero maximo de casas (15), a depender da peca que o jogador escolher para se locomover pelo tabuleiro, o jogador podera perder a sua vez. Exemplificando, suponhamos que um jogador tem duas pecas na casa 14 e outras duas na casa 7, e o dado lhe indique que deve se locomover 6 casas, caso o jogador escolha mover as pecas que estao na casa 14 o numero de casas que devera se mover sera maior que o numero disponivel, portanto, o jogador perdera sua vez. Deste modo, e necessário elaborar estrategias para propiciar uma vitoria.", 41, 5);



    for (j = 0; j <= 60; j++) {
        for (i = 0; i<=49; i++) {
            printf("%c", MANUAL[j][i]);
        }
        printf("\n");
    }
}



int main() {

    int i, j;
    int vez = 1; int result = 0;
    int escolha;


    for (j = 0; j <= linha; j++) {
        V[j][coluna] = '\0';
    }



do {
    desenho_menu();

    printf("\t\tResposta: ");
    scanf("%d", &escolha);
    switch (escolha) {
case 1:

    system("cls");

    // <-- Jogadores

    printf("Digite o nome do Jogador 1: ");
    scanf("%s", j1);
    
    printf("\nDigite o nome do Jogador 2: ");
    scanf("%s", j2);
    
    printf("\nDigite o nome do Jogador 3: ");
    scanf("%s", j3);
    
    printf("\nDigite o nome do Jogador 4: ");
    scanf("%s", j4);
    

    // -->

    desenho_tabuleiro(linha - 2, coluna - 2);

do {
        switch (vez) {
case 1:
    if (r1 <= 15 || r2 <= 15 || r3 <= 15 || r4 <= 15) {
        char escolhido[5];
        char char_r[2];
        char recusar;
        int contador = 0;
        recusar = 'x';
        escrever_string(j1, 11, 103);
        escrever_string(j1, 29, 103);
        escrever_string(j1, 21, 91);
        escrever_string(j2, 23, 91);
        escrever_string(j3, 25, 91);
        escrever_string(j4, 27, 91);
        apagar_log();
        escrever_string("Pressione qualquer tecla para rolar", 32, 82);
        escrever_string("o dado!", 33, 82);
        printar_tela();
        getch();
        apagar_log();
        result = jogar_dado1();
        sprintf(char_r, "%d", result);

        escrever_string("Qual peca deseja mover   casa(s)?", 32, 84);
        V[32][107] = char_r[0];

        escrever_string("Digite 1 para mover a peca R1", 35, 84);
        escrever_string("2 para mover a peca R2,", 36, 84);
        escrever_string("3 para mover a peca R3 ou", 37, 84);
        escrever_string("4 para mover a peca R4.", 38, 84);

        printar_tela();

        do  {
        printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
        scanf("%s", escolhido);
        if (r1 == 15) {
            while (escolhido[0] == '1') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '1';
            }
        }
        if (r2 == 15) {
            while (escolhido[0] == '2') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '2';
        }}
        if (r3 == 15) {
            while (escolhido[0] == '3') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '3';
            }
        }
        if (r4 == 15) {
            while (escolhido[0] == '4') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '4';
            }
        }} while (escolhido[0] == recusar);

        // Condicionais para não mover em casas especiais -->
        do {
        if (escolhido[0] == '1' && (r1 + result == 1 || r1 + result == 7 || r1 + result == 14)) {
            if (verificar_casas_especiais(11, r1+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '1';
                }
            }

        }
        if (escolhido[0] == '2' && (r2 + result == 1 || r2 + result == 7 || r2 + result == 14)) {
            if (verificar_casas_especiais(27, r2+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '2') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '2';
                }
            }
        }
        if (escolhido[0] == '3' && (r3 + result == 1 || r3 + result == 7 || r3 + result == 14)) {
            if (verificar_casas_especiais(43, r3+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '3') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '3';
                }
        }}
        if (escolhido[0] == '4' && (r4 + result == 1 || r4 + result == 7 || r4 + result == 14)) {
            if (verificar_casas_especiais(59, r4+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '4';
                }
            }

        }

        } while (escolhido[0] == recusar && contador < 4);

        if (contador >= 4) {
            vez = 2;
            break;
        }

        if (escolhido[0] == '1') {
            strcpy(escolhido, "R1");

            if (V[3][7] == 'R'){
                V[3][7] = '_';
                V[3][8] = '_';
            }

            if (r1 + result <= 14) {
                limpar_casa_atual(escolhido, 11);
                andar_casas_verticais(escolhido, r1, result, 11);
                r1 = r1 + result;

            } else if (r1 + result == 15) {
                limpar_casa_atual(escolhido, 11);
                escrever_string("R1", 49, 15);
                r1 = r1 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '2') {
            strcpy(escolhido, "R2");

            if (V[3][23] == 'R'){
                V[3][23] = '_';
                V[3][24] = '_';
            }

            if (r2 + result <= 14) {
                limpar_casa_atual(escolhido, 27);
                andar_casas_verticais(escolhido, r2, result, 27);
                r2 = r2 + result;

            } else if (r2 + result == 15) {
                limpar_casa_atual(escolhido, 27);
                escrever_string("R2", 50, 15);
                r2 = r2 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '3') {
            strcpy(escolhido, "R3");

            if (V[3][39] == 'R'){
                V[3][39] = '_';
                V[3][40] = '_';
            }

            if (r3 + result <= 14) {
                limpar_casa_atual(escolhido, 43);
                andar_casas_verticais(escolhido, r3, result, 43);
                r3 = r3 + result;

            } else if (r3 + result == 15) {
                limpar_casa_atual(escolhido, 43);
                escrever_string("R3", 51, 15);
                r3 = r3 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '4') {
            strcpy(escolhido, "R4");

            if (V[3][55] == 'R'){
                V[3][55] = '_';
                V[3][56] = '_';
            }

            if (r4 + result <= 14) {
                limpar_casa_atual(escolhido, 59);
                andar_casas_verticais(escolhido, r4, result, 59);
                r4 = r4 + result;

            } else if (r4 + result == 15) {
                limpar_casa_atual(escolhido, 59);
                escrever_string("R4", 52, 15);
                r4 = r4 + result;
                fim_jogo++;
            }

        }
        vez = 2;
        break;
        } else {
        vez = 2;
        break;}


case 2:
    if (b1 <= 15 || b2 <= 15 || b3 <= 15 || b4 <= 15) {
        char escolhido[5];
        char char_r[2];
        char recusar;
        int contador = 0;
        recusar = 'x';
        escrever_string(j2, 11, 103);
        escrever_string(j2, 29, 103);
        apagar_log();
        escrever_string("Pressione qualquer tecla para rolar", 32, 82);
        escrever_string("o dado!", 33, 82);
        printar_tela();
        getch();
        apagar_log();
        result = jogar_dado1();
        sprintf(char_r, "%d", result);

        escrever_string("Qual peca deseja mover   casa(s)?", 32, 84);
        V[32][107] = char_r[0];

        escrever_string("Digite 1 para mover a peca B1", 35, 84);
        escrever_string("2 para mover a peca B2,", 36, 84);
        escrever_string("3 para mover a peca B3 ou", 37, 84);
        escrever_string("4 para mover a peca B4.", 38, 84);

        printar_tela();


        do {
        printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
        scanf("%s", escolhido);
        if (b1 == 15) {
            while (escolhido[0] == '1') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '1';
            }
        }
        if (b2 == 15) {
            while (escolhido[0] == '2') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '2';
        }}
        if (b3 == 15) {
            while (escolhido[0] == '3') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '3';
            }
        }
        if (b4 == 15) {
            while (escolhido[0] == '4') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '4';
            }
        }} while (escolhido[0] == recusar);


        // Condicionais para não mover em casas especiais -->
        do {
        if (escolhido[0] == '1' && (b1 + result == 1 || b1 + result == 7 || b1 + result == 14)) {
            if (verificar_casas_especiais(11, b1+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '1';
                }
            }

        }
        if (escolhido[0] == '2' && (b2 + result == 1 || b2 + result == 7 || b2 + result == 14)) {
            if (verificar_casas_especiais(27, b2+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '2') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '2';
                }
            }
            }
        if (escolhido[0] == '3' && (b3 + result == 1 || b3 + result == 7 || b3 + result == 14)) {
            if (verificar_casas_especiais(43, b3+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '3') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '3';
                }
            }
            }
        if (escolhido[0] == '4' && (b4 + result == 1 || b4 + result == 7 || b4 + result == 14)) {
             if (verificar_casas_especiais(59, b4+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '4';
                }
            }

            }
        } while (escolhido[0] == recusar && contador < 4);


    //

        if (contador >=4) {
            vez = 3;
            break;
        }






        if (escolhido[0] == '1') {
            strcpy(escolhido, "B1");

            if (V[3][10] == 'B'){
                V[3][10] = '_';
                V[3][11] = '_';
            }

            if (b1 + result <= 14) {
                limpar_casa_atual(escolhido, 11);
                andar_casas_verticais(escolhido, b1, result, 11);
                b1 = b1 + result;

            } else if (b1 + result == 15) {
                limpar_casa_atual(escolhido, 11);
                escrever_string("B1", 49, 27);
                b1 = b1 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '2') {
            strcpy(escolhido, "B2");

            if (V[3][26] == 'B'){
                V[3][26] = '_';
                V[3][27] = '_';
            }

            if (b2 + result <= 14) {
                limpar_casa_atual(escolhido, 27);
                andar_casas_verticais(escolhido, b2, result, 27);
                b2 = b2 + result;

            } else if (b2 + result == 15) {
                limpar_casa_atual(escolhido, 27);
                escrever_string("B2", 50, 27);
                b2 = b2 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '3') {
            strcpy(escolhido, "B3");

            if (V[3][42] == 'B'){
                V[3][42] = '_';
                V[3][43] = '_';
            }

            if (b3 + result <= 14) {
                limpar_casa_atual(escolhido, 43);
                andar_casas_verticais(escolhido, b3, result, 43);
                b3 = b3 + result;

            } else if (b3 + result == 15) {
                limpar_casa_atual(escolhido, 43);
                escrever_string("B3", 51, 27);
                b3 = b3 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '4') {
            strcpy(escolhido, "B4");

            if (V[3][58] == 'B'){
                V[3][58] = '_';
                V[3][59] = '_';
            }

            if (b4 + result <= 14) {
                limpar_casa_atual(escolhido, 59);
                andar_casas_verticais(escolhido, b4, result, 59);
                b4 = b4 + result;

            } else if (b4 + result == 15) {
                limpar_casa_atual(escolhido, 59);
                escrever_string("B4", 52, 27);
                b4 = b4 + result;
                fim_jogo++;
            }

        }

        vez = 3;
        break;





    } else {
        vez = 3;
        break;
    }
case 3:
    if (g1 <= 15 || g2 <= 15 || g3 <= 15 || g4 <= 15) {
        char escolhido[5];
        char char_r[2];
        char recusar;
        int contador = 0;
        recusar = 'x';
        escrever_string(j3, 11, 103);
        escrever_string(j3, 29, 103);
        apagar_log();
        escrever_string("Pressione qualquer tecla para rolar", 32, 82);
        escrever_string("o dado!", 33, 82);
        printar_tela();
        getch();
        apagar_log();
        result = jogar_dado1();
        sprintf(char_r, "%d", result);

        escrever_string("Qual peca deseja mover   casa(s)?", 32, 84);
        V[32][107] = char_r[0];

        escrever_string("Digite 1 para mover a peca G1", 35, 84);
        escrever_string("2 para mover a peca G2,", 36, 84);
        escrever_string("3 para mover a peca G3 ou", 37, 84);
        escrever_string("4 para mover a peca G4.", 38, 84);

        printar_tela();


        do {
        printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
        scanf("%s", escolhido);
        if (g1 == 15) {
            while (escolhido[0] == '1') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '1';
            }
        }
        if (g2 == 15) {
            while (escolhido[0] == '2') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '2';
        }}
        if (g3 == 15) {
            while (escolhido[0] == '3') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '3';
            }
        }
        if (g4 == 15) {
            while (escolhido[0] == '4') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '4';
            }
        }}while (escolhido[0] == recusar);


        // Condicionais para não mover em casas especiais -->
        do {
        if (escolhido[0] == '1' && (g1 + result == 1 || g1 + result == 7 || g1 + result == 14)) {
            if (verificar_casas_especiais(11, g1+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '1';
                }
            }

        }
        if (escolhido[0] == '2' && (g2 + result == 1 || g2 + result == 7 || g2 + result == 14)) {
            if (verificar_casas_especiais(27, g2+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '2') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '2';
                }
            }
            }
        if (escolhido[0] == '3' && g3 + (result == 1 || g3 + result == 7 || g3 + result == 14)) {
            if (verificar_casas_especiais(43, g3+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '3') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '3';
                }
            }
            }
        if (escolhido[0] == '4' && (g4 + result == 1 || g4 + result == 7 || g4 + result == 14)) {
            if (verificar_casas_especiais(59, g4+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '4';
                }
            }

            }
        } while (escolhido[0] == recusar && contador < 4);

        if (contador >= 4) {
            vez = 4;
            break;
        }











        if (escolhido[0] == '1') {
            strcpy(escolhido, "G1");

            if (V[3][13] == 'G'){
                V[3][13] = '_';
                V[3][14] = '_';
            }

            if (g1 + result <= 14) {
                limpar_casa_atual(escolhido, 11);
                andar_casas_verticais(escolhido, g1, result, 11);
                g1 = g1 + result;

            } else if (g1 + result == 15) {
                limpar_casa_atual(escolhido, 11);
                escrever_string("G1", 49, 38);
                g1 = g1 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '2') {
            strcpy(escolhido, "G2");

            if (V[3][29] == 'G'){
                V[3][29] = '_';
                V[3][30] = '_';
            }

            if (g2 + result <= 14) {
                limpar_casa_atual(escolhido, 27);
                andar_casas_verticais(escolhido, g2, result, 27);
                g2 = g2 + result;

            } else if (g2 + result == 15) {
                limpar_casa_atual(escolhido, 27);
                escrever_string("G2", 50, 38);
                g2 = g2 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '3') {
            strcpy(escolhido, "G3");

            if (V[3][45] == 'G'){
                V[3][45] = '_';
                V[3][46] = '_';
            }

            if (g3 + result <= 14) {
                limpar_casa_atual(escolhido, 43);
                andar_casas_verticais(escolhido, g3, result, 43);
                g3 = g3 + result;

            } else if (g3 + result == 15) {
                limpar_casa_atual(escolhido, 43);
                escrever_string("G3", 51, 38);
                g3 = g3 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '4') {
            strcpy(escolhido, "G4");

            if (V[3][61] == 'G'){
                V[3][61] = '_';
                V[3][62] = '_';
            }

            if (g4 + result <= 14) {
                limpar_casa_atual(escolhido, 59);
                andar_casas_verticais(escolhido, g4, result, 59);
                g4 = g4 + result;

            } else if (g4 + result == 15) {
                limpar_casa_atual(escolhido, 59);
                escrever_string("G4", 52, 38);
                g4 = g4 + result;
                fim_jogo++;
            }

        }

        vez = 4;
        break;





    } else {
        vez = 4;
        break;
    }
case 4:

    if (y1 <= 15 || y2 <= 15 || y3 <= 15 || y4 <= 15) {
        char escolhido[5];
        char char_r[2];
        char recusar;
        int contador = 0;
        recusar = 'x';
        escrever_string(j4, 11, 103);
        escrever_string(j4, 29, 103);
        apagar_log();
        escrever_string("Pressione qualquer tecla para rolar", 32, 82);
        escrever_string("o dado!", 33, 82);
        printar_tela();
        getch();
        apagar_log();
        result = jogar_dado1();
        sprintf(char_r, "%d", result);

        escrever_string("Qual peca deseja mover   casa(s)?", 32, 84);
        V[32][107] = char_r[0];

        escrever_string("Digite 1 para mover a peca Y1", 35, 84);
        escrever_string("2 para mover a peca Y2,", 36, 84);
        escrever_string("3 para mover a peca Y3 ou", 37, 84);
        escrever_string("4 para mover a peca Y4.", 38, 84);

        printar_tela();


        do {
        printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
        scanf("%s", escolhido);
        if (y1 == 15) {
            while (escolhido[0] == '1') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '1';
            }
        }
        if (y2 == 15) {
            while (escolhido[0] == '2') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '2';
        }}
        if (y3 == 15) {
            while (escolhido[0] == '3') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '3';
            }
        }
        if (y4 == 15) {
            while (escolhido[0] == '4') {
                printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                scanf("%s", escolhido);
                recusar = '4';
            }
        }}while (escolhido[0] == recusar);


        // Condicionais para não mover em casas especiais -->
        do {
        if (escolhido[0] == '1' && (y1 + result == 1 || y1 + result == 7 || y1 + result == 14)) {
            if (verificar_casas_especiais(11, y1+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '1';
                }
            }

        }
        if (escolhido[0] == '2' && (y2 + result == 1 || y2 + result == 7 || y2 + result == 14)) {
            if (verificar_casas_especiais(27, y2+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '2') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '2';
                }
            }
            }
        if (escolhido[0] == '3' && (y3 + result == 1 || y3 + result == 7 || y3 + result == 14)) {
            if (verificar_casas_especiais(43, y3+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '3') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '3';
                }
            }
            }
        if (escolhido[0] == '4' && (y4 + result == 1 || y4 + result == 7 || y4 + result == 14)) {
            if (verificar_casas_especiais(59, y4+result) == 1) {
                contador++;
                escrever_string("Voce nao pode mover essa peca!", 40, 85);
                printar_tela();
                while (escolhido[0] == '1') {
                    printf("\t\t\t\t\t\t\t\t\t\t\t    Resposta: ");
                    scanf("%s", escolhido);
                    recusar = '4';
                }
            }

            }
        } while (escolhido[0] == recusar && contador < 4);

        if (contador >= 4) {
            vez = 1;
            break;
        }











        if (escolhido[0] == '1') {
            strcpy(escolhido, "Y1");

            if (V[3][16] == 'Y'){
                V[3][16] = '_';
                V[3][17] = '_';
            }

            if (y1 + result <= 14) {
                limpar_casa_atual(escolhido, 11);
                andar_casas_verticais(escolhido, y1, result, 11);
                y1 = y1 + result;

            } else if (y1 + result == 15) {
                limpar_casa_atual(escolhido, 11);
                escrever_string("Y1", 49, 50);
                y1 = y1 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '2') {
            strcpy(escolhido, "Y2");

            if (V[3][32] == 'Y'){
                V[3][32] = '_';
                V[3][33] = '_';
            }

            if (y2 + result <= 14) {
                limpar_casa_atual(escolhido, 27);
                andar_casas_verticais(escolhido, y2, result, 27);
                y2 = y2 + result;

            } else if (y2 + result == 15) {
                limpar_casa_atual(escolhido, 27);
                escrever_string("Y2", 50, 50);
                y2 = y2 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '3') {
            strcpy(escolhido, "Y3");

            if (V[3][48] == 'Y'){
                V[3][48] = '_';
                V[3][49] = '_';
            }

            if (y3 + result <= 14) {
                limpar_casa_atual(escolhido, 43);
                andar_casas_verticais(escolhido, y3, result, 43);
                y3 = y3 + result;

            } else if (y3 + result == 15) {
                limpar_casa_atual(escolhido, 43);
                escrever_string("Y3", 51, 50);
                y3 = y3 + result;
                fim_jogo++;
            }

        }

        if (escolhido[0] == '4') {
            strcpy(escolhido, "Y4");

            if (V[3][64] == 'Y'){
                V[3][64] = '_';
                V[3][65] = '_';
            }

            if (y4 + result <= 14) {
                limpar_casa_atual(escolhido, 59);
                andar_casas_verticais(escolhido, y4, result, 59);
                y4 = y4 + result;

            } else if (y4 + result == 15) {
                limpar_casa_atual(escolhido, 59);
                escrever_string("Y4", 52, 50);
                y4 = y4 + result;
                fim_jogo++;
            }

        }

        vez = 1;
        break;





    } else {
        vez = 1;
        break;
    }








    }
    } while (fim_jogo < 16);







case 2:
system("cls");
manual_instrucoes();
getch();
system("cls");
break;



case 3:
    exit(1);
}} while  (escolha <  4);
}
