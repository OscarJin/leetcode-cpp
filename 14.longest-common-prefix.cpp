/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < prefix.length(); j++)
            {
                if (strs[i][j] != prefix[j] || strs[i].length() <= j)
                {
                    prefix = prefix.substr(0, j);
                    break;
                }
            }
        }
        return prefix;
    }
};
// @lc code=end

