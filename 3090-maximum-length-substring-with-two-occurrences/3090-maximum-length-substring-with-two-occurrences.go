func maximumLengthSubstring(s string) int {
    maxLength := 0
    left := 0
    counts := make(map[byte]int)

    for right := 0; right < len(s); right++ {
        counts[s[right]]++

        for counts[s[right]] > 2 {
            counts[s[left]]--
            left++
        }

        maxLength = max(maxLength, right - left + 1)
    }

    return maxLength
}