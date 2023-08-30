/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        
        int maxJump = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxJump)
                return false;
            maxJump = maxJump > i + nums[i] ? maxJump : i + nums[i];
        }
        return true;
    }
};
// @lc code=end

