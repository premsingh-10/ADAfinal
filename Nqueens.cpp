#include <iostream>
#include <vector>
using namespace std;

class NQueensSolver {

public:

    void helper(vector<vector<char>>& board, vector<vector<string>>& allBoards, int col) {
        if (col == board.size()) {
            saveBoard(board, allBoards);
            return;
        }
        for (int row = 0; row < board.size(); row++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                helper(board, allBoards, col + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<vector<char>>& board) {
        for (int j = 0; j < board.size(); j++) {
            if (board[row][j] == 'Q')
                return false;
        }
        for (int j = 0; j < board.size(); j++) {
            if (board[j][col] == 'Q')
                return false;
        }
        int r = row;
        for (int c = col; c >= 0 && r >= 0; c--, r--) {
            if (board[r][c] == 'Q')
                return false;
        }
        r = row;
        for (int c = col; c < board.size() && r >= 0; r--, c++) {
            if (board[r][c] == 'Q')
                return false;
        }
        r = row;
        for (int c = col; c >= 0 && r < board[0].size(); c--, r++) {
            if (board[r][c] == 'Q')
                return false;
        }
        r = row;
        for (int c = col; c < board.size() && r < board.size(); c++, r++) {
            if (board[r][c] == 'Q')
                return false;
        }
        return true;
    }

    void saveBoard(vector<vector<char>>& board, vector<vector<string>>& allBoards) {
        vector<string> newboard;
        for (int i = 0; i < board.size(); i++) {
            string row = "";
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'Q')
                    row += 'Q';
                else
                    row += '.';
            }
            newboard.push_back(row);
        }
        allBoards.push_back(newboard);
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allBoards;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(board, allBoards, 0);
        return allBoards;
    }

    void printBoards(const vector<vector<string>>& boards) {
        for (size_t i = 0; i < boards.size(); i++) {
            for (const string& row : boards[i]) {
                for (size_t j = 0; j < row.length(); j++) {
                    cout << row[j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    NQueensSolver solver;
    vector<vector<string>> FinalBoard = solver.solveNQueens(n);
    solver.printBoards(FinalBoard);

    return 0;}
