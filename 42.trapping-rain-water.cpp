// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    res += maxLeft - height[left];
                left++;
            }
            else
            {
                if (height[right] >= maxRight)
                    maxRight = height[right];
                else
                    res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

