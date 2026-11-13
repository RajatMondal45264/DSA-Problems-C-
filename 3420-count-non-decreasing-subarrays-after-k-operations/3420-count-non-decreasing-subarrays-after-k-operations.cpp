
class Solution {
public:

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int LOG = 1;
        while ((1LL << LOG) <= n) {
            LOG++;
        }

        // Prefix sum
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Step 1: Next Greater Element
        vector<int> nge(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nge[i] = st.top();
            }

            st.push(i);
        }

        // Step 2: Binary Lifting
        vector<vector<int>> up(LOG, vector<int>(n + 1, n));

        vector<vector<long long>> cost(LOG, vector<long long>(n + 1, 0));

        // Base level: One next-greater segment
        for (int i = 0; i < n; i++) {

            int next = nge[i];

            up[0][i] = next;

            long long len = next - i;

            cost[0][i] = 1LL * nums[i] * len
                       - (pref[next] - pref[i]);
        }

        // Build larger jumps
        for (int j = 1; j < LOG; j++) {

            for (int i = 0; i < n; i++) {

                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];

                cost[j][i] = cost[j - 1][i]
                           + cost[j - 1][mid];
            }
        }

        // Step 3: Calculate window cost in O(log n)
        auto getCost = [&](int left, int right) {

            long long operations = 0;
            int pos = left;

            for (int j = LOG - 1; j >= 0; j--) {

                if (up[j][pos] <= right + 1) {

                    operations += cost[j][pos];

                    pos = up[j][pos];
                }
            }

            // Remaining partial segment
            if (pos <= right) {

                operations += 1LL * nums[pos]
                             * (right - pos + 1);

                operations -= pref[right + 1] - pref[pos];
            }

            return operations;
        };

        // Step 4: Sliding Window
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {

            while (left <= right && getCost(left, right) > k) {
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
