#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 20;
const char MINE = '*';
const char EMPTY = ' ';
const char FLAG = 'F';

enum Difficulty { EASY = 1, MEDIUM, HARD };

class Game {
private:
    vector<vector<char>> board;
    vector<vector<bool>> revealed;
    vector<vector<bool>> flagged;
    int rows, cols, mines;
    time_t startTime;
    bool gameOver;

    void placeMines() {
        srand(time(0));
        for (int i = 0; i < mines;) {
            int r = rand() % rows;
            int c = rand() % cols;
            if (board[r][c] != MINE) {
                board[r][c] = MINE;
                i++;
            }
        }
    }

    void calculateHints() {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == MINE) continue;
                int mineCount = 0;
                // Check surrounding cells
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (r + i >= 0 && r + i < rows && c + j >= 0 && c + j < cols) {
                            if (board[r + i][c + j] == MINE) {
                                mineCount++;
                            }
                        }
                    }
                }
                if (mineCount > 0) {
                    board[r][c] = '0' + mineCount; // Convert int to char
                }
            }
        }
    }

public:
    Game(int r, int c, int m) : rows(r), cols(c), mines(m), gameOver(false) {
        board.resize(rows, vector<char>(cols, EMPTY));
        revealed.resize(rows, vector<bool>(cols, false));
        flagged.resize(rows, vector<bool>(cols, false));
        placeMines();
        calculateHints();
        startTime = time(0);
    }

    void display() {
        system("clear"); // Use "cls" on Windows
        cout << "==================== Minesweeper ====================" << endl;
        cout << "Current Time: " << difftime(time(0), startTime) << " seconds" << endl;
        cout << "Flags remaining: " << mines - countFlags() << endl;
        cout << "------------------------------------------------------" << endl;

        cout << "   ";
        for (int c = 0; c < cols; ++c) {
            cout << setw(3) << c;
        }
        cout << endl;

        for (int r = 0; r < rows; ++r) {
            cout << setw(2) << r << " | ";
            for (int c = 0; c < cols; ++c) {
                if (revealed[r][c]) {
                    cout << board[r][c] << " ";
                } else if (flagged[r][c]) {
                    cout << FLAG << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }

    void flagCell(int r, int c) {
        if (!revealed[r][c]) {
            flagged[r][c] = !flagged[r][c]; // Toggle flag
        }
    }

    void revealCell(int r, int c) {
        if (!flagged[r][c]) {
            revealed[r][c] = true;
            if (board[r][c] == MINE) {
                gameOver = true;
            } else if (board[r][c] == EMPTY) {
                // Reveal surrounding cells recursively (if necessary)
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (r + i >= 0 && r + i < rows && c + j >= 0 && c + j < cols) {
                            if (!revealed[r + i][c + j]) {
                                revealCell(r + i, c + j);
                            }
                        }
                    }
                }
            }
        }
    }

    bool isGameOver() const {
        return gameOver;
    }

    int countFlags() const {
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (flagged[r][c]) count++;
            }
        }
        return count;
    }
};

void selectDifficulty(int &rows, int &cols, int &mines) {
    int level;
    cout << "Select difficulty level:\n1. Easy\n2. Medium\n3. Hard\n";
    cin >> level;
    switch (level) {
        case EASY:
            rows = 8; cols = 8; mines = 10; break;
        case MEDIUM:
            rows = 16; cols = 16; mines = 40; break;
        case HARD:
            rows = 16; cols = 30; mines = 99; break;
        default:
            cout << "Invalid selection, defaulting to Easy.\n";
            rows = 8; cols = 8; mines = 10; break;
    }
}

int main() {
    int rows, cols, mines;
    selectDifficulty(rows, cols, mines);
    Game game(rows, cols, mines);

    while (!game.isGameOver()) {
        game.display();
        int r, c;
        char action;

        cout << "Enter action (r for reveal, f for flag) and coordinates (row col): ";
        cin >> action >> r >> c;

        if (action == 'r') {
            game.revealCell(r, c);
        } else if (action == 'f') {
            game.flagCell(r, c);
        }
    }

    cout << "Game Over! You hit a mine!" << endl;
    return 0;
}