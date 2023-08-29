/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            mp[cur].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(unordered_map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            res.push_back(it -> second);
        }
        return res;
    }
};
// @lc code=end

