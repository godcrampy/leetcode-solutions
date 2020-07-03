class Solution {
  public boolean isNStraightHand(int[] hand, int W) {
    int n = hand.length;

    if (n % W != 0) {
      return false;
    }

    Queue<Integer> q = new PriorityQueue<>();

    for (int i = 0; i < n; ++i) {
      q.add(hand[i]);
    }

    while (!q.isEmpty()) {
      int expected = q.peek();
      for (int j = 0; j < W; ++j) {
        if (!q.contains(expected + j)) {
          return false;
        } else {
          q.remove(expected + j);
        }
      }
    }

    return true;
  }
}
