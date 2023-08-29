/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //DFS
        vector<bool> col(n), diag1(2*n-1), diag2(2*n-1);
        vector<int> cur;
        
        putQueen(n, 0, col, diag1, diag2, cur);
        return res;
    }

private:
    vector<vector<string>> res;

    void putQueen(int n, int ind, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, vector<int>& cur)
    {
        // put queen in row ind
        if (ind == n)
        {
            res.push_back(generateBoard(n, cur));
            return;
        }

        for (int i = 0; i < n; i++)
        {
            // try put queen on column i
            if (!col[i] && !diag1[ind + i] && !diag2[ind - i + n - 1])
            {
                cur.push_back(i);
                col[i] = true;
                diag1[ind + i] = true;
                diag2[ind - i + n - 1] = true;
                putQueen(n, ind + 1, col, diag1, diag2, cur);
                col[i] = false;
                diag1[ind + i] = false;
                diag2[ind - i + n - 1] = false;
                cur.erase(cur.end() - 1);
            }
        }
    }

    vector<string> generateBoard(int n, vector<int>& cur)
    {
        vector<string> board;
        string row = "";
        for (int i = 0; i < n; i++)
            row += ".";
        for (int i = 0; i < n; i++)
            board.push_back(row);
        
        for (int i = 0; i < n; i++)
            board[i][cur[i]] = 'Q';
        
        return board;
    }
};
// @lc code=end

