#include <iostream>
#include <iomanip>
#include <string>

/*
This is a tic-tac-toe game
*/

/*Prototypes
 */
bool checkBoard(char board[][3], char players[], int numTurns);
int checkExit(char input);
void displayBoard(char board[][3]);
void handleInput(char board[][3], int &row, int &col, char &input);

int main()
{

    bool gameOver = false;
    char input;
    int row = 0;
    int col = 0;
    char players[2] = {'X', 'O'};
    int numTurns = 0;
    std::string playAgain;

    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}};

    displayBoard(board);
    std::cout << "Welcome player X... Enter a row and column as your first move or press c to leave and join the cowards" << std::endl;
    do
    {
        handleInput(board, row, col, input);

        // Assign X or O to the correct spot on the board
        board[row - 1][col - 1] = players[numTurns % 2];

        // Check if game was won and increment the number of turns
        gameOver = checkBoard(board, players, numTurns);
        numTurns++;

        if (!gameOver)
        {
            displayBoard(board);
            std::cout << players[numTurns % 2] << "'s turn" << std::endl;
        }

    } while (!gameOver && numTurns < 9);

    if (numTurns == 9)
    {
        std::cout << "Game ended in Draw" << std::endl;
    }
    std::cout << "Play Again? Yes or No" << std::endl;
    std::cin >> playAgain;

    while (playAgain != "Yes")
    {
        if (playAgain == "No")
        {
            std::cout << "Welcome to the cowards team hahaha" << std::endl;
            exit(0);
        }
        std::cout << "Invalid answer... Yes or No" << std::endl;
        std::cout << "Play Again? Yes or No" << std::endl;
        std::cin >> playAgain;
    }
    if (playAgain == "Yes")
    {
        main();
    }

    return 0;
}

/*This function prints the board
 */
void displayBoard(char board[][3])
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            std::cout << std::setw(2) << board[r][c];
        }
        std::cout << std::endl;
    }
}

/*This function checks the entire
gameboard to see if there are any
winning rows/columns/diagonals.
It returns true if there is a winning
configuration. Otherwise it returns
false.
*/
bool checkBoard(char board[][3], char players[], int numTurns)
{
    bool row_check = true;
    bool col_check = true;
    char temp;

    // Check X's on diagonals
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'))
    {
        std::cout << "Winner! Player " << players[numTurns % 2] << " wins!" << std::endl;
        return true;
    }
    // Check O's on diagonals
    else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'))
    {
        std::cout << "Winner! Player " << players[numTurns % 2] << " wins!" << std::endl;
        return true;
    }

    // Check rows
    for (int r = 0; r < 3; r++)
    {
        temp = board[r][0];
        row_check = true;
        for (int c = 0; c < 3; c++)
        {
            if ((board[r][c] != temp) || (board[r][c] == '-'))
            {
                row_check = false;
            }
        }
        if (row_check)
        {
            std::cout << "Winner! Player " << players[numTurns % 2] << " wins!" << std::endl;
            return true;
        }
    }

    // Check columns
    for (int c = 0; c < 3; c++)
    {
        temp = board[0][c];
        col_check = true;
        for (int r = 0; r < 3; r++)
        {
            if ((board[r][c] != temp) || (board[r][c] == '-'))
            {
                col_check = false;
            }
        }
        if (col_check)
        {
            std::cout << "Winner! Player " << players[numTurns % 2] << " wins!" << std::endl;
            return true;
        }
    }
    return false;
}

/*This function exits the program when user enters "c"
 */
int checkExit(char input)
{
    if (input == 'c')
    {
        std::cout << "Welcome to the cowards team hahaha" << std::endl;
        exit(0);
        return 0;
    }
    else
    {
        return input - '0';
    }
}

/*This function handles the user's input
 */
void handleInput(char board[][3], int &row, int &col, char &input)
{
    // reset row and col for new turn
    row = 0;
    col = 0;

    std::cout << "Row: ";
    std::cin >> input;
    row = checkExit(input);
    if (!(row > 3))
    {
        std::cout << "Column: ";
        std::cin >> input;
        col = checkExit(input);
    }
    while ((board[row - 1][col - 1] != '-') || (row > 3) || (col > 3))
    {
        std::cout << "Invalid choice, please choose again" << std::endl;
        if (row > 3)
        {
            std::cout << "Row: ";
            std::cin >> input;
            row = checkExit(input);
        }
        std::cout << "Column: ";
        std::cin >> input;
        col = checkExit(input);
    }
}