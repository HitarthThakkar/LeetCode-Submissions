class Solution
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        double ans = 0;
        priority_queue<pair<double, pair<int, int>>> pq;
        for(auto ele : classes)
        {
            double o = ele[0] + 1, t = ele[1] + 1; double one = (o / t);
            o = ele[0], t = ele[1]; double two = (o / t);
            pq.push({(one - two), {ele[0], ele[1]}});
        }
        while(extraStudents--)
        {
            double one = pq.top().second.first + 1;
            double two = pq.top().second.second + 1;
            pq.pop();
            double three = (one / two);
            double four = ((one + 1) / (two + 1));
            pq.push({(four - three), {one, two}});
        }
        while(!pq.empty())
        {
            double one = pq.top().second.first;
            double two = pq.top().second.second;
            ans += (one / two);
            pq.pop();
        }
        return (ans / classes.size());
    }
};