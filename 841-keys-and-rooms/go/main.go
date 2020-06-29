package main

func canVisitAllRooms(rooms [][]int) bool {
	unvisited := make(map[int]bool)
	visited := make(map[int]bool)

	unvisited[0] = true

	for len(unvisited) != 0 {
		visiting := -1
		for k, v := range unvisited {
			if v {
				visiting = k
				break
			}
		}

		delete(unvisited, visiting)
		visited[visiting] = true
		for _, i := range rooms[visiting] {
			if !visited[i] {
				unvisited[i] = true
			}
		}
	}

	return len(visited) == len(rooms)
}
