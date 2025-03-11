class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int left = 0;
        int right = 0;
        int a = 0, b = 0, c = 0;
        int answer = 0;

        while(right < n)
        {
            if(s[right] == 'a') a++;
            else if(s[right] == 'b') b++;
            else if(s[right] == 'c') c++;

            while(a > 0 && b > 0 && c > 0)
            {
                answer += (n - right);
                if(s[left] == 'a') a--;
                else if(s[left] == 'b') b--;
                else if(s[left] == 'c') c--;
                left++;
            }

            right++;
        }

        return answer;
    }
};