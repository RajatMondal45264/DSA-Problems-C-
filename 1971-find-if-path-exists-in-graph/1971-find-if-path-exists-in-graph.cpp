class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if(source == destination)
        {
            return true;
        }

        queue<int> q;
        q.push(source);
        vector<bool> visited(n,0);
        visited[source] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int j = 0; j < adj[node].size(); j++)
            {
                int neighbor = adj[node][j];

                if(!visited[neighbor])
                {
                    if(neighbor == destination)
                    {
                        return true;
                    }

                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
