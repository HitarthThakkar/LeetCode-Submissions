class MyQueue
{
public:
    stack<int> writeStack;
    stack<int> readStack;

    MyQueue() {}
    
    void push(int x)
    {
        writeStack.push(x);
    }
    
    int pop()
    {
        if(!readStack.empty())
        {
            int ele = readStack.top();
            readStack.pop();
            return ele;
        }
        else
        {
            while(!writeStack.empty())
            {
                readStack.push(writeStack.top());
                writeStack.pop();
            }
            int ele = readStack.top();
            readStack.pop();
            return ele;
        }
    }
    
    int peek()
    {
        if(!readStack.empty())
        {
            return readStack.top();
        }
        else
        {
            while(!writeStack.empty())
            {
                readStack.push(writeStack.top());
                writeStack.pop();
            }
            return readStack.top();
        }
    }
    
    bool empty()
    {
        return (writeStack.empty() && readStack.empty());
    }
};