/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int tot = m * n;
        int cnt = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> res;

        while (cnt < tot)
        {
            int i = top, j = left;
            while (j <= right && cnt < tot)
            {
                res.push_back(matrix[i][j]);
                cnt++;
                j++;
            }
            i = top + 1, j = right;
            while (i <= bottom && cnt < tot)
            {
                res.push_back(matrix[i][j]);
                cnt++;
                i++;
            }
            i = bottom, j = right - 1;
            while (j >= left && cnt < tot)
            {
                res.push_back(matrix[i][j]);
                cnt++;
                j--;
            }
            i = bottom - 1, j = left;
            while (i > top && cnt < tot)
            {
                res.push_back(matrix[i][j]);
                cnt++;
                i--;
            }
            top++, left++, bottom--, right--;
        }

        return res;
    }
};
// @lc code=end

