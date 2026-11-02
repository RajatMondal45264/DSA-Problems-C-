class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];

        for(int i = 0; i< relations.size();i++)
        {
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        vector<int>Indeg(n,0);
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j <adj[i].size(); j++)
            {
                Indeg[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i = 0;i <n; i++)
        {
            if(Indeg[i] == 0)
            {
                q.push(i);
            }
        }

        // Maximum Time to complete Previous Node/ courses 
        vector<int>CourseTime(n,0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int j = 0;j < adj[node].size();j++)
            {
                Indeg[adj[node][j]]--;
                if(!Indeg[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }

                CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]],CourseTime[node]+time[node]);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans,CourseTime[i]+time[i]);
        }

        return ans;
    }
};