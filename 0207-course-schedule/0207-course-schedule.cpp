class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int p = prerequisites.size();

        vector<int>adj[numCourses];
        vector<int>Indeg(numCourses,0);

        for(int i = 0; i < p; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            Indeg[prerequisites[i][0]]++;
        }

        //kahn's algorithms
        queue<int>q;
        for(int i = 0; i< numCourses;i++)
        {
            if(!Indeg[i])
            {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for(int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if(Indeg[adj[node][j]] == 0)
                {
                    q.push(adj[node][j]);
                }
            }
        }

        return count == numCourses;
    }
}; 