#include <iostream>
#include<windows.h>
using namespace std;

//Declaring variables
string player1, player2;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row, column, choice;
char turn = 'X';
bool draw = false;

//Function to show the current status of the board
void DisplayBoard()
{
    cout << "\tPLAYER - 1: " << player1 << "[X]\t PLAYER - 2: " << player2 << "[O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}

//Function to determine whether the chosen box is empty or not
bool CheckBox()
{
    if (board[row][column] != 'X' && board[row][column] != 'O')
    {
        return true;
    }
    return false;
}

//Function to handle wrong data input
void Data()
{
    if (!cin >> choice)
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter a number between 0-9: ";
        cin >> choice;
    }
}

//Function to get user choice 
void PlayerMove()
{
    if (turn == 'X')
    {
        cout << player1 << "[X] turn: ";
    }
    else if (turn == 'O')
    {
        cout << player2 << "[O] turn: ";
    }

    cin >> choice;
    Data();

    switch (choice)
    {
    case 1: row = 0; column = 0;
        break;
    case 2: row = 0; column = 1;
        break;
    case 3: row = 0; column = 2;
        break;
    case 4: row = 1; column = 0;
        break;
    case 5: row = 1; column = 1;
        break;
    case 6: row = 1; column = 2;
        break;
    case 7: row = 2; column = 0;
        break;
    case 8: row = 2; column = 1;
        break;
    case 9: row = 2; column = 2;
        break;
    default:
        cout << "Invalid move" << endl;
        return;
    }

    if (turn == 'X' && CheckBox() == true)
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && CheckBox() == true)
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else if (CheckBox() == false)
    {
        cout << "Box already filled in, please choose another one!" << endl;
        PlayerMove();
    }
}
//Function to determine whether game is over or not
bool GameStatus()
{
    for (int i = 0; i < 3; i++)
    {
        //checks the horizontal and vertical status of the board
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }
    //checks the diagonal status of the board 
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }
    //checks the diagonal pairs to decide whether game is over or not
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    //checking if game is already draw
    draw = true;
    return false;
}

int main()
{
    cout << "\t T I C -- T A C -- T O E -- G A M E \n\n";

    cout << "Enter Player-1 name: ";
    cin >> player1;
    cout << "Enter Player-2 name: ";
    cin >> player2;
    cout << "\n";

    while (GameStatus() == true)
    {
        Sleep(500);
        DisplayBoard();
        PlayerMove();
        GameStatus();
    }
    if (turn == 'O' && draw == false)
    {
        cout << "Congratz! " << player1 << " has won the game" << endl;
    }
    else if (turn == 'X' && draw == false)
    {
        cout << "Congratz! " << player2 << " has won the game" << endl;
    }
    else
    {
        cout << "Draw";
    }
}
