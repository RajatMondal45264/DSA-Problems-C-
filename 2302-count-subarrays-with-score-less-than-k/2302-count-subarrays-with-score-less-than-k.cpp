class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long total = 0;
        long long start = 0;
        long long end = 0;
        long long sum = 0;
        int n = nums.size();

        while(end < n)
        {
            sum = sum + nums[end];

            // jab sum k se bada ho jaye tou window size ko ghatao 
            while(sum * (end - start + 1) >= k && start <= end)
            {
                sum = sum - nums[start];
                start++;
            }

            total += end - start + 1;
            end++;
        }

        return total;
    }
};