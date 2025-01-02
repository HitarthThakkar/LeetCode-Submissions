class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        int n = deck.size(); queue<int> q; vector<int> answer(n);
        for (int i = 0; i < n; i++) q.push(i);
        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++)
        {
            answer[q.front()] = deck[i]; q.pop();
            if (!q.empty()) { q.push(q.front()); q.pop(); }
        }
        return answer;
    }
};