/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        
        int* dp = new int[n];
        memset(dp, 0, sizeof(int) * n);
        dp[0] = nums[0];
        int res = dp[0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = nums[i] + dp[i-1] * (dp[i-1] > 0);
            res = res > dp[i] ? res : dp[i];
        }
        return res;
    }
};
// @lc code=end

