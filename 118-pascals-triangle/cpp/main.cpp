class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0) return {};
    vector<vector<int>> res = {{1}};

    for (int i = 2; i <= numRows; ++i) {
      vector<int> temp(i);
      for (int j = 0; j < i; ++j) {
        temp[j] = get(res.back(), j - 1) + get(res.back(), j);
      }
      res.push_back(temp);
    }

    return res;
  }

  int get(const vector<int> &v, int i) {
    if (i < 0 || i >= v.size()) {
      return 0;
    }
    return v[i];
  }
};