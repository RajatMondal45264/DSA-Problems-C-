class Solution {
public:

    int maximum(int start, int end, vector<int>& nums)
    {
        int maxi = nums[start];

        for(int i = start; i <= end; i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
            }
        }

        return maxi;
    }

    int minimum(int start, int end, vector<int>& nums)
    {
        int mini = nums[start];

        for(int i = start; i <= end; i++)
        {
            if(nums[i] < mini)
            {
                mini = nums[i];
            }
        }

        return mini;
    }

    int firstStableIndex(vector<int>& nums, int k)
    {
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int maxScore = maximum(0, i, nums);
            int minScore = minimum(i, n - 1, nums);

            if(maxScore - minScore <= k)
            {
                return i;
            }
        }

        return -1;
    }
};