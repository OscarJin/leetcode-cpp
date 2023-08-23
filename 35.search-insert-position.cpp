/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                if (mid == nums.size() - 1 || nums[mid+1] >= target)
                    return mid + 1;
                low = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

