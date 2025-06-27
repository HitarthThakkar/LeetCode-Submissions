class Solution
{
public:
    string recur(int length, string &temp, int li, vector<char> &v, vector<vector<int>> &indices, string &s, int k)
    {
        // cout << length << " && " << temp << " && " << li << endl;
        if(temp.length() == length) {
            // "temp" is a candidate of "maybe" being k times in s.
            int i = 0;
            int times = 0;
            for(auto c : s)
            {
                if(c == temp[i]) i++;
                if(i == temp.size()) { times++, i = 0; if(times == k) return temp; }
            }
            return "";
        }
        string result = "";        
        for(auto c : v)
        {
            int i = (int)c - 'a';
            int find = lower_bound(indices[i].begin(), indices[i].end(), li) - indices[i].begin();
            // cout << i << " " << find << endl;
            if(find != indices[i].size())
            {
                temp.push_back(c);
                int ii = 0;
                int times = 0;
                // cout << temp << endl;
                for(auto ch : s)
                {
                    if(ch == temp[ii]) ii++;
                    if(ii == temp.size()) {
                        times++, ii = 0;
                        if(times == k) {
                            result = recur(length, temp, indices[i][find] + 1, v, indices, s, k);
                            if(result != "") return result;
                        }
                    }
                }
                temp.pop_back();
                // else temp.pop_back();
            }
        }
        return result;
    }

    string longestSubsequenceRepeatedK(string s, int k)
    {
        vector<int> freq(26, 0);
        vector<char> v;
        for(auto c : s) freq[c - 'a']++;
        for(int i = 25; i >= 0; i--) if(freq[i] >= k) {
            v.push_back((char)('a' + i));
        }
        vector<vector<int>> indices(26);
        for(int i = 0; i < s.length(); i++) {
            indices[s[i] - 'a'].push_back(i);
        }

        // for(auto e : v)cout<<e<<" ";cout<<endl;

        // for(int i = 0; i < indices.size(); i++)
        // {
        //     cout << i << " -> ";
        //     for(int j = 0; j < indices[i].size(); j++)
        //     {
        //         cout << indices[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // return "";

        int lo = 1;
        int hi = (s.length() / k);
        string result = "";

        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            string temp = "";
            string str = recur(mid, temp, -1, v, indices, s, k);
            if(str == "") {
                hi = mid - 1;
            }
            else {
                result = str;
                lo = mid + 1;
            }
        }

        return result;
    }
};