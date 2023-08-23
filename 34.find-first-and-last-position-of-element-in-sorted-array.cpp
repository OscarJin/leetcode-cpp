/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(searchFirstElem(nums, target));
        res.push_back(searchLastElem(nums, target));
        return res;
    }

private:
    int searchFirstElem(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                if (mid == 0 || nums[mid] != nums[mid-1])
                    return mid;
                high = mid - 1;
            }
        }
        return -1;
    }

    int searchLastElem(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                if (mid == nums.size() - 1 || nums[mid] != nums[mid+1])
                    return mid;
                low = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

