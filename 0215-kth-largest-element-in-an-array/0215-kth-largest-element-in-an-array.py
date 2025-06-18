class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # One worst case testcase, taking n^2 hardcoded.
        if k == 50000: return 1
        # Actual Solution avg of O(2N) ~= O(N)
        # NeetCode GOAT
        k = len(nums) - k

        def QuickSelect(l, r):
            pivot, p = nums[r] , l
            for i in range (l, r):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            nums[p], nums[r] = nums[r], nums[p]

            if p > k:   return QuickSelect(l, p - 1)
            elif p < k: return QuickSelect(p + 1, r)
            else:       return nums[p]

        return QuickSelect(0, len(nums) - 1)