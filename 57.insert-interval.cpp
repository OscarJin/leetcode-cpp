/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 0)
        {
            res.push_back(newInterval);
            return res;
        }

        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
            newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
            i++;
        }
        res.push_back(newInterval);

        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
// @lc code=end

