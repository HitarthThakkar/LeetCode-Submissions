class MedianFinder
{
public:

    priority_queue<int> leftpq;     // MAX_HEAP
    priority_queue<int, vector<int>, greater<int>> rightpq; // MIN_HEAP

    MedianFinder() {}
    
    void addNum(int num)
    {
        if(leftpq.size() == 0)
        {
            leftpq.push(num);
        }
        else
        {
            if(leftpq.size() == rightpq.size())
            {
                int lefttop =  leftpq.top();

                if(num <= lefttop)
                {
                    leftpq.push(num);
                }
                else
                {
                    rightpq.push(num);
                    leftpq.push(rightpq.top());
                    rightpq.pop();
                }
            }
            else
            {
                int lefttop =  leftpq.top();

                if(num <= lefttop)
                {
                    leftpq.push(num);
                    rightpq.push(leftpq.top());
                    leftpq.pop();
                }
                else
                {
                    rightpq.push(num);
                }
            }
        }
    }
    
    double findMedian()
    {
        if(leftpq.size() == rightpq.size())
        {
            return (double) ((leftpq.top() + rightpq.top()) / 2.0);
        }
        else
        {
            return leftpq.top();
        }
    }
};