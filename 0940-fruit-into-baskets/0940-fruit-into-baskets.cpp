class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mexlen = 0, left = 0, right = 0;
        unordered_map<int, int> m;
        while (right < fruits.size()) {
            m[fruits[right]]++;
                            while (m.size() > 2) {
                    m[fruits[left]]--;
                    if (m[fruits[left]] == 0)
                        m.erase(fruits[left]);
                    left++;
                }
                mexlen = max(mexlen, right - left + 1);
            right++;
        }
        return mexlen;
    }
};