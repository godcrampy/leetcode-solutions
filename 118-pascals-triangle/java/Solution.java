class Solution {
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> res = new ArrayList<>();
    if (numRows == 0) {
      return res;
    }
    res.add(new ArrayList<>(Arrays.asList(1))); // {{1}}

    for (int i = 2; i <= numRows; ++i) {
      List<Integer> last = res.get(res.size() - 1);
      List<Integer> next = new ArrayList<>(i);
      for (int j = 0; j < i; ++j) {
        next.add(get(last, j - 1) + get(last, j));
      }
      res.add(next);
    }

    return res;
  }

  public int get(List<Integer> a, int i) {
    if (i < 0 || i >= a.size()) {
      return 0;
    }
    return a.get(i);
  }
}
