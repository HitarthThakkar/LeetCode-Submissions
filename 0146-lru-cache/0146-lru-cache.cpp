class LRUCache
{
public:

    // 2025 Hiring Prep Sprint Week_2 Q4

    class Node
    {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(Node* newNode)
    {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* tbDel)
    {
        Node* left = tbDel->prev;
        Node* right = tbDel->next;
        left->next = right;
        right->prev = left;
    }

    int get(int _key)
    {
        if(mp.find(_key) != mp.end())
        {
            Node* resNode = mp[_key];
            int res = resNode->val;
            mp.erase(_key);
            deleteNode(resNode);
            insertNode(resNode);
            mp[_key] = head->next;
            return res;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int _key, int value)
    {
        // 2 cases of Deletion
        // EITHER 1) {key,val} exists and we have to change val
        // OR     2) capacity reached
        if(mp.find(_key) != mp.end())
        {
            Node* existingNode = mp[_key];
            mp.erase(_key);
            deleteNode(existingNode);
        }
        else if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        insertNode(new Node(_key, value));
        mp[_key] = head->next;
    }
};