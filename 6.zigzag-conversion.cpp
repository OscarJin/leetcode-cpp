/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string* zigzag = new string[numRows];

        int down = 0, up = numRows - 2;

        for (int i = 0; i < s.length();)
        {
            if (down != numRows)
            {
                zigzag[down] += s[i];
                down++; i++;
            }
            else if (up > 0)
            {
                zigzag[up] += s[i];
                up--; i++;
            }
            else
            {
                up = numRows - 2;
                down = 0;
            }
        }

        string result = "";
        for (int i = 0; i < numRows; i++)
        {
            result += zigzag[i];
        }
        delete[] zigzag;
        return result;
    }
};
// @lc code=end

