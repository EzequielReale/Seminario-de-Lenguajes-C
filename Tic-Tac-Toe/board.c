#include "board.h"

void clean_board(char board[][DIMF])
{
    for (unsigned short i = 0; i < DIMF; i++)
    {
        for (unsigned short j = 0; j < DIMF; j++) board[i][j] = EMPTY;
    } 
}

void print_board(char board[][DIMF])
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

void print_winner(char winner)
{
    switch (winner)
    {
    case PLAYER:
        puts("Congratulations! You win!");
        break;
    case COM:
        puts("What a pitty! You loose!");
        break;
    default:
        puts("Ohhh, it was a tie!");
        break;
    }
}

/*int main()
{
    char board[3][3];
    clean_board(board);
    print_board(board);
    print_winner(PLAYER);
}*/
