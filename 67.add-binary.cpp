// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem67.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.length(), bLen = b.length();
        if (bLen > aLen)
        {
            swap(a, b);
            swap(aLen, bLen);
        }
        
        int r = 0;
        for (int i = aLen - 1, j = bLen - 1; i >= 0; i--, j--)
        {
            if (j < 0)
            {
                int cur = ((a[i] - '0') + r) % 2;
                r = ((a[i] - '0') + r) / 2;
                a[i] = cur + '0';
            }
            else
            {
                int cur = ((a[i] - '0') + (b[j] - '0') + r) % 2;
                r = ((a[i] - '0') + (b[j] - '0') + r) / 2;
                a[i] = cur + '0';
            }
        }
        if (r == 1)
            a.insert(0, "1");
        return a;
    }
};
// @lc code=end

