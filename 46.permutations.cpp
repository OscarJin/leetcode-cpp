/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        bool* used = new bool[nums.size()];
        memset(used, false, sizeof(bool) * nums.size());
        vector<int> cur;
        findPermutation(nums, 0, cur, used);
        delete [] used;
        return res;
    }

private:
    vector<vector<int>> res;

    void findPermutation(vector<int>& nums, int ind, vector<int>& cur, bool* used)
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
                used[i] = true;
                cur.push_back(nums[i]);
                findPermutation(nums, ind + 1, cur, used);
                cur.erase(cur.end() - 1);
                used[i] = false;
            }
        }
    }
};
// @lc code=end

