// BFS: find distance, track fresh count
//  O(m x n)
//  O(m x n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // find rottens
        int fresh_count = 0;
        queue<pair<int,int>> cells;
        // empty 0 -> -2
        // fresh 1 -> -1
        // rottn 2 ->  0
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = -2;
                }
                else if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    fresh_count++;
                }
                else if (grid[i][j] == 2) {
                    grid[i][j] = 0;
                    cells.push({i, j});
                }
            }
        }

        // write distances and track greatest
        int time = 0;
        while (!cells.empty()) {
            auto [r, c] = cells.front();
            cells.pop();
            int dist = grid[r][c];
            time = max(time, dist);

            vector<pair<int,int>> neibs;
            if (r > 0)
                neibs.push_back({r-1, c});
            if (r < grid.size()-1)
                neibs.push_back({r+1, c});
            if (c > 0)
                neibs.push_back({r, c-1});
            if (c < grid[0].size()-1)
                neibs.push_back({r, c+1});

            for (auto [nr, nc] : neibs) {
                if (grid[nr][nc] != -1) continue;
                grid[nr][nc] = 1 + dist;
                fresh_count--;
                cells.push({nr, nc});
            }
        }
        return fresh_count == 0 ? time : -1;
    }
};
