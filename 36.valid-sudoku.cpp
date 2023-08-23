/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowbuf[9][9], colbuf[9][9], subboxbuf[9][9];
        memset(rowbuf, false, sizeof(rowbuf));
        memset(colbuf, false, sizeof(colbuf));
        memset(subboxbuf, false, sizeof(subboxbuf));

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    int num = board[r][c] - '1';
                    if (rowbuf[r][num] || colbuf[c][num] || subboxbuf[(r/3)*3 + c/3][num])
                        return false;
                    rowbuf[r][num] = true;
                    colbuf[c][num] = true;
                    subboxbuf[(r/3)*3 + c/3][num] = true;
                }
            }
        }

        return true;
    }
};
// @lc code=end

