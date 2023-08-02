/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        short N = nums.size();
        int res = 0, diff = INT_MAX;

        for (int i = 0; i < N-2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            for (int l = i+1, r = N-1; l < r;)
            {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (abs(sum-target) < diff)
                {
                    diff = abs(sum-target);
                    res = sum;
                }
                
                if (sum == target)
                    return sum;
                else if (sum > target)
                    r--;
                else
                    l++;
            }
        }

        return res;
    }
};
// @lc code=end

