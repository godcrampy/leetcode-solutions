class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    // ab#c => abc
    // ad#c => adc
    int l = S.length() - 1;
    int r = T.length() - 1;
    int s_skips = 0;
    int t_skips = 0;

    // a##c, #a#c, l = 3, r = 3
    while (l >= 0 || r >= 0) {
      while ((l >= 0) && (s_skips > 0 || S[l] == '#')) {
        if (S[l] == '#') {
          ++s_skips;
        } else {
          --s_skips;
        }
        --l;
      }

      while ((r >= 0) && (t_skips > 0 || T[r] == '#')) {
        if (T[r] == '#') {
          ++t_skips;
        } else {
          --t_skips;
        }
        --r;
      }

      if (l < 0 && r < 0) {
        return true;
      }

      if (l < 0 || r < 0) {
        return false;
      }

      // both >= 0
      if (S[l] != T[r]) {
        return false;
      }

      --l;
      --r;
    }

    return true;
  }
};
