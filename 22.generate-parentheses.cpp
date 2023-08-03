/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        findParenthesis(n, n, "");
        return res;
    }

private:
    vector<string> res;
    void findParenthesis(int numLeft, int numRight, string s)
    {
        // DFS
        if (numLeft == 0 && numRight == 0)
        {
            res.push_back(s);
            return;
        }

        if (numLeft > 0)
            findParenthesis(numLeft - 1, numRight, s+"(");
        if (numRight > 0 && numRight > numLeft)
            findParenthesis(numLeft, numRight - 1, s+")");
    }
};
// @lc code=end

