/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        int row = matrix.size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse colums
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end

