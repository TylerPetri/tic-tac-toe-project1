#include <iostream>
#include <iomanip>

void displayBoard(char board[][3]);

int main()
{

    bool gameOver = false;
    char input;
    int row = 0;
    int col = 0;
    char players[2] = {'X', 'O'};
    int openSpaces = 9;

    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}};

    displayBoard(board);
    std::cout << "Welcome player... Enter a row and column as your first move or press c to leave and join the cowards" << std::endl;
    do
    {
        // TODO
        // greet and show board
        // ask for row and col
        // check if open spot as well as inside board
        // once placed, check if winner or draw (no more open spots)
        // then repeat
        std::cout << "Row: ";
        std::cin >> input;
        if (input == 'c')
        {
            std::cout << "Welcome to the cowards team hahaha" << std::endl;
            exit(0);
        }
        else
        {
            row = input - '0';
        }
        std::cout << row << std::endl;

        std::cout << "Column: ";
        std::cin >> input;
        if (input == 'c')
        {
            std::cout << "Welcome to the cowards team hahaha" << std::endl;
            exit(0);
        }
        else
        {
            col = input - '0';
        }
        std::cout << col << std::endl;

        displayBoard(board);

    } while (!gameOver && openSpaces > 0);

    return 0;
}

void handleInput()
{
};

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