// DFS: iterate starts points, explore/sum/overwrite islands
//  O(M x N)
//  O(M x N)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++)
                max_area = max(max_area, exploreIsland(grid, i, j));
        return max_area;
    }

    int exploreIsland(vector<vector<int>>& grid, int row, int col) {
        if (grid[row][col] <= 0)
            return 0;
        
        int area = grid[row][col];
        grid[row][col] = 0;

        if (row > 0)
            area += exploreIsland(grid, row-1, col);
        if (row < grid.size() - 1)
            area += exploreIsland(grid, row+1, col);
        if (col > 0)
            area += exploreIsland(grid, row, col-1);
        if (col < grid[0].size() - 1)
            area += exploreIsland(grid, row, col+1);

        return area;
    }
};
