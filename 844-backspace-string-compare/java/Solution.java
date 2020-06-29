class Solution {
  public boolean backspaceCompare(String S, String T) {
    int l = S.length() - 1;
    int r = T.length() - 1;
    int sSkips = 0;
    int tSkips = 0;

    while (l >= 0 || r >= 0) {
      while (l >= 0 && (S.charAt(l) == '#' || sSkips > 0)) {
        if (S.charAt(l) == '#') {
          ++sSkips;
        } else {
          --sSkips;
        }
        --l;
      }

      while (r >= 0 && (T.charAt(r) == '#' || tSkips > 0)) {
        if (T.charAt(r) == '#') {
          ++tSkips;
        } else {
          --tSkips;
        }
        --r;
      }

      if (l < 0 && r < 0) {
        return true;
      }

      if (l < 0 || r < 0) {
        return false;
      }

      if (T.charAt(r) != S.charAt(l)) {
        return false;
      }

      --l;
      --r;
    }

    return true;
  }
}
