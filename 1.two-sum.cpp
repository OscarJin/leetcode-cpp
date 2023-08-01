/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> NumsIndex;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int another = target - nums[i];
            if(NumsIndex.find(another) != NumsIndex.end())
            {
                result.push_back(i);
                result.push_back(NumsIndex[another]);
                break;
            }
            else
            {
                NumsIndex.insert(pair<int, int>(nums[i], i));
            }
        }
        return result;
    }
};
// @lc code=end

