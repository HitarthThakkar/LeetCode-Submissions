class FreqStack
{
public:
    /* This que has many approaches to learn from this is first of them. */
    /*------ Approach 2 :- Priority queue -------*/

    // O(N + M) Space complexity for frequency map and pq
    unordered_map<int, int> freq;
    priority_queue<tuple<int, int, int>> pq;
    int timestamp = 0;

    FreqStack() {}

    // O(logN) for push
    void push(int val)
    {
        freq[val]++;
        pq.push({freq[val], timestamp++, val});
        // Sorts by most freq, then most timestamp and then value.
    }    

    // O(logN) for pop
    int pop()
    {
        auto [f, t, x] = pq.top();
        pq.pop();
        freq[x]--;
        return x;
    }
};