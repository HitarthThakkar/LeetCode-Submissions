class Solution
{
public:
    string largestOddNumber(string num)
    {
        int lastOdd = -1;
        string ans;
        
        for(int i = num.length() - 1; i >= 0; i--)
        {
            if(((int)num[i] - 48) & 1)
            {
                lastOdd = i;
                break;
            }
        }

        if(lastOdd == -1)
        {
            return ans;
        }
        else
        {
            return num.substr(0, lastOdd + 1);
        }
    }
};