/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;

        if (x < 0 || x % 10 == 0)
            return false;
        
        int digit = 0;
        int rev[32];

        while (x > 0)
        {
            rev[digit++] = x % 10;
            x /= 10;
        }

        for (int i = 0, j = digit - 1; i <= j; i++, j--)
        {
            if (rev[i] != rev[j])
                return false;
        }
        return true;
    }
};
// @lc code=end

