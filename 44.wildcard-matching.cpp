/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

/*
0. Clean the pattern
1. Checked base cases
initialized a 2X2 boolean vector and made dp[0][0] true which is the case when both strings are empty
when pattern is empty and string_len is greater than zero set to false
when word is empty and pattern contains only * set to true else false
2. Case 1: if(p[i-1]==s[j-1] || p[i-1]=='?')then we set dp[i][j]=dp[i-1][j-1]; so that dp[i][j] is true only if previous values also true
2. Case 2: when p[i-1]=='*' then we consider two subscases
    dp[i][j-1]: which treats * matching with every letter
    dp[i-1][j]: * matches with nothing
3. finally we return dp[n][m]
*/

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p != "")
            p = clean(p);
        
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;
        bool flag = true;
        for (int i = 1; i < n + 1; i++)
        {
            if (p[i-1] != '*' && flag)
                flag = false;
            dp[i][0] = flag;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[i-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }

        return dp[n][m];
    }

private:
    string clean(string& p)
    {
        string clean_p = "";
        for (int i = 0; i < p.length(); i++)
        {
            if (clean_p.empty() || p[i] != '*' || (i >= 1 && clean_p[clean_p.length() - 1] != '*'))
                clean_p.append(1, p[i]);
        }
        return clean_p;
    }
};
// @lc code=end

