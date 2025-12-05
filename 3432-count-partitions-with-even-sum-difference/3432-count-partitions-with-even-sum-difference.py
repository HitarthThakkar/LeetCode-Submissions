class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n = len(nums)
        pfxSum, total, count = 0, sum(nums), 0
        for i in range(n - 1):
            pfxSum += nums[i]
            left, right = pfxSum, total - pfxSum
            if ((left - right) % 2) == 0:
                print(left, right)
                count += 1
        return count