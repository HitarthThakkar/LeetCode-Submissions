class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        curSum = 0
        pfxSums = {0 : 1}

        for n in nums:
            curSum += n
            diff = curSum - k
            res += pfxSums.get(diff, 0)
            pfxSums[curSum] = 1 + pfxSums.get(curSum, 0)

        return res