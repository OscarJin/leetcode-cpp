/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

/*
1. Iterate through the array from the start.
2. Check if the current number, X[i], is within the range of 1 to n and if it is not already present at index X[i] - 1.
3. If the conditions are met, swap X[i] with the number present at the index X[i] - 1.
Continue the process until the array is fully traversed.

After the sorting is done, the next step is to scan the modified array again to find the first index where X[i] is not equal to i + 1. This indicates the presence of a missing positive number. If such an index is found, return i + 1 as the first missing positive. If no such index is found, it means all numbers from 1 to n are present in the array, so return the value n + 1 as the first missing positive.
*/

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len;)
        {
            if (1 <= nums[i] && nums[i] <= len && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }

        for (int i = 1; i <= len; i++)
        {
            if (i != nums[i-1])
                return i;
        }

        return len + 1;
    }
};
// @lc code=end

