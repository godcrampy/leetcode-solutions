class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int W) {
    int n = hand.size();
    if (n % W != 0) {
      return false;
    }

    multiset<int> s(hand.begin(), hand.end());

    while (!s.empty()) {
      int expected = *s.begin();
      for (int j = 0; j < W; ++j) {
        if (s.find(expected + j) == s.end()) {
          return false;
        } else {
          s.erase(s.find(expected + j));
        }
      }
    }

    return true;
  }
};
