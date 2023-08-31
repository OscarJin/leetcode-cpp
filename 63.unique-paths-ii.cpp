// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem63.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        bool canArrive = true;
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 1)
            {
                canArrive = false;
                obstacleGrid[0][j] = 0;
            }
            else if (!canArrive)
                obstacleGrid[0][j] = 0;
            else
                obstacleGrid[0][j] = 1;
        }

        canArrive = true;
        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                canArrive = false;
                obstacleGrid[i][0] = 0;
            }
            else if (!canArrive)
                obstacleGrid[i][0] = 0;
            else
                obstacleGrid[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};
// @lc code=end

