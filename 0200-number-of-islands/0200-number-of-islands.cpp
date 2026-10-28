#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r;
    int c;
    int row[4] = {-1, 1, 0, 0};   // up, down, left, right
    int col[4] = {0, 0, -1, 1};

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++)   // <-- 4, not 8
                        {
                            int ni = x + row[k];
                            int nj = y + col[k];

                            if (valid(ni, nj) && grid[ni][nj] == '1')
                            {
                                grid[ni][nj] = '0';   // mark visited on push
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};