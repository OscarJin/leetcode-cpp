/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        short nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";

        int i = 0;
        while (num != 0)
        {
            while (num < nums[i])
                i++;
            
            num -= nums[i];
            res += symbols[i];
        }
        return res;
    }
};
// @lc code=end

