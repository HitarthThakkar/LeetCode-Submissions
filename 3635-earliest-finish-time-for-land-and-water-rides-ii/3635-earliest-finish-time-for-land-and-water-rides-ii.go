func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {

	calc := func(start1, dur1, start2, dur2 []int) int {
		// Step 1: Find the earliest any ride in the first category can finish
		minFirstEnd := 1_000_000_000

		for i := 0; i < len(start1); i++ {
			minFirstEnd = min(minFirstEnd, start1[i]+dur1[i])
		}

		// Step 2: Find the minimum time to finish the second ride
		minTotalEnd := 1_000_000_000
		for i := 0; i < len(start2); i++ {
			// You start at either when the first ride ended, or when this ride opens
			startTime := max(minFirstEnd, start2[i])
			finishTime := startTime + dur2[i]
			minTotalEnd = min(minTotalEnd, finishTime)
		}

		return minTotalEnd
	}

	pathA := calc(landStartTime, landDuration, waterStartTime, waterDuration)
	pathB := calc(waterStartTime, waterDuration, landStartTime, landDuration)

	return min(pathA, pathB)
}