class FreqStack
{
public:
    /* This que has many approaches to learn from this is THIRD of them. */
    /*------ Approach 3 :- MOST OPTIMAL [OP] -------*/

    // O(N + M) Space complexity for frequency map and stack map
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    // Group stores => {freq, all elements having that freq in LIFO manner}
    int maxFreq = 0;

    FreqStack() {}

    // O(1) for push
    void push(int val)
    {
        int f = ++freq[val];
        maxFreq = max(maxFreq, f);
        group[f].push(val);
    }    

    // O(1) for pop
    int pop()
    {
        int x = group[maxFreq].top();
        group[maxFreq].pop();
        freq[x]--;
        if (group[maxFreq].empty())
            maxFreq--;
        return x;
    }
};