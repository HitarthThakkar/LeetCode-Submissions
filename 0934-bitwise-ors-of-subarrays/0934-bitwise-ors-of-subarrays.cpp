class Solution
{
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        int n = arr.size();
        unordered_set<int> uniq, prev, cur;

        for(int i = 0; i < n; i++) {
            if(uniq.find(arr[i]) == uniq.end()) uniq.insert(arr[i]);

            cur.clear();
            for(auto e : prev) {
                cur.insert(arr[i] | e);
                uniq.insert(arr[i] | e);
            }

            prev = cur;
            prev.insert(arr[i]);
        }

        return uniq.size();
    }
};