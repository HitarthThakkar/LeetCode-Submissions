class Solution
{
public:
    int countVowelSubstrings(string word)
    {
        int n = word.length();

        int left = 0;
        int right = 0;

        map<char, int> freq;
        freq.insert({'a', 0});
        freq.insert({'e', 0});
        freq.insert({'i', 0});
        freq.insert({'o', 0});
        freq.insert({'u', 0});

        int ans = 0;

        int compound_interest = 0;

        while(right < n)
        {
            // cout << ans << " " << compound_interest << endl;

            char ch = word[right];

            if(freq.find(ch) == freq.end())
            {
                freq['a'] = 0;
                freq['e'] = 0;
                freq['i'] = 0;
                freq['o'] = 0;
                freq['u'] = 0;
                left = right + 1;
                compound_interest = 0;
            }
            else
            {
                freq[ch]++;
            }

            bool no = false;

            for(auto ele : freq)
            {
                if(ele.second == 0)
                {
                    no = true;
                    break;
                }
            }

            if(!no)
            {
                while(freq[word[left]] > 1)
                {
                    freq[word[left]]--;
                    left++;
                    compound_interest++;
                }

                ans++;
                ans += compound_interest;
            }

            right++;
        }

        return ans;
    }
};