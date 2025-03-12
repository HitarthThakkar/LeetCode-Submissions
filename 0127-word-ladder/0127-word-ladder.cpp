class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1}); // {Word, Steps} => WHY NOT ZERO STEPS, because we have to return 0 in the case of the word cannot be formed.
        st.erase(beginWord);    // Why we erase the elements is the same logic as the visited array in BFS. iykyk else Watch Video

        // IF Given Number Of words == N
        // T.C. => [N x (internal loop)] @Worstcase
        while (!q.empty())
        {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (curr == endWord)
            {
                return steps;
            }

            // internal loop -> (Word_Length * 26 * logN)
            for (int i = 0; i < curr.length(); i++)
            {
                char ch = curr[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    curr[i] = c;

                    if (st.find(curr) != st.end())
                    {
                        q.push({curr, steps + 1}); // 1 Step increased than that of the last
                        // cout << curr << " " << steps + 1 << endl;
                        st.erase(curr); // iykyk
                    }
                }

                curr[i] = ch;
            }
        }

        return 0; // Not Possible
    }
};