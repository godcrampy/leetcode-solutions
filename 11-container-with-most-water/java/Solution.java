class Solution {
  public int maxArea(int[] height) {
    int l = 0, r = height.length - 1, maxVolume = 0;

    while (l < r) {
      maxVolume = Math.max(maxVolume, (r - l) * Math.min(height[l], height[r]));
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }

    return maxVolume;
  }
}
