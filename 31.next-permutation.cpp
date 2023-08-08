/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = 0, end = 0;
        for (start = nums.size() - 2; start >= 0; start--)
        {
            if (nums[start] < nums[start + 1])
                break;
        }

        if (start >= 0)
        {
            for (end = nums.size() - 1; end > start; end--)
            {
                if (nums[end] > nums[start])
                    break;
            }
            swap(nums[start], nums[end]);
        }
        
        end = nums.size() - 1;
        while (++start < end)
        {
            swap(nums[start], nums[end]);
            end--;
        }
    }

private:
    inline void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
// @lc code=end

