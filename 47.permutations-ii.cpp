/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        bool* used = new bool[nums.size()];
        memset(used, false, sizeof(bool) * nums.size());
        vector<int> cur;
        sort(nums.begin(), nums.end());
        findPermutation2(nums, 0, cur, used);
        delete [] used;
        return res;
    }

private:
    vector<vector<int>> res;

    void findPermutation2(vector<int>& nums, int ind, vector<int>& cur, bool* used)
    {
        if (ind == nums.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                    continue;
                used[i] = true;
                cur.push_back(nums[i]);
                findPermutation2(nums, ind + 1, cur, used);
                cur.erase(cur.end() - 1);
                used[i] = false;
            }
        }
    }
};
// @lc code=end

