#include "ai.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

t_bool has_free_spaces(char board[][DIMF])
{
    for (unsigned short i = 0; i < DIMF; i++)
    {
        for (unsigned short j = 0; j < DIMF; j++)
        {
            if (board[i][j] == EMPTY) return 1;
        }
    }
    return 0;
}

t_bool out_of_range(short row, short col)
{
    return row > DIMF || row < 1 || col > DIMF || col < 1;
}

void player_move(char board[][DIMF])
{
    int row, col;
    t_bool move_done = 0;
    while (!move_done)
    {
        printf("\nRow [1..3]: ");
        scanf("%d", &row);
        printf("\nColumn [1..3]: ");
        scanf("%d", &col);
        if (out_of_range(row,col)) printf("\nOut of range. Try again.");
        else if (board[row-1][col-1] == EMPTY)
        {
            board[row-1][col-1] = PLAYER;
            move_done = 1;
        }
        else printf("\nSquare occupied. Try again");
    }
    printf("\n");
}

char check_winner(char board[][DIMF])
{
    //checks rows
    for(int i = 0; i < DIMF; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
    }
    //checks cols
    for(int i = 0; i < DIMF; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    //checks diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];
    
    return EMPTY;
}

// Función de evaluación para el algoritmo minimax
int evaluate(char board[][DIMF])
{
    char winner = check_winner(board);
    
    if(winner == COM)
        return 10;
    else if(winner == PLAYER)
        return -10;
    else
        return 0;
}

// Función minimax recursiva
int minimax(char board[][DIMF], int depth, t_bool isMaximizer)
{
    int score = evaluate(board);
    
    // Si COM gana, devolver puntuación positiva
    if(score == 10)
        return score - depth;
    
    // Si PLAYER gana, devolver puntuación negativa
    if(score == -10)
        return score + depth;
    
    // Si no hay espacios libres, es un empate
    if(!has_free_spaces(board))
        return 0;
    
    // Si es el turno del maximizador (COM)
    if(isMaximizer)
    {
        int best = -1000;
        
        for(int i = 0; i < DIMF; i++)
        {
            for(int j = 0; j < DIMF; j++)
            {
                if(board[i][j] == EMPTY)
                {
                    // Hacer movimiento
                    board[i][j] = COM;
                    
                    // Llamar recursivamente a minimax y elegir el máximo valor
                    best = (best > minimax(board, depth + 1, !isMaximizer)) ? best : minimax(board, depth + 1, !isMaximizer);
                    
                    // Deshacer movimiento
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
    // Si es el turno del minimizador (PLAYER)
    else
    {
        int best = 1000;
        
        for(int i = 0; i < DIMF; i++)
        {
            for(int j = 0; j < DIMF; j++)
            {
                if(board[i][j] == EMPTY)
                {
                    // Hacer movimiento
                    board[i][j] = PLAYER;
                    
                    // Llamar recursivamente a minimax y elegir el mínimo valor
                    best = (best < minimax(board, depth + 1, !isMaximizer)) ? best : minimax(board, depth + 1, !isMaximizer);
                    
                    // Deshacer movimiento
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

// Encuentra el mejor movimiento para COM
void find_best_move(char board[][DIMF], int *row, int *col)
{
    int best_val = -1000;
    *row = -1;
    *col = -1;
    
    // Evaluar todos los movimientos posibles y elegir el mejor
    for(int i = 0; i < DIMF; i++)
    {
        for(int j = 0; j < DIMF; j++)
        {
            if(board[i][j] == EMPTY)
            {
                // Hacer movimiento
                board[i][j] = COM;
                
                // Calcular valor minimax para este movimiento
                int move_val = minimax(board, 0, 0);
                
                // Deshacer movimiento
                board[i][j] = EMPTY;
                
                // Actualizar el mejor movimiento si este es mejor
                if(move_val > best_val)
                {
                    *row = i;
                    *col = j;
                    best_val = move_val;
                }
            }
        }
    }
}

void COM_move(char board[][DIMF])
{
    // Añadimos un poco de variabilidad al comienzo
    static int first_move = 1;
    
    if(first_move && has_free_spaces(board))
    {
        srand(time(0));
        // 80% de probabilidad de colocar en el centro si está libre
        if(board[DIMF/2][DIMF/2] == EMPTY && (rand() % 10 < 8))
        {
            board[DIMF/2][DIMF/2] = COM;
        }
        else
        {
            int row, col;
            find_best_move(board, &row, &col);
            if(row != -1 && col != -1)
                board[row][col] = COM;
            else
            {
                // Esto solo ocurriría en un caso extremo
                do
                {
                    row = rand() % DIMF;
                    col = rand() % DIMF;
                } while (board[row][col] != EMPTY);
                board[row][col] = COM;
            }
        }
        first_move = 0;
    }
    else
    {
        int row, col;
        find_best_move(board, &row, &col);
        if(row != -1 && col != -1)
            board[row][col] = COM;
        else
        {
            // Esto solo ocurriría en un caso extremo
            unsigned short r, c;
            do
            {
                r = rand() % DIMF;
                c = rand() % DIMF;
            } while (board[r][c] != EMPTY);
            board[r][c] = COM;
        }
    }
}
