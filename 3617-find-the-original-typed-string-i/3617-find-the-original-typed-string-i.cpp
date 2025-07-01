class Solution
{
public:
    int possibleStringCount(string word)
    {
        int ans = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int j = i;
            while(j + 1 < word.length() && word[j + 1] == word[j])
            {
                j++;
            }
            ans += (j - i);
            i = j;
        }
        return (ans + 1);
    }
};