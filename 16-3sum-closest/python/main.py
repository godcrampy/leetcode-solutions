class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        result = sum(nums[:3])

        for l in range(len(nums)):
            m = l + 1
            r = len(nums) - 1

            while m < r:
                currentSum = nums[l] + nums[m] + nums[r]

                if currentSum > target:
                    r -= 1
                else:
                    m += 1

                if abs(target - currentSum) < abs(target - result):
                    result = currentSum

        return result
