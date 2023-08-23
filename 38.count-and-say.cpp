/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1)
            return s;
        
        for (int i = 2; i <= n; i++)
            s = say(s);
        
        return s;
    }

private:
    string say(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            int cnt = 1;
            while(i < s.length() - 1 && s[i] == s[i+1])
            {
                cnt++;
                i++;
            }
            ans += (cnt + '0');
            ans += s[i];
        }
        return ans;
    }
};
// @lc code=end

