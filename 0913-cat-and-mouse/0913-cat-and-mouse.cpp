// THE OVERALL BEST DP/GRAPH QUESTION SEEN UNTIL NOW (16TH APR, 2026)
// WAS UNABLE TO SOLVE, WATCHED AN AMAZING EXPLANATION
// WORLD BEST EXPLANATION : CPP IN PAJAMAS YOUTUBE CHANNEL VIDEO, AMAZING EXPLANATION + VOICE.
// AFTER WATCHING THE VIDEO, SEE THE OFFICIAL LEETCODE EDITORIAL
// AFTER THAT EDITORIAL READING, SEE THE CODE BELOW AND IT WILL MAKE SENSE.

class Solution
{
public:
    int catMouseGame(vector<vector<int>>& graph)
    {
        int n = graph.size();

        // Constants for better readability
        const int HOLE = 0;
        const int MOUSE_START = 1;
        const int CAT_START = 2;

        const int MOUSE_TURN = 0;
        const int CAT_TURN = 1;

        const int DRAW = 0;
        const int MOUSE_WIN = 1;
        const int CAT_WIN = 2;

        // As you know, game "state" can be UNIQUELY represented by (cur_mouse_pos, cur_cat_pos, whose_turn_next)
        // We make 2 arrays.
        // First is "dp" which stores the result for that "state", e.g. DRAW or MOUSE_WIN or CAT_WIN
        // Second is "degree" which stores count of possible moves left to play without losing for that "state" (iykyk)

        int dp[n][n][2];
        int degree[n][n][2];

        // Initializing all states as DRAW in dp, will update this using already known info.
        memset(dp, DRAW, sizeof(dp));
        // Initializing degree of all nodes as zero in start, will update this.
        memset(degree, 0, sizeof(degree));

        // Initializing degree for each "state" first.
        // Note that looping starts from 1 and not 0 because,
        // when mouse_pos is zero, mouse has already won, no need to calculate degree for it and
        // cat_pos can not be zero, so we start both mouse_pos and cat_pos from 1.

        for(int mousePos = 1; mousePos < n; mousePos++)
        {
            for(int catPos = 1; catPos < n; catPos++)
            {
                // Mouse can move from "mousePos" to any adjacent node of "mousePos"
                degree[mousePos][catPos][MOUSE_TURN] = graph[mousePos].size();

                // Here, we are making a mistake, because cat if "catPos" is adjacent to HOLE, then we should not count it.
                degree[mousePos][catPos][CAT_TURN] = graph[catPos].size();
            }

            // Here, we correct the mistake by finding all adjacent node to the HOLE for each "mousePos".
            for(int adjacentToHole : graph[HOLE])
            {
                degree[mousePos][adjacentToHole][CAT_TURN]--;
            }
        }

        // INFO : degree matrix initialization completed.

        // This function is useful in future.
        // Gets all previous possible states that could've led to the given state in input
        auto getPossiblePreviousStates = [&](int mousePos, int catPos, int turn)
        {
            int prevTurn = turn ^ 1;    // PrevTurn = MOUSE then curTurn = CAT and vice versa.

            vector<tuple<int, int, int>> possiblePreviousStates;

            if(prevTurn == CAT_TURN)
            {
                // prevTurn was cat's; so mouse position would be unchanged (prevMousePos == mousePos)
                // and cat could've came from any of the nodes in graph[catPos] EXCEPT hole.

                for(auto prevCatPos : graph[catPos])
                {
                    if(prevCatPos != HOLE)
                    {
                        possiblePreviousStates.emplace_back(mousePos, prevCatPos, prevTurn);
                    }
                }
            }
            else
            {
                // prevTurn was mouse's; so cat position would be unchanged (prevCatPos = catPos)
                // and mouse could've came from ANY of the nodes in graph[mousePos].

                for(auto prevMousePos : graph[mousePos])
                {
                    possiblePreviousStates.emplace_back(prevMousePos, catPos, prevTurn);
                }
            }

            return possiblePreviousStates;
        };

        // INFO : helper function completed.


        // Stores all the states whose result is already known and marked in the dp.
        queue<tuple<int, int, int>> resolvedStates;


        // Initializing DP and resolvedStates with common sense.
        // COMMON SENSE

        // 1. MOUSE_WIN
        // If (mousePos is zero, catPos is ANY, and it's CAT's turn) then result of that state is MOUSE_WIN.
        // (mousePos is zero, catPos is ANY, and it's MOUSE's turn) that state is not possible. (Think / cpp in pajamas)
        for(int catPos = 1; catPos < n; catPos++)
        {
            dp[0][catPos][CAT_TURN] = MOUSE_WIN;
            resolvedStates.emplace(0, catPos, CAT_TURN);
            // => Technically we can write this and it will not affect the correctness of the answer,
            // but it's not possible anyway based on game rules and will also increase runtime. (cpp in pajamas)
            // dp[0][catPos][MOUSE_TURN] = MOUSE_WIN;
            // resolvedStates.push(0, catPos, MOUSE_TURN);
        }

        // 2. CAT_WIN
        // If (mousePos == catPos, it canbe any node EXCEPT hole, and canbe anyone's turn) then result of that state is CAT_WIN.
        for(int pos = 1; pos < n; pos++)
        {
            dp[pos][pos][MOUSE_TURN] = CAT_WIN;
            dp[pos][pos][CAT_TURN] = CAT_WIN;
            resolvedStates.emplace(pos, pos, MOUSE_TURN);
            resolvedStates.emplace(pos, pos, CAT_TURN);
        }

        // INFO : dp and queue initialization completed.

        while(!resolvedStates.empty())
        {
            // cur is known/resolved, we know result for is already and it's stored in dp[curMousePos, curCatPos, curTurn].
            // prev is the one whose result we might not know, and we are trying to deduce it based on :
            // EITHER "immediate coloring", i.e.; there is a clear win for some player;
            // OR "eventual coloring", i.e.; the player has run out of all escape options (degree == 0) and it's a loss for him.

            auto [curMousePos, curCatPos, curTurn] = resolvedStates.front();
            resolvedStates.pop();

            int curResult = dp[curMousePos][curCatPos][curTurn];

            for(auto [prevMousePos, prevCatPos, prevTurn] : getPossiblePreviousStates(curMousePos, curCatPos, curTurn))
            {
                // Skipping if result is already determined, kinda like visited.
                if(dp[prevMousePos][prevCatPos][prevTurn] != DRAW) continue;

                // Now we know result for prev state is not caculated and we will try to detemine/deduce it.

                // "immediate coloring"
                bool canWin = ((curResult == MOUSE_WIN && prevTurn == MOUSE_TURN) || (curResult == CAT_WIN && prevTurn == CAT_TURN));

                if(canWin)
                {
                    dp[prevMousePos][prevCatPos][prevTurn] = curResult;
                    resolvedStates.emplace(prevMousePos, prevCatPos, prevTurn);
                }
                else
                {
                    // immediate coloring not possible, decrease degree and check for eventual coloring
                    degree[prevMousePos][prevCatPos][prevTurn]--;

                    if(degree[prevMousePos][prevCatPos][prevTurn] == 0)
                    {
                        dp[prevMousePos][prevCatPos][prevTurn] = curResult;
                        resolvedStates.emplace(prevMousePos, prevCatPos, prevTurn);
                    }
                }
            }
        }

        return dp[MOUSE_START][CAT_START][MOUSE_TURN];
    }
};