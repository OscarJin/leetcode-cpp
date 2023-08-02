/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0, right = height.size()-1;

        while (left < right)
        {
            int width = right - left;
            int high = 0;
            if (height[left] < height[right])
            {
                high = height[left];
                left++;
            }
            else
            {
                high = height[right];
                right--;
            }

            max = width * high > max ? width * high : max;
        }

        return max;
    }
};
// @lc code=end

