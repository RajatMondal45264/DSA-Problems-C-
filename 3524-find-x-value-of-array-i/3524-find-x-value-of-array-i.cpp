class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCount(k, 0);

        for(int i = 0; i < n; i++)
        {
            // index i pe end hone wale all subarrays
            vector<long long> currCount(k, 0);

            int currElementRem = nums[i] % k;
            currCount[currElementRem]++;

            for(int oldRem = 0; oldRem < k; oldRem++)
            {
                int newRem = ((long long)oldRem * nums[i]) % k;

                currCount[newRem] += prevCount[oldRem];
            }

            prevCount = currCount;

            for(int x = 0; x < k; x++)
            {
                result[x] += prevCount[x];
            }
        }

        return result;
    }
};