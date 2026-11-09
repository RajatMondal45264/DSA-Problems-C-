class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        
        set<int> available;
        for (int i = 0; i < k; ++i) available.insert(i);
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) 
        {
            long long time = arrival[i];
            
            // Free all servers that have completed by this time
            while (!busy.empty() && busy.top().first <= time) 
            {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If no servers available, drop the request
            if (available.empty()) continue;
            
            int target = i % k;
            
            auto it = available.lower_bound(target);
            if (it == available.end()) 
            {
                it = available.begin();
            }
            
            int server = *it;
            available.erase(it);
            
            busy.push({time + load[i], server});
            count[server]++;
        }
        
        int maxCount = *max_element(count.begin(), count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) 
        {
            if (count[i] == maxCount) result.push_back(i);
        }

        return result;
    }
};