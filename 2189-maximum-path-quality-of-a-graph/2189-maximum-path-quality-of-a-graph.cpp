#define my_pair pair<vector<int>, set<int>>

class Solution
{
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime)
    {
        int n = values.size();
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n, 1e9);
        priority_queue<int, vector<int>, greater<int>> pq_temp;

        dist[0] = 0;
        pq_temp.push(0);

        while(!pq_temp.empty())
        {
            int node = pq_temp.top();
            pq_temp.pop();

            for(auto e : adj[node])
            {
                int neiNode = e.first;
                int dis = e.second;

                if(dist[neiNode] > dist[node] + dis)
                {
                    dist[neiNode] = dist[node] + dis;
                    pq_temp.push(neiNode);
                }
            }
        }

        // for(auto e : dist) cout << e << " "; cout << endl;

        auto cmp = [](const my_pair& a, const my_pair& b) {
            return a.first[0] > b.first[0]; // MIN-HEAP BASED ON 1ST ELEMENT OF VECTOR.
        };

        // timeTillNow, node, scoreTillNow, nodes_visited_till_now.
        priority_queue<my_pair, vector<my_pair>, decltype(cmp)> pq;
        vector<int> v = {0, 0, values[0]};
        set<int> s = {0};
        pq.push({v, s});

        int max_score = values[0];

        while(!pq.empty())
        {
            my_pair curNode = pq.top();
            pq.pop();

            int timeTillNow = curNode.first[0];
            int node = curNode.first[1];
            int scoreTillNow = curNode.first[2];
            s = curNode.second;

            if(timeTillNow > maxTime) return max_score;
            if(node == 0) max_score = max(max_score, scoreTillNow);

            // cout << timeTillNow << " " << node << " " << scoreTillNow << " & ";
            // for(auto e : s) cout << e << ","; cout << endl;

            for(auto e : adj[node])
            {
                int nei = e.first;
                int weight = e.second;

                if(timeTillNow + weight + dist[nei] <= maxTime)
                {
                    bool wasThere = (s.find(nei) != s.end());
                    int scoretb = scoreTillNow;
                    if(!wasThere) scoretb += values[nei];
                    vector<int> temp = {timeTillNow + weight, nei, scoretb};
                    if(!wasThere) s.insert(nei);
                    pq.push({temp, s});
                    if(!wasThere) s.erase(nei);
                }
            }
        }

        return max_score;
    }
};