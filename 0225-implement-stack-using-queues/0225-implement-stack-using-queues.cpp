class MyStack {
public:
    queue<int> q;
    int sz = 0;

    MyStack() {
    }
    
    void push(int x) {
        vector<int> v;
        while(!q.empty())
        {
            v.push_back(q.front());q.pop();
        }
        q.push(x);
        for(auto ele : v)q.push(ele);
        sz++;
    }
    
    int pop() {
        int f = q.front();
        q.pop();
        sz--;
        return f;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return (sz == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */