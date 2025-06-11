/*

First USE SOME MIND, i think that will help to get INITIAL IDEA.

The core idea is to reframe the problem from finding a substring to -
finding two points in the string (a start and an end) that satisfy certain conditions.
By iterating through all possible characters for a and b,
the problem simplifies to: for a fixed a and b, find the maximum difference.

The solution uses a combination of prefix sums, bitmasking for states,
and a sliding window/two-pointer approach to solve the problem efficiently
for each pair of characters (a, b).

#############################################################################################
1. Brute-Force Character Selection
The problem is to find the max difference for some pair of characters a and b.
Since the set of possible characters is very small ('0' to '4'),
we can simply test every possible combination.
We use a nested loop to iterate through all 20 pairs where a is not equal to b.
The final answer will be the maximum value found across all these pairs.

#############################################################################################
2. Using Prefix Sums to Find Substring Frequencies
The frequency of a character in a substring s[i...j] can be calculated using prefix sums.
Let count(char, j) be the number of times char appears in the prefix s[0...j].
freq[a] in s[i...j] = count(a, j) - count(a, i-1)
freq[b] in s[i...j] = count(b, j) - count(b, i-1)
The value we want to maximize is freq[a] - freq[b].
i.e.;
(count(a, j) - count(a, i-1)) - (count(b, j) - count(b, i-1))

Rearranging this gives us a crucial insight:
(count(a, j) - count(b, j)) - (count(a, i-1) - count(b, i-1))

This means for a given substring ending at j, to maximize the total difference,
we need to find a starting point i-1 that minimizes the term count(a, i-1) - count(b, i-1)
while still satisfying the problem's parity conditions.

#############################################################################################
3. Using Bitmasks to Handle Parity (Odd/Even) Conditions
The problem has strict rules about the parity of frequencies :
freq[a] must be odd, and freq[b] must be even.

The parity of a difference depends on the parity of the numbers being subtracted:

odd - even = odd
even - odd = odd
odd - odd = even
even - even = even

So, for freq[a] to be odd, the parities of count(a, j) and count(a, i-1) must be different.
For freq[b] to be even, the parities of count(b, j) and count(b, i-1) must be the same.

We can represent the parity of the two prefix counts (count(a), count(b)) as a 2-bit state:

Bit 1: count(a) % 2 (1 for odd, 0 for even)
Bit 0: count(b) % 2 (1 for odd, 0 for even)
This gives us 4 possible states for any prefix:

00 (Decimal 0): count(a) is even, count(b) is even.
01 (Decimal 1): count(a) is even, count(b) is odd.
10 (Decimal 2): count(a) is odd, count(b) is even.
11 (Decimal 3): count(a) is odd, count(b) is odd.
Our target substring must have the state 10 (freq[a] odd, freq[b] even).

The state of a substring is the XOR of the states of its endpoint prefixes.
If state_j is the state for prefix j and state_{i-1} is for prefix i-1:

target_state = state_j ⊕ state_{i-1}
10 = state_j ⊕ state_{i-1}
Therefore, state_{i-1} = state_j ⊕ 10.
This tells us: for a prefix ending at j with state state_j,
we must find a previous prefix ending at i-1 that had the state state_j ⊕ 10.

#############################################################################################
4. The overpowered Logic connecting the points 1, 2 & 3
This is where all the pieces come together.
We iterate through the string with a right pointer, representing the end of our potential substring.

TERMINOLOGY
right: The main iterator, moving from 0 to n-1. It defines the prefix s[0...right].
left: A second pointer that trails behind. It defines the prefix s[0...left] that we consider as a potential starting point (specifically, left+1 is the start of the substring).
best[4]: An array to store the minimum value of prev_a - prev_b seen so far for each of the 4 possible parity states. best[status] holds this minimum value for all prefixes s[0...left] that have the state status.

The process for each right:

4.1. Advance right: Move right one step, and update the prefix counts cnt_a and cnt_b for the prefix 
                    s[0...right].
4.2. Update best array: Before calculating an answer, we potentially advance the left pointer.
                        The while loop updates the best array. It processes prefixes ending at left 
                        only when they are valid candidates to start a substring (i.e., right - left >= k).
                        For each such left, we calculate its state (left_status) and update
                        best[left_status] with the minimum prev_a - prev_b seen.
4.3. Calculate Answer: Get the state for the current prefix s[0...right], let's call it right_status.
                        Find the required state for the starting prefix:
                        required_status = right_status ⊕ 0b10.
                        Look up best[required_status]. This gives us the minimum prev_a - prev_b
                        for a valid starting prefix that satisfies the parity rules.
The potential answer for this right is (cnt_a - cnt_b) - best[required_status].
We update our global maximum ans with this value.

*/

