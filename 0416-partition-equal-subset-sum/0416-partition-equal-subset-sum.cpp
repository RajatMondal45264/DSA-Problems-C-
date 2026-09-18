class Solution {
public:

    bool solve(vector<int>& nums, int index, int sum, int target,
               vector<vector<int>>& dp)
    {
        if(sum == target)
        {
            return true;
        }

        if(index == nums.size() || sum > target)
        {
            return false;
        }

        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        
        if(solve(nums, index + 1, sum + nums[index], target, dp))
        {
            return dp[index][sum] = true;
        }

        // Not take current element
        if(solve(nums, index + 1, sum, target, dp))
        {
            return dp[index][sum] = true;
        }

        return dp[index][sum] = false;
    }

    bool canPartition(vector<int>& nums)
    {
        int total = 0;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++)
        {
            total = total + nums[i];
        }

        if(total % 2 != 0)
        {
            return false;
        }

        int target = total / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(nums, 0, 0, target, dp);
    }
};