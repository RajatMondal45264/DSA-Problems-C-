class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        deque<int> deq;

        vector<long long> cumulativeSum(n + 1, 0);

        int result = INT_MAX;

        int j = 0;

        while(j < n)
        {
            cumulativeSum[j + 1] =
                cumulativeSum[j] + nums[j];

            j++;
        }

        j = 0;

        while(j <= n)
        {
            // Check if current prefix itself gives
            // a valid subarray with some previous prefix
            while(!deq.empty() &&
                  cumulativeSum[j] - cumulativeSum[deq.front()] >= k)
            {
                result = min(result, j - deq.front());

                deq.pop_front();
            }

            // Maintain increasing cumulative sum
            while(!deq.empty() &&
                  cumulativeSum[j] <= cumulativeSum[deq.back()])
            {
                deq.pop_back();
            }

            deq.push_back(j);

            j++;
        }

        if(result == INT_MAX)
        {
            return -1;
        }

        return result;
    }
};