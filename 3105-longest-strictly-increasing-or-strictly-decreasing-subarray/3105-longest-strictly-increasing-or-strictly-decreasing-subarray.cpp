class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int start =  0;
        int end = 1;
        int n = nums.size();
        int ans = 1;

        while(end < n)
        {
            if(nums[end] > nums[end-1])
            {
                ans = max(ans,end-start+1);
                end++;
            }
            else
            {
                start = end;
                end++;
            }
        }

        start = 0;
        end = 1;

        while(end < n)
        {
            if(nums[end] < nums[end - 1])
            {
                ans = max(ans,end - start +1);
                end++;
            }
            else
            {
                start = end;
                end++;
            }
        }

        return ans;
    }
};