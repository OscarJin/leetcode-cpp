/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int last = len - 1;
        while (last >= 0 && s[last] == ' ')
            last --;
        int first = last;
        while (first >= 0 && s[first] != ' ')
            first--;
        return last - first;
    }
};
// @lc code=end

