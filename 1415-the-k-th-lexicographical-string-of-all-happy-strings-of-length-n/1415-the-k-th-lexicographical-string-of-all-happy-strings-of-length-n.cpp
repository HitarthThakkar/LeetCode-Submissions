class Solution
{
public:
    string getHappyString(int n, int k)
    {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";

        string res = "";
        char prev = '#';

        for (int i = 0; i < n; i++)
        {
            for (char c = 'a'; c <= 'c'; c++)
            {
                if (c == prev) continue;

                int remaining = n - i - 1;
                int count = 1 << remaining;  // number of strings starting with this prefix

                if (k > count)
                {
                    k -= count;  // skip this block
                }
                else
                {
                    res += c;
                    prev = c;
                    break;
                }
            }
        }

        return res;
    }
};