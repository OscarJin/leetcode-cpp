// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = 0, finder = 0;
        for (; last < nums.size() - 1; last++)
        {
            while (nums[finder] == nums[last])
            {
                finder++;
                if (finder == nums.size())
                    return last + 1;
            }
            nums[last+1] = nums[finder];
        }
        return last + 1;
    }
};
// @lc code=end

