class Solution
{
public:
    int maximum69Number (int num)
    {
        int sp = 1e8;
        int i = 1;
        int ncp = num;
        while(ncp)
        {
            int digi = (ncp % 10);
            if(digi == 6) sp = i;
            ncp /= 10;
            i *= 10;
        }

        if(sp == 1e8) return num;

        num -= (sp * 6);
        num += (sp * 9);

        return num;
    }
};