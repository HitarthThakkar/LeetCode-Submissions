class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();

        int gno = 0;
        vector<int> gid(26, -1), mapping(26, 27);

        for(int i = 0; i < n; i++)
        {
            int c1 = (int) s1[i] - 'a';
            int c2 = (int) s2[i] - 'a';

            if(gid[c1] == -1 && gid[c2] == -1)
            {
                gid[c1] = gno;
                gid[c2] = gno;
                mapping[c1] = min(c1, c2);
                mapping[c2] = min(c1, c2);
                gno++;
            }
            else if(gid[c1] == -1)
            {
                gid[c1] = gid[c2];
                int mini = min(mapping[c2], c1);
                for(int i = 0; i < 26; i++) if(gid[i] == gid[c2]) mapping[i] = mini;
            }
            else if(gid[c2] == -1)
            {
                gid[c2] = gid[c1];
                int mini = min(mapping[c1], c2);
                for(int i = 0; i < 26; i++) if(gid[i] == gid[c1]) mapping[i] = mini;
            }
            else
            {
                int newgid = gid[c1];
                int pgid1 = gid[c1];
                int pgid2 = gid[c2];

                for(int i = 0; i < 26; i++)
                    if(gid[i] == pgid1 || gid[i] == pgid2)
                        gid[i] = newgid;

                int mini = min(mapping[c1], mapping[c2]);

                for(int i = 0; i < 26; i++)
                    if(gid[i] == newgid)
                        mapping[i] = mini;
            }
        }

        string result = "";

        for(auto c : baseStr)
        {
            int bhelu = (int) c - 'a';
            result += (mapping[bhelu] > 25 ? c : (char) 'a' + mapping[bhelu]);
        }

        return result;
    }
};