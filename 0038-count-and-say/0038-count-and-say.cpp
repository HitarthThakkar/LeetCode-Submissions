class Solution
{
public:
    string countAndSay(int n)
    {
        string base = "1";
        for(int i = 2; i <= n; i++)
        {
            string nextbase = "";
            char prev = 'a'; int freq = 0;
            for(auto ch : base)
            {
                if(ch != prev)
                {
                    if(freq > 0) { nextbase += to_string(freq); nextbase += prev; }
                    prev = ch; freq = 1;
                }
                else freq++;
            }
            if(freq > 0) { nextbase += to_string(freq); nextbase += prev; }
            base = nextbase;
        }
        return base;
    }
};