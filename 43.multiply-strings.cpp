/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int len1 = num1.length(), len2 = num2.length();
        int* multiple = new int[len1 + len2];
        memset(multiple, 0, sizeof(int) * (len1 + len2));

        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
                multiple[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
        }

        for (int i = len1 + len2 - 1; i > 0; i--)
        {
            multiple[i - 1] += multiple[i] / 10;
            multiple[i] %= 10;
        }

        string res = "";
        for (int i = 0; i < len1 + len2; i++)
        {
            if (i == 0 && multiple[i] == 0)
                continue;
            res += (multiple[i] + '0');
        }

        delete[] multiple; 
        return res;
    }
};
// @lc code=end

