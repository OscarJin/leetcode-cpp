/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

private:
    bool solutionFound = false;

    bool validPut (vector<vector<char>>& board, int x, int i, int j)
    {
        for (int k = 0; k < 9; k++)
        {
            // check row
            if (board[i][k] == x + '0')
                return false;
            // check column
            if (board[k][j] == x + '0')
                return false;
        }

        // check subbox
        for (int k = (i/3)*3; k < (i/3)*3 + 3; k++)
        {
            for (int l = (j/3)*3; l < (j/3)*3 + 3; l++)
            {
                if (board[k][l] == x + '0')
                    return false;
            }
        }

        return true;
    }

    void solve(vector<vector<char>>& board, int i, int j)
    {
        if (solutionFound)
            return;
        if (i == 9)
        {
            solutionFound = true;
            return;
        }
        if (j == 9)
        {
            solve(board, i+1, 0);
        }
        else
        {
            if (board[i][j] != '.')
            {
                solve(board, i, j+1);
                if (solutionFound)
                    return;
            }
            else
            {
                for (int x = 1; x <= 9; x++)
                {
                    if (validPut(board, x, i, j))
                    {
                        board[i][j] = x + '0';
                        solve(board, i, j+1);
                        if (solutionFound)
                            return;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
};
// @lc code=end

