class Solution {
  public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    HashSet<Integer> visited = new HashSet<>(), unvisited = new HashSet<>();
    unvisited.add(0);

    while (!unvisited.isEmpty()) {
      int visiting = unvisited.iterator().next();
      unvisited.remove(visiting);
      visited.add(visiting);

      for (int to_visit : rooms.get(visiting)) {
        if (!visited.contains(to_visit)) {
          unvisited.add(to_visit);
        }
      }
    }

    return visited.size() == rooms.size();
  }
}
