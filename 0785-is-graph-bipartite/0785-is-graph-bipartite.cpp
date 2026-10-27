class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n,-1);
        queue<int>q;

        for(int i = 0; i< n; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                q.push(i);
            }

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int j = 0; j < graph[node].size(); j++)
                {
                    int adj = graph[node][j];

                    if(color[adj] == -1)
                    {
                        color[adj] = 1 - color[node];
                        q.push(adj);
                    }
                    else if(color[adj] == color[node])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};