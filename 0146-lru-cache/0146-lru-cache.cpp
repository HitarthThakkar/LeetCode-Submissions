class LRUCache
{
public:

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
    map<int, Node*> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(Node* newNode)
    {
        Node* secLast = tail->prev;
        Node* last = tail;

        secLast->next = newNode;
        last->prev = newNode;
        newNode->next = last;
        newNode->prev = secLast;
    }

    void deleteNode(Node* tbDel)
    {
        Node* left = tbDel->prev;
        Node* right = tbDel->next;
        left->next = right;
        right->prev = left;
        delete(tbDel);
    }

    int get(int _key)
    {
        if(m.find(_key) != m.end())
        {
            Node* tbDel = m[_key];
            int val = tbDel->val;
            Node* newNode = new Node(_key, val);
            deleteNode(tbDel);
            insertNode(newNode);
            m[_key] = newNode;
            // cout << val << endl;
            return val;
        }
        else
        {
            // cout << -1 << endl;
            return -1;
        }
    }
    
    void put(int _key, int value)
    {
        // 2 cases of deletion.
        // 1) value already exists and we want to do a value update
        // 2) capacity reached

        if(m.find(_key) != m.end())
        {
            Node* node = m[_key];
            deleteNode(node);
        }
        else if(m.size() == cap)
        {
            m.erase(head->next->key);
            deleteNode(head->next);
        }

        Node* node = new Node(_key, value);
        insertNode(node);
        m[_key] = node;

        // cout << _key << " " << value << endl;
    }
};