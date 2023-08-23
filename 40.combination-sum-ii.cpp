/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (i > ind && candidates[i] == candidates[i-1])
                continue;
            if (candidates[i] > target)
                break;
            cur.push_back(candidates[i]);
            findcombinationSum(candidates, target-candidates[i], i+1, cur, res);
            cur.erase(cur.end()-1);
        }
    }
};
// @lc code=end

