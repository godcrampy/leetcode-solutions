class Solution {
  public int[] sortedSquares(int[] A) {
    int positive = 0;
    int negative = 0;

    while (positive < A.length && A[positive] < 0) {
      ++positive;
    }

    negative = positive - 1;
    int[] sorted = new int[A.length];
    int i = 0;
    while (positive < A.length || negative >= 0) {
      int a = positive < A.length ? A[positive] * A[positive] : Integer.MAX_VALUE;
      int b = negative >= 0 ? A[negative] * A[negative] : Integer.MAX_VALUE;

      if (a < b) {
        sorted[i++] = a;
        positive++;
      } else {
        sorted[i++] = b;
        negative--;
      }
    }

    return sorted;
  }
}
