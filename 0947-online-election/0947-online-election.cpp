/*
more strategic improvement here kinda GOLDEN one.
*/

class TopVotedCandidate {
vector<int> leading;
vector<int> times;

public:

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = times.size();
        this->times = times;
        unordered_map<int, int> mpp;
        int leader = -1, maxVotes = 0;
        for (int i = 0; i < n; i++) {
            int p = persons[i];
            if (++mpp[p] >= maxVotes) {
                leader = p;
                maxVotes = mpp[p];
            }
            leading.push_back(leader);
        }
    }
    
    int q(int t) {
        int index = upper_bound(times.begin(), times.end(), t) - times.begin();
        return leading[index-1];
    }
};