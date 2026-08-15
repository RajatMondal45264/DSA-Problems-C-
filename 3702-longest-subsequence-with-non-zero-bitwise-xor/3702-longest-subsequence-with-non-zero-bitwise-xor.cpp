class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int result = 0;
        int ans = 0;
        int n = nums.size();

        while(end < n)
        {
            result ^= nums[end];
            end++;
        }

        if(result !=0)
        {
            ans = n;
        }
        else
        {
            while(start < n && nums[start] == 0)
            {
                start++;
            }

            if(start < n)
            {
                ans = n -1;
            }
            else
            {
                ans = 0;
            }
        }

        return ans;
    }
};