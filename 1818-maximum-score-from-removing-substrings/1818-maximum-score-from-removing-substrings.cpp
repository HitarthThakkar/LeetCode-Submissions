/*


I know it's long, sorry. It is not quite rigorous or hard to understand, just long;
but I hope it is clear enough and SURELY qualifies as a proof. :)

Note: (b, a) in the proof is not the same as (ba).
The former refers to a pair which is not necessarily adjacent
(they are just two letters in this order) and the latter refers to
letters b and a such that a comes directly after b.

Let us divide the string into substrings containing only a and b.
So e.g. abbaabbxyzaabxb becomes abbaabb, aab and b.
The answer to the problem is the sum of the answers for each of these strings.
So from now on consider we only have a string containing a's and b's.

[NEEDED LATER IN PROOF, leaving details to reader] Whatever order we remove the pairs in,
we always end up with the same string (can be also empty).
E.g. ababa becomes a and abab becomes empty string.
In fact, the resulting string consists of only the letter of type which was
more frequent in the string, or is empty. If there were K as and L bs with K > L,
then the resulting string is aa...a where the count of as is K - L.
If K = L we have an empty string in the end.
So from now on we know that the order of pair removal does not matter
in terms of the number of removed letter's (we always remove the same number of as and bs).

Consider (ba) is more valuable than (ab).
The other case would be treated in an analogous way and
if one is as valuable as the other, then we have practically proved that
the result will always be the same (in step 2.).
So, (ba) is more valuable than (ab).
Let M be the max number of pairs b, a of letters in the string
which are in this order, where each letter is used only once.
E.g. in bbababbba it is 3, but note that we do not necessarily
say that b and a are right after each other, there may be a other letters in between.
So the pairs (b,a) could be on indexes (0,2), (3,4), (5,8).

Note that the process of removing of (ab) or (ba) does not change the order of
any remaining b compared to any remaining a.
Clearly, therefore, we cannot achieve to remove more than M pairs (ba).
So the max result is when we remove (ba) M times and remove (ab)
the remaining number of times (say N times).
Note that we always remove M + N touples (ab) or (ba) (according to 2.)
independent of the order we remove them in.
And since (ba) is more valuable than (ab) then indeed the best
we can get is to remove (ba) M times.

We claim that we can manage to remove (ba) M times when we start with
removing only (ba) and all (ab) can come afterward.
For contradiction suppose that we start removing (ba) but manage to remove only P < M
such touples and no other.
According to 3. there must still exist some pair (b, a) such that b is before a
in the remaining sequence.
Since we removed all the touples which are possible,
then the remaining pair must have some characters in between.
Consider a pair (b, a) such that b mas minimal distance to a,
it looks something like this: b....a where the dots are characters a or b.
But if there was either a or b in the place of the dots, we can find a pair (b, a)
with the property that b is closer to a than the pair we considered has the distance
of b and a minimal.
This is a contraditction.
Hence, we indeed manage to remove M (ba) touples this way.
*/

/*
    ALSO ONE MORE COMMENT, YOU CAN DO MORE EFFICIENT IMPLEMENTATION THAN THIS ONE FOR SURE.
    BUT ITS LEFT FOR FUTURE TRASH VERSION OF THIS PRESENT TRASH.
*/

class Solution
{
private:
    string removeSubstring(string &input, string &target)
    {
        stack<char> st;
        for (char ch : input)
            if (ch == target[1] && !st.empty() && st.top() == target[0]) st.pop();
            else st.push(ch);
        string output;
        while (!st.empty())
        {
            output += st.top();
            st.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
public:
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        string first, second;
        if(x > y) first = "ab", second = "ba";
        else first = "ba", second = "ab";
        string s_v1 = removeSubstring(s, first);
        int ctPair = (s.length() - s_v1.length()) / 2;
        ans += ctPair * max(x, y);
        string s_v2 = removeSubstring(s_v1, second);
        ctPair = (s_v1.length() - s_v2.length()) / 2;
        ans += ctPair * min(x, y);
        return ans;
    }
};



/*

ANOTHER COMMENT:
EDITORIAL GOOD AND UNDERSTANDABLE CODE IF U CAN UNDERSTAND THE CORE LOGIC THEN CODE IS EZ

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Ensure "ab" always has more points than "ba"
        if (x < y) {
            // Swap points
            int temp = x;
            x = y;
            y = temp;
            // Reverse the string to maintain logic
            reverse(s.begin(), s.end());
        }

        int aCount = 0, bCount = 0, totalPoints = 0;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (currentChar == 'a') {
                ++aCount;
            } else if (currentChar == 'b') {
                if (aCount > 0) {
                    // Can form "ab", remove it and add points
                    --aCount;
                    totalPoints += x;
                } else {
                    // Can't form "ab", keep 'b' for potential future "ba"
                    ++bCount;
                }
            } else {
                // Non 'a' or 'b' character encountered
                // Calculate points for any remaining "ba" pairs
                totalPoints += min(bCount, aCount) * y;
                // Reset counters for next segment
                aCount = bCount = 0;
            }
        }
        // Calculate points for any remaining "ba" pairs at the end
        totalPoints += min(bCount, aCount) * y;

        return totalPoints;
    }
};



*/