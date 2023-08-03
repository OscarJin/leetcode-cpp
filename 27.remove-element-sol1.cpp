/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        int last = 0;
        for (; last < nums.size(); last++)
        {
            if (nums[last] == val)
            {
                for (int finder = last; finder < nums.size(); finder++)
                {
                    if (finder == nums.size() - 1 && nums[finder] == val)
                        return last;
                    if (nums[finder] != val)
                    {
                        int tmp = nums[last];
                        nums[last] = nums[finder];
                        nums[finder] = tmp;
                        break;
                    }
                }
            }
        }
        return last;
    }
};
// @lc code=end

