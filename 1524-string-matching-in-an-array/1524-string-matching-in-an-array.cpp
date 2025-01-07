class Solution
{
public:
    vector<string> stringMatching(vector<string>& words)
    {
        int n = words.size();

        set<string> ans; vector<string> answer;

        for(int i = 0; i < n; i++)
        {
            string str = words[i];

            vector<int> lps(str.length(), 0);

            int lstindofpfx = 0;

            for(int k = 1; k < str.length(); k++)
            {
                while(lstindofpfx > 0 && str[k] != str[lstindofpfx])
                {
                    lstindofpfx = lps[lstindofpfx - 1];
                }
                if(str[k] == str[lstindofpfx])
                {
                    lps[k] = lstindofpfx + 1;
                    lstindofpfx++;
                }
            }

            // for(auto ele : lps) cout << ele << " ";
            // cout << endl;

            for(int j = 0; j < n; j++)
            {
                string s = words[j];

                if(s.length() >= str.length() && i != j)
                {
                    int p1 = 0, p2 = 0;

                    while(p1 < s.length() && p2 < str.length())
                    {
                        if(s[p1] == str[p2])
                        {
                            p1++; p2++;
                        }
                        else if(p2 > 0)
                        {
                            p2 = lps[p2 - 1];
                        }
                        else
                        {
                            p1++;
                        }
                    }

                    if(p2 >= str.length())
                    {
                        ans.insert(str);
                    }

                }
            }


        }

        for(auto ele : ans) answer.push_back(ele);

        return answer;
    }
};