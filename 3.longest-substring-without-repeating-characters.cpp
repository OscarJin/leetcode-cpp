/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool repeat[256];
        memset(repeat, false, sizeof(repeat));

        int left = 0; int right = 0; int length = 0;
        while(left < s.length())
        {
            if(repeat[s[right]])
            {
                repeat[s[left]] = false;
                left++;
            }
            else
            {
                repeat[s[right]] = true;
                right++;
            }
            length = length > (right - left) ? length : (right - left);

            if(left+length >= s.length() || right >= s.length())
                break;
        }

        return length;
    }
};
// @lc code=end

