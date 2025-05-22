#define pai pair<int, int>
class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int n = arr.size();
        auto cmp = [](const pai& a, const pai& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        priority_queue<pai, vector<pai>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < n; i++)
        {
            pq.push({abs(arr[i] - x), i});
            if(pq.size() > k) pq.pop();
        }
        vector<int> result;
        while(!pq.empty()) { result.push_back(arr[pq.top().second]); pq.pop(); }
        sort(result.begin(), result.end());
        return result;
    }
};