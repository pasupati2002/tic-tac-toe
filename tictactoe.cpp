#include <iostream>
using namespace std;

char board[3][3];
char current_marker;
int current_player;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int row, int col) {
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = current_marker;
    return true;
}

int winner() {
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return current_player;
        }
    }
    // columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return current_player;
        }
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return current_player;
    }
    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }
    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    current_marker = 'X';
    current_player = 1;
    int player_won;

    for (int i = 0; i < 9; i++) {
        drawBoard();
        cout << "It's player " << current_player << "'s turn. Enter your move (row and column): ";
        int row, col;
        cin >> row >> col;
        row--; col--;
        if (row < 0 || row > 2 || col < 0 || col > 2 || !placeMarker(row, col)) {
            cout << "Invalid move. Try again." << endl;
            i--;
            continue;
        }
        player_won = winner();
        if (player_won != 0) {
            drawBoard();
            cout << "Player " << player_won << " wins!" << endl;
            return;
        }
        swapPlayerAndMarker();
    }
    drawBoard();
    cout << "It's a tie!" << endl;
}

int main() {
    game();
    return 0;
}
