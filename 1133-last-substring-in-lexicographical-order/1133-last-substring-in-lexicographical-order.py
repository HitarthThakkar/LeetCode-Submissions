class Solution:
    def lastSubstring(self, s: str) -> str:
        n = len(s)
        # Max valued char in s
        mmax = max(s)
        # all 'candidates', AKA indices of chars eql to `mmax`
        candidates = [i for i, c in enumerate(s) if c == mmax]
        # overpowered variable
        offset = 1
        # eliminate until only one left, squid game
        while len(candidates) > 1:
            # best one in `i+offset`th position
            curmmax = max(s[i + offset] for i in candidates if i + offset < n)
            # again squid game
            survivors = []
            # eliminate all `BAD`
            for i, start in enumerate(candidates):
                # Previous is better fr and `i` will not get placed in `survivors`
                if i > 0 and candidates[i - 1] + offset == start:
                    continue
                # Regular eliminatory checks
                if start + offset < n and s[start + offset] == curmmax:
                    survivors.append(start)

            # brand new candidates AKA last season survivors
            candidates = survivors
            # level++ AKA offset++
            offset += 1

        return s[candidates[0]:]