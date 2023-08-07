// @before-stub-for-debug-begin
#include <map>
#include <vector>
#include <string>
#include "commoncppproblem30.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> wordsCnt;
        int len = words[0].length(), totLen = len * words.size();
        
        if (s.length() < totLen)
            return res;

        for (int i = 0; i < words.size(); i++)
            wordsCnt[words[i]]++;

        for (int i = 0; i + totLen <= s.length(); i++)
        {
            if (checkSubstring(wordsCnt, s.substr(i, totLen), len))
                res.push_back(i);
        }
        return res;
    }

private:
    bool checkSubstring(unordered_map<string, int> wordsCnt, string s, int len)
    {
        for (int i = 0; i < s.length(); i+=len)
        {
            string cur = s.substr(i, len);
            if (wordsCnt.find(cur) != wordsCnt.end())
            {
                if (--wordsCnt[cur] == -1)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

