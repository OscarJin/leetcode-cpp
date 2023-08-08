// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem33.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
                return mid;
            else if ((nums[mid] < target && target <= nums[high]) || (nums[mid] >= nums[low] && nums[mid] >= nums[high] && (target > nums[mid] || target <= nums[high])))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

