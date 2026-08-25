class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        int max = nums[0];

        // Find maximum element
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > max)
            {
                max = nums[i];
            }
        }

        // Check multiples of k
        for(int i = k; i <= max + k; i += k)
        {
            bool found = false;

            for(int j = 0; j < n; j++)
            {
                if(nums[j] == i)
                {
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                return i;
            }
        }

        return -1;
    }
};