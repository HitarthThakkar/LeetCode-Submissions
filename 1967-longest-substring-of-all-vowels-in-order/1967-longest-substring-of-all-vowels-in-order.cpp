class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        map<char, set<char>> rule;
        rule.insert({'#',{'a'}});
        rule.insert({'a',{'a','e'}});
        rule.insert({'e',{'e','i'}});
        rule.insert({'i',{'i','o'}});
        rule.insert({'o',{'o','u'}});
        rule.insert({'u',{'u'}});

        int n = word.length();
        int left = 0;
        int right = 0;
        char last = '#';
        int ans = 0;

        while(right < n)
        {
            // cout << left << " " << right << " " << last << " " << ans << endl;

            char ch = word[right];
            bool isGood = false;

            for(auto ele : rule[last])
            {
                if(ele == ch)
                {
                    isGood = true;
                    break;
                }
            }

            if(isGood)
            {
                last = ch;
                if(ch == 'u') ans = max(ans, right - left + 1);
            }
            else
            {
                if(ch == 'a')
                {
                    last = 'a';
                    left = right;
                }
                else
                {
                    last = '#';
                    left = right + 1;
                }
            }

            right++;
        }

        return ans;
    }
};