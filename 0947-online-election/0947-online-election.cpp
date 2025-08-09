class TopVotedCandidate
{
private:
    map<int,int> win_at_time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
    {
        int n = persons.size();
        int mxVotes = 0;
        int winner = 0;

        vector<int> voteCount(n,0);

        for(int i = 0; i < n; i++)
        {
            voteCount[persons[i]]++;
            if(voteCount[persons[i]] >= mxVotes)
            {
                winner = persons[i];
                mxVotes = voteCount[persons[i]];
            }
            win_at_time[times[i]] = winner;
        }
    }
    
    int q(int t)
    {
        auto itr = win_at_time.upper_bound(t);
        itr--;
        return itr->second;
    }
};