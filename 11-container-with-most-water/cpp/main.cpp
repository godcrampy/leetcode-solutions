class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, maxHeight = 0;

    while (l < r) {
      maxHeight = max(maxHeight, (r - l) * min(height[l], height[r]));

      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }

    return maxHeight;
  }
};
