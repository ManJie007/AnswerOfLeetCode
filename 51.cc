#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool isValid(vector<string> &board, int row, int col) {

    int n = board.size();

    for (int i = 0; i < row; ++i) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }

  void backtrack(vector<vector<string>> &res, vector<string> &board, int n,
                 int row) {
    if (row == n) {
      res.push_back(board);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (isValid(board, row, i)) {
        board[row][i] = 'Q';
        backtrack(res, board, n, row + 1);
        board[row][i] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board;
    for (int i = 0; i < n; ++i) {
      board.emplace_back(n, '.');
    }

    backtrack(res, board, n, 0);

    return res;
  }
};