class Solution
{
    public int maxDifference(String s, int k)
    {
        int n = s.length();

        // Initialize answer to a very small number.
        int ans = Integer.MIN_VALUE;

        // Step 1: Iterate through all possible pairs of distinct characters (a, b).
        for (char a = '0'; a <= '4'; ++a)
        {
            for (char b = '0'; b <= '4'; ++b)
            {
                if (a == b) continue;

                // --- Start of logic for a single (a, b) pair ---

                // best[status] stores the minimum (prev_a - prev_b) for a prefix
                // with the parity state 'status'. Initialize with a large value.
                int[] best = new int[4];
                Arrays.fill(best, Integer.MAX_VALUE);

                // cnt_a, cnt_b: Prefix counts for the 'right' pointer (s[0...right]).
                int cnt_a = 0, cnt_b = 0;
                // prev_a, prev_b: Prefix counts for the 'left' pointer (s[0...left]).
                int prev_a = 0, prev_b = 0;
                // 'left' tracks the end of the prefix we are recording in the 'best' array.
                int left = -1;

                // The main loop iterating through the string with the 'right' pointer.
                for (int right = 0; right < n; ++right)
                {
                    // Update prefix counts for the current 'right' position.
                    cnt_a += (s.charAt(right) == a) ? 1 : 0;
                    cnt_b += (s.charAt(right) == b) ? 1 : 0;

                    // This loop updates the 'best' array. It advances the 'left' pointer
                    // and records the state of the prefix ending at 'left'.
                    // The conditions ensure that any substring starting at 'left + 1'
                    // will have a length of at least 'k'.
                    // Note: `cnt_b - prev_b >= 2` is a specific condition in this implementation
                    // ensuring `freq[b]` is a positive even number. The base problem allows freq[b]=0.
                    while (right - left >= k && cnt_b - prev_b >= 2)
                    {
                        // Get the parity state for the prefix ending at 'left'.
                        int left_status = getStatus(prev_a, prev_b);

                        // Update the 'best' array with the minimum value of (prev_a - prev_b)
                        // for this specific state.
                        best[left_status] = Math.min(
                                best[left_status],
                                prev_a - prev_b
                        );

                        // Advance the left pointer and its corresponding prefix counts.
                        ++left;
                        prev_a += (s.charAt(left) == a) ? 1 : 0;
                        prev_b += (s.charAt(left) == b) ? 1 : 0;
                    }

                    // Now, calculate the potential answer for the current 'right' pointer.
                    // 1. Get the parity state for the prefix ending at 'right'.
                    int right_status = getStatus(cnt_a, cnt_b);

                    // 2. Determine the required state for the start-prefix.
                    // We need `left_status = right_status XOR 10` (binary).
                    int required_status = right_status ^ 0b10;

                    // 3. If we have seen a valid starting prefix with the required state...
                    if (best[required_status] != Integer.MAX_VALUE)
                    {
                        // Calculate the difference: (cnt_a-cnt_b) - min(prev_a-prev_b).
                        // This maximizes the expression.
                        ans = Math.max(
                                ans,
                                cnt_a - cnt_b - best[required_status]
                        );
                    }
                }
            }
        }
        return ans;
    }

    /**
     * Helper function to calculate the 2-bit parity state.
     * Bit 1: parity of cnt_a. Bit 0: parity of cnt_b.
     */
    private int getStatus(int cnt_a, int cnt_b)
    {
        // (cnt_a & 1) is 1 if cnt_a is odd, 0 if even.
        // << 1 shifts it to the second bit position.
        // | (cnt_b & 1) puts the parity of cnt_b in the first bit position.
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    }
}