#include "ai.h"
#include "board.h"

int main()
{
    char play, winner;
    char board[DIMF][DIMF];
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
         "\n      Welcome to poor Tic-Tac-Toe english careta v.2.0.1!"
         "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    do
    {
        clean_board(board);
        winner = EMPTY;
        while ((has_free_spaces(board)) && (winner == EMPTY)){
            print_board(board);

            player_move(board);
            if (((winner = check_winner(board)) != EMPTY) || !(has_free_spaces(board))) break;

            COM_move(board);
            if (((winner = check_winner(board)) != EMPTY) || !(has_free_spaces(board))) break;
        }
        print_board(board);
        print_winner(winner);
        printf("\nDo you want to play again? [Y/N]: ");
        play = getchar(); //clean buffer
        play = toupper(getchar());
    } while (play != 'N');
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
         "\n        Thanks for playing!"
         "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    return 0;
}