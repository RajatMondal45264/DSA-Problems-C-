class Solution {
public:
    int stoneGameVIII(vector<int>& stones)
    {
         int n = stones.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = stones[0];

        for(int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        vector<int> dp(n, 0);

        // Base case
        dp[n - 1] = prefixSum[n - 1];
        
        for(int idx = n - 2; idx >= 1; idx--)
        {
            int take = prefixSum[idx] - dp[idx + 1];

            int skip = dp[idx + 1];

            dp[idx] = max(take, skip);
        }

        return dp[1];
    }
};