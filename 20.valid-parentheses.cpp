/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.length(); i++)
        {
            char cur = (char)s[i];
            if (cur == '(' || cur == '[' || cur == '{')
                parentheses.push(cur);
            else
            {
                if (parentheses.empty())
                    return false;
                char top = parentheses.top();
                if ((cur == ')' && top != '(') || (cur == ']' && top != '[' || (cur == '}' && top != '{')))
                    return false;
                parentheses.pop();
            }
        }
        
        if (parentheses.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end

