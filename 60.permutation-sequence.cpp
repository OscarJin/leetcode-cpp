// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem60.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        bool* used = new bool[n];
        memset(used, false, n);
        int temp = n;
        while (n > 0)
        {
            int p = calcPermutation(n - 1);
            int r = k / p;
            k %= p;
            if (k == 0)
            {
                r--; 
                k += p;
            }
            res += (find(temp, r + 1, used) + '0');
            n--;
        }

        delete [] used;
        return res;
    }

private:
    int calcPermutation(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        return n * calcPermutation(n - 1);
    }

    int find(int n, int k, bool* used)
    {
        // find k-th unused in [1, n]
        if (k == 0)
            k = 1;
        
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (used[i])
                continue;
            else if (cnt == k)
            {
                used[i] = true;
                return i + 1;
            }
            else
                cnt++;
        }
        return 0;
    }
};
// @lc code=end

