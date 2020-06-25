class Solution {
  public int reverse(int x) {
    long rev = 0;
    boolean negative = x < 0;
    x = Math.max(x, -1 * x);

    while (x > 0) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }

    if (negative) {
      rev *= -1;
    }

    return (rev <= Integer.MAX_VALUE && rev >= Integer.MIN_VALUE) ? (int) rev : 0;
  }
}
