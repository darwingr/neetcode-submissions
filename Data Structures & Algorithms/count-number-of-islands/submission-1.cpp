// DFS with set memo & rewrite
//  O(NxM * 4)
//  O(NxM)
class Solution {
    int islands;
public:
    int numIslands(vector<vector<char>>& grid) {
        islands = 0;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++)
                if (exploreIsland(grid, i, j))
                    islands++;
        return islands;
    }

    bool exploreIsland(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size())
            return false;
        if (col < 0 || col >= grid[0].size())
            return false;

        if (grid[row][col] == '0')
            return false;
        
        grid[row][col] = '0';
        exploreIsland(grid, row+1, col);
        exploreIsland(grid, row-1, col);
        exploreIsland(grid, row,   col-1);
        exploreIsland(grid, row,   col+1);
        return true;
    }
};
