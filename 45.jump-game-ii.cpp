/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int furthest = 0, step = 0, nextStep = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            furthest = i + nums[i] > furthest ? i + nums[i] : furthest;
            if (furthest >= nums.size() - 1)
                return step + 1;
            if (i == nextStep)
            {
                nextStep = furthest;
                step++;
            }
        }
        
        return step;
    }
};
// @lc code=end

