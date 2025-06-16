class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        maxx, res = 0, 0
        for i in range(len(nums) - 1, -1, -1):
            res = max(res, maxx - nums[i])
            maxx = max(maxx, nums[i])
        if res == 0:
            res = -1
        return res