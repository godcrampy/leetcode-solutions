class Solution {
  public boolean isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    return x == reverseInt(x);
  }

  public int reverseInt(int x) {
    int rev = 0;

    while (x > 0) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }

    return rev;
  }
}
