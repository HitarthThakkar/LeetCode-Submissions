func findMissingElements(nums []int) []int {

    // 1. Handle empty input boundary condition
    if len(nums) == 0 {
        return nil
    }

    // 2. Find range boundaries and track existing numbers
    min, max := math.MaxInt, math.MinInt
    seen := make(map[int]bool, len(nums))

    for _, num := range nums {
        seen[num] = true
        if num < min {
            min = num
        }
        if num > max {
            max = num
        }
    }

    // 3. Allocate slice with estimated capacity to reduce reappend overhead
    res := make([]int, 0, (max - min) - len(nums) + 1)

    // 4. Collect missing numbers sequentially
    for i := min + 1; i < max; i++ {
        if !seen[i] {
            res = append(res, i)
        }
    }

    return res
}