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
    int findMaximumXOR(vector<int>& nums)
    {
        Trie myTrie;
        for(auto e : nums) myTrie.insert(e);
        int answer = 0;
        for(auto e : nums) answer = max(answer, myTrie.getMaxXOR(e));
        return answer;
    }
};