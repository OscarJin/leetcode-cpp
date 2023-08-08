// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parentheses;
        int res = 0;
        parentheses.push(-1);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                parentheses.push(i);
            else
            {
                parentheses.pop();
                if (parentheses.size() == 0)
                    parentheses.push(i);
                else
                    res = res > i - parentheses.top() ? res : i - parentheses.top();
            }
        }
        return res;
    }
};
// @lc code=end

