class Solution {
  public int findDuplicate(int[] nums) {
    int s = 0;
    int f = 0;
    s = nums[s];
    f = nums[nums[f]];

    while (s != f) {
      s = nums[s];
      f = nums[nums[f]];
    }

    s = 0;

    while (s != f) {
      s = nums[s];
      f = nums[f];
    }

    return s;
  }
}
