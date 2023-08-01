/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // assume nums1 is shorter
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
    // find the right cutting
        int low = 0, high = nums1.size();
        int k = (nums1.size() + nums2.size() + 1) >> 1;
        int nums1MidInd = 0, nums2MidInd = 0;

        while (low <= high) 
        {
            // nums1:  ...... nums1[nums1Mid-1] | nums1[nums1Mid] ......
		    // nums2:  ...... nums2[nums2Mid-1] | nums2[nums2Mid] ......
            nums1MidInd = low + ((high-low) >> 1);
            nums2MidInd = k - nums1MidInd;

            if (nums1MidInd > 0 && nums1[nums1MidInd-1] > nums2[nums2MidInd])
            {
                // move left
                high = nums1MidInd - 1;
            }
            else if (nums1MidInd < nums1.size() && nums1[nums1MidInd] < nums2[nums2MidInd-1])
            {
                // move right
                low = nums1MidInd + 1;
            }
            else
            {
                // cutting finished
                break;
            }
        }

    // merge
        int midLeft = 0, midRight = 0;
        if (nums1MidInd == 0)
            midLeft = nums2[nums2MidInd-1];
        else if (nums2MidInd == 0)
            midLeft = nums1[nums1MidInd-1];
        else
            midLeft = nums1[nums1MidInd-1] > nums2[nums2MidInd-1] ? nums1[nums1MidInd-1] : nums2[nums2MidInd-1];

        // odd length
        if ((nums1.size() + nums2.size()) & 1 == 1)
            return (double)midLeft;

        if (nums1MidInd == nums1.size())
            midRight = nums2[nums2MidInd];
        else if (nums2MidInd == nums2.size())
            midRight = nums1[nums1MidInd];
        else
            midRight = nums1[nums1MidInd] < nums2[nums2MidInd] ? nums1[nums1MidInd] : nums2[nums2MidInd];

        return (double)(midLeft + midRight) / 2;
    }
};
// @lc code=end

