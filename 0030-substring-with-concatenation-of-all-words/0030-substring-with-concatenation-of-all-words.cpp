class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        int word_count = words.size();
        int word_length = words[0].length();
        int total_length = word_count * word_length;
        int string_length = s.length();

        // new thing, C++17; gets rid of substr time complexity.
        unordered_map<string_view, int> mp;

        auto it = words.begin();
        while(it != words.end())
        {
            mp[*it]++;
            it++;
        }

        vector<int> result;

        for(int start = 0; start < word_length; start++)
        {
            int current_matches = 0;
            int left = start, right = start;
            unordered_map<string_view, int> mpp = mp;

            while((left <= string_length - total_length) && (right < string_length))
            {
                string_view ss = string_view(s).substr(right, word_length);

                if(mpp.find(ss) != mpp.end())
                {
                    mpp[ss]--;
                    if(mpp[ss] >= 0) current_matches++;
                    if(current_matches == word_count) result.push_back(left);
                    right += word_length;

                    if(right - left >= total_length)
                    {
                        string_view sss = string_view(s).substr(left, word_length);
                        left += word_length;
                        mpp[sss]++;
                        if(mpp[sss] > 0) current_matches--;
                        if(current_matches == word_count) result.push_back(left);
                    }
                }
                else
                {
                    mpp = mp;
                    current_matches = 0;
                    right += word_length;
                    left = right;
                }
            }
        }

        return result;
    }
};