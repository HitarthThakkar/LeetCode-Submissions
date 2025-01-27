class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(const auto& edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<set<int>> prereq(n);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int child : graph[node])
            {
                prereq[child].insert(node);

                for(auto ele : prereq[node])
                {
                    prereq[child].insert(ele);
                }

                if(--indegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        vector<bool> answer;

        for(const auto& query : queries)
        {
            answer.push_back(prereq[query[1]].count(query[0]));
        }

        return answer;
    }
};