class Solution
{
public:
    int minMaxDifference(int num)
    {
        string maxi = to_string(num);
        string mini = maxi;
        char tbc = '$';
        for(auto &c : maxi)
        {
            if(c == '9') continue;
            else if(c != '9' && tbc == '$') { tbc = c; c = '9'; }
            else if(c == tbc) c = '9';
        }
        tbc = mini[0];
        for(auto &c : mini)
        {
            if(c == tbc) c = '0';
        }
        return (stoi(maxi) - stoi(mini));
    }
};