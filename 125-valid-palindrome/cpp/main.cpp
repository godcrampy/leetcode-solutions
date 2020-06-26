class Solution {
 public:
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;

    while (l <= r) {
      while (l < s.length() && !isAlphaNum(s[l])) {
        ++l;
      }

      while (r >= 0 && !isAlphaNum(s[r])) {
        --r;
      }

      if (l > r) {
        return true;
      }

      if (toLower(s[l]) != toLower(s[r])) {
        return false;
      }

      ++l;
      --r;
    }

    return true;
  }

  bool isAlphaNum(char c) {
    return (c >= '0' && c <= '9') ||
           ((toLower(c) >= 'a') && (toLower(c) <= 'z'));
  }

  char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
      return c + 'a' - 'A';
    }
    return c;
  }
};
