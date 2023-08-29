/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
         vector<bool> col(n), diag1(2*n-1), diag2(2*n-1);
        vector<int> cur;
        int res = 0;
        putQueen2(n, 0, col, diag1, diag2, cur, res);
        return res;
    }

private:
    void putQueen2(int n, int ind, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, vector<int>& cur, int& res)
    {
        // put queen in row ind
        if (ind == n)
        {
            res++;
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
                putQueen2(n, ind + 1, col, diag1, diag2, cur, res);
                col[i] = false;
                diag1[ind + i] = false;
                diag2[ind - i + n - 1] = false;
                cur.erase(cur.end() - 1);
            }
        }
    }
};
// @lc code=end

