/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    void recur(Node* node, map<Node*, Node*> &m)
    {
        Node* newNode = new Node(node->val);
        m[node] = newNode;
        for(auto nei : node->neighbors)
        {
            if(m.find(nei) == m.end()) recur(nei, m);
            (newNode->neighbors).push_back(m[nei]);
        }
    }

    Node* cloneGraph(Node* node)
    {
        map<Node*, Node*> m;
        if(node) recur(node, m);
        else return NULL;
        return m[node];
    }
};