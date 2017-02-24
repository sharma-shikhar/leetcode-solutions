class Solution {
    bool withinBounds(vector<vector<char>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() &&
            j >= 0 && j < grid[0].size();
    }
    
    bool flood(vector<vector<char>>& grid, int i, int j) {
        if (!withinBounds(grid, i, j))
            return false;
        
        if (grid[i][j] != '1')
            return false;
        
        grid[i][j] = '0';
        
        flood(grid, i-1, j);
        flood(grid, i+1, j);
        flood(grid, i, j-1);
        flood(grid, i, j+1);
        
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (flood(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};