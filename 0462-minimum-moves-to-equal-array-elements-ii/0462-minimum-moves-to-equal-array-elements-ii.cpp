class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int median = nums[n / 2];   

        long long sum = 0;    

        for (int i = 0; i < n; i++) 
        {
            sum += abs(nums[i] - median);
        }
        return (int)sum;
    }
};