/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool signRead = false, whitespaceAllowed = true;
        bool sign = true;   // + true; - false
        long long int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == ' ' && whitespaceAllowed)
                continue;
            if (!signRead)
            {
                if (c == '+')
                {
                    signRead = true;
                    sign = true;
                    whitespaceAllowed = false;
                    continue;
                }
                else if (c == '-')
                {
                    signRead = true;
                    sign = false;
                    whitespaceAllowed = false;
                    continue;
                }
            }
            if (c < '0' || c > '9')
                break;
            
            signRead = true; whitespaceAllowed = false;
            
            int digit = (int)(c-'0');
            if (result > INT_MAX/10 || (result == INT_MAX/10 && digit > 7))
                return INT_MAX;
            if (result < INT_MIN/10 || (result == INT_MIN/10 && digit > 7))
                return INT_MIN;

            result = sign ? result * 10 + digit : result * 10 - digit;
        }
        return (int)result;
    }
};
// @lc code=end

