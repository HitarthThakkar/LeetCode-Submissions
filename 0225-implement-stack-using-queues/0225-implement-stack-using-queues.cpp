class MyStack
{
public:
    queue<int> q;
    MyStack() {}    
    void push(int x)
    {
        vector<int> v;
        while(!q.empty()) v.push_back(q.front()), q.pop();
        q.push(x);
        for(auto ele : v) q.push(ele);
    }
    int pop() { int f = q.front(); q.pop(); return f; }
    int top() { return q.front(); }
    bool empty() { return (q.size() == 0); }
};