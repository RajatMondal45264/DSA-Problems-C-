class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start = 0;
        int end = 0;
        int ans = 0;

        deque<int> maxDq;
        deque<int> minDq;

        while (end < nums.size()) {

            while (!maxDq.empty() && nums[maxDq.back()] < nums[end]) 
            {
                maxDq.pop_back();
            }

            maxDq.push_back(end);

            while (!minDq.empty() && nums[minDq.back()] > nums[end]) {
                minDq.pop_back();
            }

            minDq.push_back(end);

            while (nums[maxDq.front()] - nums[minDq.front()] > limit) {

                if (maxDq.front() == start) {
                    maxDq.pop_front();
                }

                if (minDq.front() == start) {
                    minDq.pop_front();
                }

                start++;
            }

            ans = max(ans, end - start + 1);

            end++;
        }

        return ans;
    }
};