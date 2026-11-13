
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // Stores {prefix maximum, count}
        deque<pair<int, int>> dq;

        int right = n - 1;

        long long operations = 0;
        long long ans = 0;

        // Move left from right to left
        for (int left = n - 1; left >= 0; left--) {

            int x = nums[left];
            int cnt = 1;

            // Add the new element from the left
            while (!dq.empty() && dq.front().first <= x) {

                operations += 1LL *
                    (x - dq.front().first) * dq.front().second;

                cnt += dq.front().second;

                dq.pop_front();
            }

            dq.push_front({x, cnt});

            // If operations exceed k, remove from right
            while (operations > k) {

                operations -= dq.back().first - nums[right];

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                right--;
            }

            // Count valid subarrays starting at left
            ans += right - left + 1;
        }

        return ans;
    }
};
