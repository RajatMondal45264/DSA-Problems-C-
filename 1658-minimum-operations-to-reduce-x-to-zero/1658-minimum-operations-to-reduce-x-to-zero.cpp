class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        int target = total - x;

        if (target < 0) return -1;

        int left = 0;
        int curr = 0;
        int maxLen = -1;

        // Step 3: sliding window se longest block dhoondo
        for (int right = 0; right < n; right++) {
            curr += nums[right];

            while (curr > target) {
                curr -= nums[left];
                left++;
            }

            if (curr == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        if (maxLen == -1) return -1;
        return n - maxLen;
    }
};