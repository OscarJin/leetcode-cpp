/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // DFS
        if (digits == "")
            return {};
        
        findCombinations(digits, 0, "");
        return res;
    }

private:
    string letterMap[10] = {
        " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> res;

    void findCombinations(string& digits, int ind, string s)
    {
        if (ind == digits.length())
        {
            res.push_back(s);
            return;
        }

        string curLetters = letterMap[digits[ind]-'0'];
        for (int i = 0; i < curLetters.length(); i++)
        {
            findCombinations(digits, ind+1, s + curLetters[i]);
        }
    }
};
// @lc code=end

