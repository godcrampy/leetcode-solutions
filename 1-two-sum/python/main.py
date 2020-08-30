class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = {}
        for i, n in enumerate(nums):
            if target - n in s:
                return [s[target - n], i]
            else:
                s[n] = i
        return [-1, -1]
