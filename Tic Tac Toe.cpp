#include <iostream>
using namespace std;

// The game board
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

// Function to display the game board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to make a move
bool makeMove(int slot, char mark) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
        return true;
    }
    return false;
}

// Function to check if someone has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// Main game function
void playGame() {
    char player1 = 'X', player2 = 'O';
    int turn = 1; // 1 for Player 1, 2 for Player 2
    int move;
    bool gameWon = false;

    cout << "Welcome to Tic Tac Toe!\n";
    displayBoard();

    for (int i = 0; i < 9 && !gameWon; i++) {
        cout << "Player " << turn << " (" << (turn == 1 ? player1 : player2) << "), enter a slot (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || !makeMove(move, (turn == 1 ? player1 : player2))) {
            cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }

        displayBoard();

        if (checkWin()) {
            cout << "Player " << turn << " wins! Congratulations!\n";
            gameWon = true;
        }

        // Switch turns
        turn = (turn == 1) ? 2 : 1;
    }

    if (!gameWon) {
        cout << "It's a tie! Well played!\n";
    }
}

// Main function
int main() {
    playGame();
    return 0;
}
