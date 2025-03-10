class Solution
{
public:
    int maximumSwap(int num)
    {
        vector<int> f(10, 0);
        int nod = 0;
        int ncp = num;
        while(ncp)
        {
            int digit = (ncp % 10);
            f[digit]++;
            nod++;
            ncp /= 10;
        }
        int i = 9;
        int div = 1;
        for(int ii = 0; ii < nod - 1; ii++) div *= 10;
        int baddigit, gooddigit,baddiv,ind;bool mila=false;
        for(int ii = 0; ii < nod; ii++)
        {
            int digit = ((num - (num % div)) / div) % 10;
            // cout << "$ " << num << " " << div << " " << digit << endl;
            while(f[i] == 0) i--;
            if(digit < i)
            {
                baddigit = digit;
                gooddigit = i;
                baddiv = div;
                ind = ii;
                mila = true;
                break;
            }
            else f[i]--;
            div /=10;
        }

        if(mila)
        {
            // cout << endl << endl;
            int gooddiv;
            int divcp = baddiv / 10;
            while(divcp)
            {
                int digit = ((num - (num % divcp)) / divcp) % 10;
                // cout << "$ " << num << " " << divcp << " " << digit << endl;
                if(digit == gooddigit)
                {
                    gooddiv = divcp;
                    // break;
                }
                divcp /= 10;
            }

            // baddigit, gooddigit, gooddiv, baddiv.

            // cout << endl << endl;
            // cout << baddigit << " " << gooddigit << " " << gooddiv << " " << baddiv << endl;

            num -= (baddigit * baddiv);
            num += (gooddigit * baddiv);
            num -= (gooddigit * gooddiv);
            num += (baddigit * gooddiv);
        }
        return num;
    }
};