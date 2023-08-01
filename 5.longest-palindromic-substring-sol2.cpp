/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int cur_left = 0, cur_right = -1;
        int left = 0, right = 0;
        int len = s.length();

        while (cur_left < len)
        {
            // find repeating letters
            while (cur_right + 1 < len && s[cur_left] == s[cur_right+1])
            {
                cur_right++;
            }
            // find boundaries of palindromic substring
            while (cur_left - 1 >= 0 && cur_right + 1 < len && s[cur_left-1] == s[cur_right+1])
            {
                cur_left--; cur_right++;
            }
            
            if (cur_right - cur_left > right - left)
            {
                right = cur_right; left = cur_left;
            }

            // reset center
            cur_left = ((cur_left + cur_right) >> 1) + 1;
            cur_right = cur_left;
        }
        return s.substr(left, right-left+1);
    }
};
// @lc code=end

