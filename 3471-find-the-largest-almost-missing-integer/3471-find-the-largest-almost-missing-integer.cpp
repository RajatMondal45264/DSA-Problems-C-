class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // case :1
        if(k == 1)
        {
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++) 
            {
                mp[nums[i]]++;
            }

            int ans = -1;

            for (int i = 0; i < n; i++) {
                if (mp[nums[i]] == 1) {
                    ans = max(ans, nums[i]);
                }
            }

            return ans;
        }

        // case :2
        if (k == n) {
            // Subarray == array so now the largest number 
            // is in the array is the ans
            int ans = nums[0];
            for (int i = 1; i < n; i++) 
            {
                ans = max(ans, nums[i]);
            }

            return ans;
        }


        // case : 3
        int first = nums[0];
        int last = nums[n - 1];
        int ans = -1;

        int firstCount = 0;
        int lastCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == first) {
                firstCount++;
            }

            if (nums[i] == last) {
                lastCount++;
            }
        }

        if(firstCount == 1)
        {
            ans = max(ans,first);
        }

        if(lastCount == 1)
        {
            ans = max(ans, last);
        }

        return ans;
    }
};