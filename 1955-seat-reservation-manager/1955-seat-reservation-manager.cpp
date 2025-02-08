class SeatManager
{
public:

    // Editorial Approach OP

    int marker = 1;
    priority_queue<int, vector<int>, greater<int>> avl;

    SeatManager(int n) {}
    
    int reserve()
    {
        if(avl.empty())
        {
            // O(1)
            int minSeat = marker;
            marker++;
            return minSeat;
        }
        else
        {
            int minSeat = avl.top(); // O(1)
            avl.pop(); // O(log(Size))
            return minSeat;
        }
    }
    
    void unreserve(int seatNumber)
    {
        avl.push(seatNumber); // O(logN)
    }
};