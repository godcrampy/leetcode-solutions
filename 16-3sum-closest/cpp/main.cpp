class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];

    for (int l = 0; l < nums.size(); ++l) {
      int m = l + 1;
      int r = nums.size() - 1;

      while (m < r) {
        int currentSum = nums[l] + nums[m] + nums[r];

        if (currentSum > target) {
          --r;
        } else {
          ++m;
        }

        if (abs(target - currentSum) < abs(target - result)) {
          result = currentSum;
        }
      }
    }

    return result;
  }
};
