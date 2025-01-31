class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # We know there canbe one jude atmax
        # i.e. atmax one will have 
        # incoming edges = n - 1 and also outgoing edges = 0
        # if noone has then return -1

        delta = defaultdict(int) # delta = (incoming - outgoing)

        for(src, dst) in trust:
            delta[dst] += 1 # incoming edge
            delta[src] -= 1 # outgoing edge

        for i in range(1, n + 1):
            if delta[i] == n - 1:
                return i

        return -1