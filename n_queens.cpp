#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Backtracking method
    void solveBacktracking(int col, vector<string> &board, vector<vector<string>> &ans,
                           vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solveBacktracking(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueensBacktracking(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        solveBacktracking(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }

    // Branch and bound method
    bool isSafe(int row, int col, vector<int>& queenCols) {
        for (int i = 0; i < row; i++) {
            if (queenCols[i] == col || abs(queenCols[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    void solveBranchAndBound(int row, vector<int>& queenCols, vector<vector<string>>& ans) {
        int n = queenCols.size();
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][queenCols[i]] = 'Q';
            }
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, queenCols)) {
                queenCols[row] = col;
                solveBranchAndBound(row + 1, queenCols, ans);
                queenCols[row] = -1; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueensBranchAndBound(int n) {
        vector<vector<string>> ans;
        vector<int> queenCols(n, -1); // Initialize all queens to be unplaced (-1)
        solveBranchAndBound(0, queenCols, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Solution solution;

    // Backtracking method
    cout << "Using Backtracking Method:" << endl;
    vector<vector<string>> resultBacktracking = solution.solveNQueensBacktracking(n);
    cout << "Number of solutions using Backtracking: " << resultBacktracking.size() << endl;
    cout << "Solutions:" << endl;
    for (int i = 0; i < resultBacktracking.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < resultBacktracking[i].size(); j++) {
            cout << resultBacktracking[i][j] << endl;
        }
        cout << endl;
    }

    // Branch and bound method
    cout << "Using Branch and Bound Method:" << endl;
    vector<vector<string>> resultBranchAndBound = solution.solveNQueensBranchAndBound(n);
    cout << "Number of solutions using Branch and Bound: " << resultBranchAndBound.size() << endl;
    cout << "Solutions:" << endl;
    for (int i = 0; i < resultBranchAndBound.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < resultBranchAndBound[i].size(); j++) {
            cout << resultBranchAndBound[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
