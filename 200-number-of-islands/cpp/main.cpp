class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        count += bfs(grid, i, j);
      }
    }

    return count;
  }

  int bfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
        grid[i][j] == '0') {
      return 0;
    }

    grid[i][j] = '0';
    bfs(grid, i - 1, j);
    bfs(grid, i + 1, j);
    bfs(grid, i, j - 1);
    bfs(grid, i, j + 1);
    return 1;
  }
};