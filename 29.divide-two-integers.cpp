// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem29.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;
        bool neg = (dividend < 0) ^ (divisor < 0);
        long long longDividend = abs((long long) dividend);
        long long longDivisor = abs((long long) divisor);
        
        if (dividend == 0)
            return 0;

        long long sum = 0, step = 1, multiple = longDivisor;
        while (step >= 1)
        {
            if (sum + multiple <= longDividend)
            {
                sum += multiple;
                res += step;
                step <<= 1;
                multiple <<= 1;
            }
            else
            {
                step >>= 1;
                multiple >>= 1;
            }
        }

        res = neg ? res * (-1) : res;
        res = res > INT_MAX ? INT_MAX : res;
        res = res < INT_MIN ? INT_MIN : res;
        return (int)res;
    }
};
// @lc code=end

