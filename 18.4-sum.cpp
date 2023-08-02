/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < N-3 && ((long long)nums[i] + (long long)nums[i+1] + (long long)nums[i+2] + (long long)nums[i+3]) <= target; i++)
        {
            if (i > 0 && nums[i] == nums[i-1] || ((long long)nums[i] + (long long)nums[N-3] + (long long)nums[N-2] + (long long)nums[N-1]) < target)
                continue;
            
            for (int j = i+1; j < N-2 && ((long long)nums[i] + (long long)nums[j] + (long long)nums[j+1] + (long long)nums[j+2]) <= target; j++)
            {
                if (j > i+1 && nums[j] == nums[j-1] || ((long long)nums[i] + (long long)nums[j] + (long long)nums[N-2] + (long long)nums[N-1]) < target)
                    continue;
                
                for (int l = j+1, r = N-1; l<r;)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1])   r--;
                        l++;    r--;
                    }
                    else if (sum > target)
                        r--;
                    else
                        l++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

