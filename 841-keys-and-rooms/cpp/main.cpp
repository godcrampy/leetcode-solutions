class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> unvisited, visited;
    unvisited.insert(0);

    while (!unvisited.empty()) {
      int visiting = *unvisited.begin();
      unvisited.erase(unvisited.begin());
      visited.insert(visiting);
      for (int next : rooms[visiting]) {
        if (visited.find(next) == visited.end()) unvisited.insert(next);
      }
    }

    return visited.size() == rooms.size();
  }
};
