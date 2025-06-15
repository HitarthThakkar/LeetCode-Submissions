class Solution {
public:
    int maxDiff(int num) {
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
        if(tbc == '1')
        {
            int i = 0;
            while(i < mini.length() && mini[i] <= '1') i++;
            if(i >= mini.length()) return (stoi(maxi) - stoi(mini));
            else {
                tbc = mini[i];
                for(auto &c : mini)
                {
                    if(c == tbc) c = '0';
                }
                return (stoi(maxi) - stoi(mini));
            }
        }
        else
        {
            for(auto &c : mini)
            {
                if(c == tbc) c = '1';
            }
            return (stoi(maxi) - stoi(mini));
        }
    }
};