class Solution {
   public:
    bool isValid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    int r[4] = {1, 0, -1, 0};
    int c[4] = {0, 1, 0, -1};

    int solve(int row, int col, int n, int m, vector<vector<int>>& vis,
              vector<vector<int>>& grid) {
        // if()
        queue<pair<int, int>> q;
        int size = 1;
        q.push({row, col});
        vis[row][col] = 1;
        while (!q.empty()) {
            int rrr = q.front().first;
            int ccc = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int rr = rrr + r[i];
                int cc = ccc + c[i];
                if (isValid(rr, cc, n, m) && grid[rr][cc] == 1 && vis[rr][cc] == -1) {
                    q.push({rr, cc});
                    size++;
                    vis[rr][cc] = 1;
                }
            }
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int res = 0;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    res = max(res, solve(i, j, n, m, vis, grid));
                }
            }
        }
        return res;
    }
};
