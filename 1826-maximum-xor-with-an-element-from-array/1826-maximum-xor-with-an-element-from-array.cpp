struct Node
{
    Node* links[2];
    bool containsKey(int bit) { return links[bit] != NULL; }
    Node* get(int bit) { return links[bit]; }
    void put(int bit) { links[bit] = new Node(); }
};

class Trie
{
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num)
    {
        Node* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if(!node->containsKey(bit)) node->put(bit);
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num)
    {
        Node* node = root;
        int result = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if(node->containsKey(!bit))
            {
                result |= (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return result;
    }

};

class Solution
{
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        int q = queries.size();

        vector<pair<int, pair<int, int>>> offlineQueries; // m_i, x_i, q_i
        for(int i = 0; i < q; i++) offlineQueries.push_back({queries[i][1], {queries[i][0], i}});

        sort(offlineQueries.begin(), offlineQueries.end());
        sort(nums.begin(), nums.end());

        Trie myTrie;
        vector<int> answer(q, -1);
        int ind = 0;

        for(auto e : offlineQueries)
        {
            int m_i = e.first;
            int x_i = e.second.first;
            int q_i = e.second.second;

            while(ind < n && nums[ind] <= m_i) myTrie.insert(nums[ind++]);

            if(ind > 0) answer[q_i] = myTrie.getMaxXOR(x_i);
        }

        return answer;
    }
};