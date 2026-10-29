class Solution {
public:
    int r, c;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,-1,1};

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int closedIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> q;

        // ---- Step 1: Boundary se BFS (open islands ko 1 kar do) ----
        // First row
        for (int j = 0; j < c; j++)
            if (grid[0][j] == 0) { q.push({0,j}); grid[0][j] = 1; }

        // First column
        for (int i = 1; i < r; i++)
            if (grid[i][0] == 0) { q.push({i,0}); grid[i][0] = 1; }

        // Last row
        for (int j = 1; j < c; j++)
            if (grid[r-1][j] == 0) { q.push({r-1,j}); grid[r-1][j] = 1; }  // ✅ fix

        // Last column
        for (int i = 1; i < r-1; i++)
            if (grid[i][c-1] == 0) { q.push({i,c-1}); grid[i][c-1] = 1; }  // ✅ fix

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();          // ✅ pop
            for (int k = 0; k < 4; k++) {
                int ni = i + row[k], nj = j + col[k];
                if (valid(ni,nj) && grid[ni][nj] == 0) {
                    grid[ni][nj] = 1;
                    q.push({ni,nj});
                }
            }
        }

        // ---- Step 2: Bacha hua 0 = closed island; BFS karke count ----
        int island = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    island++;
                    // BFS is component ko 1 kar do
                    queue<pair<int,int>> qq;
                    qq.push({i,j});
                    grid[i][j] = 1;

                    while (!qq.empty()) {
                        auto [x, y] = qq.front(); qq.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + row[k], ny = y + col[k];
                            if (valid(nx,ny) && grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                                qq.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }

        return island;
    }
};