/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            while (i != n - 1 && end >= intervals[i+1][0])
            {
                end = end > intervals[i+1][1] ? end : intervals[i+1][1];
                i++;
            }
            vector<int> cur = {start, end};
            res.push_back(cur);
        }

        return res;
    }

    
};
// @lc code=end

