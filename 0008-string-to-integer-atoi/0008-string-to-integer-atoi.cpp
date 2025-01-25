class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int ind = 0;

        while(ind < n && s[ind] == ' ')
        {
            ind++;
        }

        if(ind == n)
        {
            return 0;
        }

        int sign = 1;

        if(s[ind] == '-')
        {
            sign = 0;
            ind++;
        }
        else if(s[ind] == '+')
        {
            ind++;
        }

        string str = "";

        for(int i = ind; i < n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                str += s[i];
            }
            else
            {
                break;
            }
        }
        
        reverse(str.begin(), str.end());

        int ep = str.length() - 1;

        while(ep >= 0 && str[ep] == '0')
        {
            ep--;
        }

        if(ep == -1)
        {
            return 0;
        }

        long long int num = 0;
        long long int mul = 1;

        for(int i = 0; i <= ep; i++)
        {
            long long int digit = (int)(str[i] - 48);

            if(sign == 0)
            {
                num -= (mul * 1LL * digit);
            }
            else
            {
                num += (mul * 1LL * digit);
            }

            if(num >= INT_MAX)
            {
                return INT_MAX;
            }
            else if(num <= INT_MIN)
            {
                return INT_MIN;
            }
            else if(mul >= INT_MAX)
            {
                if(sign == 0)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }
            }

            mul *= 10;
        }

        return ((int)num);
    }
};