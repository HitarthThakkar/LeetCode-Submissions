class Solution
{
public:
    string largestOddNumber(string num)
    {
        int loi = -1;
        for(int i = num.length() - 1; i >= 0; i--)
        {
            if(((int)num[i] - 48) & 1)
            {
                loi = i;
                break;
            }
        }
        if(loi == -1) return "";
        else return num.substr(0, loi + 1);
    }
};