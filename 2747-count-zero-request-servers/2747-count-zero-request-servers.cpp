class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        
        int q = queries.size();
        vector<pair<int,int>> qs(q);
        for (int i = 0; i < q; i++) {
            qs[i] = {queries[i], i};
        }
        sort(qs.begin(), qs.end());

        vector<int> ans(q);
        unordered_map<int,int> freq;   // server_id -> count in current window
        int activeServers = 0;

        int l = 0, r = 0;
        int m = logs.size();

        // Step 3: process each query in increasing time order
        for (int i = 0; i < q; i++) {
            int t = qs[i].first;
            int idx = qs[i].second;

            int start = t - x;
            int end   = t;

            // expand right boundary
            while (r < m && logs[r][1] <= end) {
                int srv = logs[r][0];
                if (freq[srv] == 0) activeServers++;
                freq[srv]++;
                r++;
            }

            // shrink left boundary
            while (l < r && logs[l][1] < start) {
                int srv = logs[l][0];
                freq[srv]--;
                if (freq[srv] == 0) activeServers--;
                l++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};