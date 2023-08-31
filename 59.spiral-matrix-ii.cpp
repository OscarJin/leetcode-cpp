/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int tot = n * n, cnt = 0;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        while (cnt < tot)
        {
            int i = top, j = left;
            while (j <= right && cnt < tot)
            {
                matrix[i][j] = cnt + 1;
                cnt++;
                j++;
            }
            i = top + 1, j = right;
            while (i <= bottom && cnt < tot)
            {
                matrix[i][j] = cnt + 1;
                cnt++;
                i++;
            }
            i = bottom, j = right - 1;
            while (j >= left && cnt < tot)
            {
                matrix[i][j] = cnt + 1;
                cnt++;
                j--;
            }
            i = bottom - 1, j = left;
            while (i > top && cnt < tot)
            {
                matrix[i][j] = cnt + 1;
                cnt++;
                i--;
            }
            top++, left++, bottom--, right--;
        }

        return matrix;
    }
};
// @lc code=end

