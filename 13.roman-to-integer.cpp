/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        short sum = 0, prev = 0, digit = 0;
        for (short i = s.length() - 1; i >= 0; i--)
        {
            switch ((char)s[i])
            {
            case 'I':
                digit = 1;
                break;
            case 'V':
                digit = 5;
                break;
            case 'X':
                digit = 10;
                break;
            case 'L':
                digit = 50;
                break;
            case 'C':
                digit = 100;
                break;
            case 'D':
                digit = 500;
                break;
            case 'M':
                digit = 1000;
                break;
            default:
                break;
            }
            sum = digit >= prev ? sum + digit : sum - digit;
            prev = digit;
        }
        return (int)sum;
    }
};
// @lc code=end

