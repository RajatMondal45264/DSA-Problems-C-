class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;

        // Step 1: poore array ka sum
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // Step 2: beech wale block ka target sum
        int target = total - x;

        // Agar x hi total se bada hai, toh possible nahi
        if (target < 0) return -1;

        int left = 0;
        int curr = 0;
        int maxLen = -1;

        // Step 3: sliding window se longest block dhoondo
        for (int right = 0; right < n; right++) {
            curr += nums[right];

            // Agar sum target se bada, left se chhota karo
            while (curr > target) {
                curr -= nums[left];
                left++;
            }

            // Agar exactly target mil gaya
            if (curr == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // Step 4: koi block nahi mila
        if (maxLen == -1) return -1;

        // Step 5: answer
        return n - maxLen;
    }
};