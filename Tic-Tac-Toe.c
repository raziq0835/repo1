#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char board[3][3];
int score[2] = {0, 0};
const char PLAYER = 'X';
const char PLAYER2 = 'O';
int turn = 1, winner = 0, com = 0;
char player1[10], player2[10];

void setBoard();
void clrscr()
{
    system("cls");
}
void printBoard();
int checkWinner();
int checkSpace();
void printMenu(int *ch);
// void printScore();
void playerMove(const char player);

void main()
{
    int intrest, ch;
    char player;
    clrscr();
    for (;;)
    {
        clrscr();
        printMenu(&ch);
        clrscr();
        switch (ch)
        {
        case 1:
            strcpy(player1, "User");
            strcpy(player2, "Computer");
            do
            {
                clrscr();
                setBoard();
                do
                {
                    turn = turn % 2;
                    player = (turn == 1) ? PLAYER : PLAYER2;
                    if (turn == 1)
                    {
                        com = 0;
                        playerMove(player);
                    }
                    else
                    {
                        com = 1;
                        playerMove(player);
                    }

                    if (checkWinner() == 1)
                        break;

                } while (checkSpace() != 0);
                printf("Do you want to play again? (1/0): ");
                scanf("%d", &intrest);
            } while (intrest != 0);

            break;

        case 2:
            com = 0;
            printf("Enter Player 1 name : ");
            scanf("%s", player1);
            printf("Enter player 2 name : ");
            scanf("%s", player2);
            do
            {
                setBoard();
                do
                {
                    turn = turn % 2;
                    player = (turn == 1) ? PLAYER : PLAYER2;
                    if (turn == 1)
                        playerMove(player);
                    else
                        playerMove(player);
                    if (checkWinner() == 1)
                        break;

                } while (checkSpace() != 0);
                printf("Do you want to play again? (1/0): ");
                scanf("%d", &intrest);
            } while (intrest != 0);

            break;
        case 3:
            // printScore();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice \nEnter valid choice \n");
        }
    }
}

void setBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}

void printBoard()
{

    printf("\n---TIC-TAC-TOE---\n\n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

int checkWinner()
{
    int winner = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
            winner = 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
            winner = 1;
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        winner = 1;

    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[2][0] != ' ')
        winner = 1;

    if (winner == 1)
    {
        turn = (turn == 1) ? 0 : 1;
        printBoard();
        if (turn == 1)
            printf("%s is winner\n", player1);
        else
            printf("%s is winner\n", player2);
        return 1;
    }
    return 0;
}

int checkSpace()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                count++;
    }
    return count;
}

void playerMove(const char player)
{
    srand(time(0));
    int row, col, flag = 0;
    while (flag != 1)
    {
        printBoard();
        if (turn == 1)
            printf("%s's turn\n", player1);
        else
            printf("%s's turn\n", player2);
        if (com == 0)
        {
            printf("Row (1-3) : ");
            scanf("%d", &row);
            printf("Column (1-3) : ");
            scanf("%d", &col);
            row--;
            col--;
        }
        else
        {
            do
            {
                srand(time(NULL));
                row = rand() % 3;
                col = rand() % 3;
            } while (board[row][col] != ' ');
        }
        if ((row < 0 || row > 2) || (col < 0 || col > 2) || (board[row][col] != ' '))
        {
            clrscr();
            printf("Invalid choice \n");
            printf("Try again\n");
            continue;
        }

        board[row][col] = player;
        turn++;
        flag = 1;
        clrscr();
    }
}

void printMenu(int *ch)
{
    printf("\n---TIC-TAC-TOE---\n\n");
    printf("------------------\n");
    printf("| 1. 1Players    |\n| 2. 2player     |\n| 3. Score       |\n| 4. exit        |\n");
    printf("------------------\n");
    printf("Enter Choice  : ");
    scanf("%d",ch);
}