class Solution {
  public String toLowerCase(String str) {
    char[] a = str.toCharArray();

    for (int i = 0; i < a.length; ++i) {
      if (a[i] >= 'A' && a[i] <= 'Z') {
        a[i] += 'a' - 'A';
      }
    }

    return new String(a);
  }
}
