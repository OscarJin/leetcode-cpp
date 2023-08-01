/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            res = maxPalindrome(s, i, i, res);
            res = maxPalindrome(s, i, i+1, res);
        }
        return res;
    }

private:
    string maxPalindrome(string s, int i, int j, string res)
    {
        // center i, j
        string cur = "";
        while(i >= 0 && j < s.length() && s[i] == s[j])
        {
            cur = s.substr(i, j-i+1);
            i--; j++;
        }
        return res.length() < cur.length() ? cur : res;
    }
};
// @lc code=end

