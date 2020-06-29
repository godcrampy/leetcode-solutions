class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    int n = A.size();
    vector<int> sorted(n);
    int positive = 0;
    int negative = 0;

    while (positive < n && A[positive] < 0) {
      ++positive;
    }

    negative = positive - 1;
    int i = 0;
    while (positive < n || negative >= 0) {
      int a = positive < n ? A[positive] * A[positive] : INT_MAX;
      int b = negative >= 0 ? A[negative] * A[negative] : INT_MAX;

      if (a < b) {
        sorted[i++] = a;
        ++positive;
      } else {
        sorted[i++] = b;
        --negative;
      }
    }

    return sorted;
  }
};