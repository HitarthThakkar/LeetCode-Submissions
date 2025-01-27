class Solution
{
private:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[1] != b[1]) return (a[1] < b[1]);
        return (a[0] < b[0]);
    }
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        int n = courses.size();

        sort(courses.begin(), courses.end(), cmp);

        priority_queue<int> pq;

        int elapsed_time = 0;

        for(int i = 0; i < n; i++)
        {
            if(elapsed_time + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                elapsed_time += courses[i][0];
            }
            else
            {
                if(!pq.empty() && pq.top() > courses[i][0])
                {
                    elapsed_time -= (pq.top() - courses[i][0]);
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }

        return pq.size();
    }
};