class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int s = 0;
    int f = 0;
    s = nums[s];
    f = nums[nums[f]];

    while (f != s) {
      s = nums[s];
      f = nums[nums[f]];
    }

    s = 0;
    while (f != s) {
      s = nums[s];
      f = nums[f];
    }

    return f;
  }
};
