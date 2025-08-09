/*
last one was good but this might be a strategic improvement
[if u think clearly]
*/

class TopVotedCandidate {
public:
    unordered_map<int, int> mpp;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = times.size(), lead = -1;
        this->times = times;

        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            cnt[persons[i]]++;
            if(cnt[persons[i]] >= cnt[lead]){
                lead = persons[i];
            }
            mpp[times[i]] = lead;
        }

    }
    
    int q(int t) {
        return mpp[*--upper_bound(times.begin(), times.end(), t)];
    }
};