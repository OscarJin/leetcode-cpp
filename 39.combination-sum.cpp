/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        findcombinationSum(candidates, target, 0, cur, res);
        return res;
    }

private:
    void findcombinationSum(vector<int>& candidates, int target, int ind, vector<int>& cur, vector<vector<int>>& res)
    {
        if (target <= 0)
        {
            if (target == 0)
            {
                res.push_back(cur);
            }
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                break;
            cur.push_back(candidates[i]);
            findcombinationSum(candidates, target-candidates[i], i, cur, res);
            cur.erase(cur.end()-1);
        }
    }
};
// @lc code=end

