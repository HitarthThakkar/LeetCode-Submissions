class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int n = word.length(), j = 0;
        vector<int> lps(n, 0);
        for(int i = 1; i < n; i++)
        {
            while(j > 0 && word[j] != word[i]) j = lps[j - 1];
            if(word[j] == word[i]) lps[i] = ++j;
        }
        int lentocut = n - lps[n - 1];
        if(lps[n - 1] + 1 == n) return 1;
        if(lentocut == n) {
            if(n % k == 0) return (n / k); else return ((n / k) + 1);
        }
        else if(lentocut == k) { return 1; }
        else if(lentocut > k)
        {
            int actualcut = ((lentocut / k) * k);
            if(actualcut == lentocut) return (lentocut / k);
            if(actualcut + k - 1 > n - 1) return (lentocut / k) + 1;
            word[actualcut + k - 1] = '#';
            return minimumTimeToInitialState(word, k);
        }
        else
        {
            word[k - 1] = '@';
            return minimumTimeToInitialState(word, k);
        }
    }
};