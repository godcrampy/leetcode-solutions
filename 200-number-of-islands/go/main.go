package main

func numIslands(grid [][]byte) int {
	count := 0
	for i, _ := range grid {
		for j, _ := range grid[i] {
			count += bfs(&grid, i, j)
		}
	}
	return count
}

func bfs(grid *[][]byte, i int, j int) int {
	if i < 0 || j < 0 || i >= len(*grid) || j >= len((*grid)[i]) || (*grid)[i][j] == uint8('0') {
		return 0
	}

	(*grid)[i][j] = uint8('0')

	bfs(grid, i-1, j)
	bfs(grid, i+1, j)
	bfs(grid, i, j-1)
	bfs(grid, i, j+1)

	return 1
}
