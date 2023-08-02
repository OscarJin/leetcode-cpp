/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        short N = nums.size();
        for (int i = 0; i < N; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            short left = i+1, right = N-1;
            while (left < right)
            {
                if ((nums[left] + nums[right]) == -nums[i])
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1])    right--;
                    left++;     right--;
                }
                else if((nums[left] + nums[right]) > -nums[i])
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
// @lc code=end

