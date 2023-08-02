/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));

        // when s is null
        dp[0][0] = true;
        for (int j = 1; j < pLen; j++)
        {
            if (p[j] == '*')
                dp[0][j+1] = dp[0][j-1];
        }

        // state transition
        for (int i = 0; i < sLen; i++)
        {
            for (int j = 0; j < pLen; j++)
            {
                if (p[j] == '.' || p[j] == s[i])
                    dp[i+1][j+1] = dp[i][j];
                
                if (p[j] == '*')
                {
                    if (p[j-1] != s[i] && p[j-1] != '.')
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else
                        dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1];
                }
            }
        }

        return dp[sLen][pLen];
    }
};
// @lc code=end

