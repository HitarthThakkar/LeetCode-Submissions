struct Node
{
    int key, value, frequency;
    Node* next;
    Node* prev;

    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        frequency = 1;
    }
};

struct List
{
    int size;
    Node* head;
    Node* tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->next = head;
        size = 0;
    }

    void addFront(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delNode)
    {
        Node* left = delNode->prev;
        Node* right = delNode->next;
        left->next = right;
        right->prev = left;
        size--;
    }
};

class LFUCache
{
public:
    unordered_map<int, Node*> keyNodeMap; 
    unordered_map<int, List*> freqListMap;
    int cap;
    int minFreq;
    int curSz;

    LFUCache(int capacity)
    {
        cap = capacity;
        minFreq = 0;
        curSz = 0;
    }

    void updateFreqListMap(Node* node)
    {
        keyNodeMap.erase(node->key);
        freqListMap[node->frequency]->removeNode(node);
        if(node->frequency == minFreq && freqListMap[node->frequency]->size == 0)
        {
            minFreq++;
        }

        node->frequency++;

        List* nextHigherFreqList = new List();

        if(freqListMap.find(node->frequency) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->frequency];
        }

        nextHigherFreqList->addFront(node);
        freqListMap[node->frequency] = nextHigherFreqList;
        keyNodeMap[node->key] = node;
    }
    
    int get(int key)
    {
        if(keyNodeMap.find(key) != keyNodeMap.end())
        {
            Node* node = keyNodeMap[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(cap == 0) return;

        if(keyNodeMap.find(key) != keyNodeMap.end())
        {
            Node* node = keyNodeMap[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if(curSz == cap)
            {
                List* list = freqListMap[minFreq];
                keyNodeMap.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                // Here we removed the node from the list of minFreq
                // but never checked whether it became empty or not
                // and correspondingly we have to increase minFreq or not.
                // cuz we are going to insert new key which was not there
                // and thus minFreq will be 1 anyways. that's what is down there.
                curSz--;
            }

            curSz++;
            minFreq = 1;    // Will be 1 cuz new key is added which was not there.

            List* ListFreq = new List();

            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                ListFreq = freqListMap[minFreq];
            }

            Node* node = new Node(key, value);
            ListFreq->addFront(node);
            keyNodeMap[key] = node;
            freqListMap[minFreq] = ListFreq;
        }
    }
};