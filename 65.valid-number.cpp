/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        bool numFlag = false, eFlag = false, dotFlag = false;
        for (int i = 0; i < s.length(); i++)
        {
            if ('0' <= s[i] && s[i] <= '9')
                numFlag = true;
            else if (s[i] == '.' && !eFlag && !dotFlag)
                dotFlag = true;
            else if ((s[i] == 'E' || s[i] == 'e') && numFlag && !eFlag)
            {
                eFlag = true;
                numFlag = false;
            }
            else if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i - 1] == 'E' || s[i - 1] == 'e'))
                continue;
            else
                return false;
        }
        return numFlag;
    }
};
// @lc code=end

