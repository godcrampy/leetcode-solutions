class Solution {
  public boolean isPalindrome(String s) {
    int l = 0;
    int r = s.length() - 1;

    while (l <= r) {
      while (l < s.length() && !isAlphaNum(s.charAt(l))) {
        ++l;
      }

      while (r >= 0 && !isAlphaNum(s.charAt(r))) {
        --r;
      }

      if (l > r) {
        return true;
      }

      if (toLower(s.charAt(l)) != toLower(s.charAt(r))) {
        return false;
      }

      ++l;
      --r;
    }

    return true;
  }

  boolean isAlphaNum(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
      return (char) ((int) c + (int) ('a') - (int) ('A'));
    }
    return c;
  }
}
