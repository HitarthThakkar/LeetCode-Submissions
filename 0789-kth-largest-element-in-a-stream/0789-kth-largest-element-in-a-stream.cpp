class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums)
    {
        int n=nums.size();
        for(int i=0;i<min(k,n);i++)pq.push(nums[i]);
        for(int i=k;i<n;i++)
            if(nums[i]>pq.top()){pq.pop();pq.push(nums[i]);}
        while(pq.size()<k)pq.push(-1e8);
    }

    int add(int val)
    {
        if(val>pq.top()){pq.pop();pq.push(val);}
        return pq.top();
    }
};