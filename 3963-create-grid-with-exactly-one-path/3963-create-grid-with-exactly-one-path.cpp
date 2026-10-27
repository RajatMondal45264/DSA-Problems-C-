class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;

        if (m == 1 || n == 1) {
            for (int i = 0; i < m; i++) {
                grid.push_back(string(n, '.'));
            }
            return grid;
        }
        
        grid.push_back(string(n, '.'));
        for (int i = 1; i < m; i++) {
            string row(n, '#');
            row[n - 1] = '.';
            grid.push_back(row);
        }
        
        return grid;
    }
};