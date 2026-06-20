// BFS
//  O(M x N)
//  O(M x N)
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Enqueue chest cells
        queue<pair<int,int>> cells;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++)
                if (grid[i][j] == 0)
                    cells.push({i, j});

        //  BFS
        while (!cells.empty()) {
            auto [r, c] = cells.front();
            cells.pop();
            // Find neighboring land cells
            vector<pair<int,int>> neibs;
            if (r > 0 && grid[r-1][c] == INT_MAX)
                neibs.push_back({r-1, c});
            if (r < grid.size()-1 && grid[r+1][c] == INT_MAX)
                neibs.push_back({r+1, c});
            if (c > 0 && grid[r][c-1] == INT_MAX)
                neibs.push_back({r, c-1});
            if (c < grid[0].size()-1 && grid[r][c+1] == INT_MAX)
                neibs.push_back({r, c+1});

            // 2. set dist for next cells and enqueue
            for (auto [nr, nc] : neibs) {
                cells.push({nr, nc});
                grid[nr][nc] = grid[r][c]+1;
            }
        }

    }
};
