class Solution
{
private:
    long long atleastK(string word, int k)
    {
        int n = word.length();
        int left = 0;
        int right = 0;
        long long answer = 0;
        int a, e, i, o, u, c;
        a = e = i = o = u = c = 0;

        while(right < n)
        {
            char ch = word[right];

            if(ch == 'a') a++;
            else if(ch == 'e') e++;
            else if(ch == 'i') i++;
            else if(ch == 'o') o++;
            else if(ch == 'u') u++;
            else c++;

            while(a > 0 && e > 0 && i > 0 && o > 0 && u > 0 && c >= k)
            {
                answer += (n - right);

                char chh = word[left];
                if(chh == 'a') a--;
                else if(chh == 'e') e--;
                else if(chh == 'i') i--;
                else if(chh == 'o') o--;
                else if(chh == 'u') u--;
                else c--;

                left++;
            }

            right++;
        }

        return answer;
    }
public:
    long long countOfSubstrings(string word, int k)
    {
        long long Kans = atleastK(word, k);
        long long Kp1ans = atleastK(word, k + 1);
        return (Kans - Kp1ans);
    }
};