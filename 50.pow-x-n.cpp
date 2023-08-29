/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, long long n) {
        if (x == 0)
            return 0;
        if (n == 0 || x == 1)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        double temp = myPow(x, n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else
            return temp * temp * x;
    }
};
// @lc code=end

