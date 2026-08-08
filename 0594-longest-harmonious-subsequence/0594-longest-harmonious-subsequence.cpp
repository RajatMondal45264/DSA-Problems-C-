class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int start = 0;
        int end = 0;

        sort(nums.begin(),nums.end());

        for(int end = 0; end < n;end++)
        {
            while(nums[end] - nums[start] > 1)
            {
                start++;
            }

            if(nums[end] - nums[start] == 1)
            {
                count = max(count, end - start + 1);
            }
        }

        return count;
    }
};