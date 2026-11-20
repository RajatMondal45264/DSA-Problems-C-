class Solution {
public:

    vector<vector<int>> dp;
    int n;

    
    int findMethod(vector<int> &nums, int start, int target)
    {
        int low = start;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if(low < nums.size() && nums[low] == target)
        {
            return low;
        }

        return -1;
    }


    int solve(int i, int inc, vector<int> &nums)
    {
        if(dp[i][inc] != -1)
        {
            return dp[i][inc];
        }

        int currVal = nums[i] + inc;
        int len = 1;

        int j = findMethod(nums, i + 1, currVal + 1);

        if(j != -1)
        {
            len = max(len, 1 + solve(j, 0, nums));
        }

        j = findMethod(nums, i + 1, currVal);

        if(j != -1)
        {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return dp[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        
        n = nums.size();

        sort(nums.begin(), nums.end());

        dp.assign(n, vector<int>(2, -1));

        int result = 1;

        for(int i = 0; i < n; i++)
        {
            result = max(result, solve(i, 0, nums));
            result = max(result, solve(i, 1, nums));
        }

        return result;
    }
};
