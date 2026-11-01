class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int sum = 0;

        for(int i = 0; i< n; i++)
        {
            if(nums[i] < mini)
            {
                mini = nums[i];
            }
        }

        for(int i = 0; i< n; i++)
        {
            sum = sum + (nums[i] - mini);
        }

        return sum;
    }
};