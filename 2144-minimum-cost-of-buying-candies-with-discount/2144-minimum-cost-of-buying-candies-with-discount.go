func minimumCost(cost []int) int {
    slices.SortFunc(cost, func(a, b int) int {return cmp.Compare(b, a)} )
    sum := 0
    for index, value := range cost {
        if index % 3 != 2 { sum += value }
    }
    return sum
}