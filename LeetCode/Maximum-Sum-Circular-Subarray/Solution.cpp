def maxSubArray(self, nums: List[int]) -> int:
    arr_sum = nums[0]
    best = arr_sum
    for i in range(1, len(nums)):
        if arr_sum < 0:
            arr_sum = 0
        arr_sum += nums[i]
        best = max(best, arr_sum)

    return best