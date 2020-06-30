class Solution {
  public int threeSumClosest(int[] nums, int target) {
    Arrays.sort(nums);
    int res = nums[0] + nums[1] + nums[2];

    for (int l = 0; l < nums.length; ++l) {
      int m = l + 1;
      int r = nums.length - 1;

      while (m < r) {
        int sum = nums[l] + nums[m] + nums[r];
        if (sum > target) {
          --r;
        } else {
          ++m;
        }

        if (Math.abs(target - sum) < Math.abs(target - res)) {
          res = sum;
        }
      }
    }

    return res;
  }
}
