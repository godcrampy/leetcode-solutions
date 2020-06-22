class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int sum = nums[l] + nums[r];

      if (sum < target) {
        ++l;
      } else if (sum > target) {
        --r;
      } else {
        return {l, r};
      }
    }

    return {0, 0};
  }
};
