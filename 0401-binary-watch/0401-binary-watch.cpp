class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> res;

        for(int h = 0; h <= 11; h++)
        {
            for(int m = 0; m <= 59; m++)
            {
                int hbpc = __builtin_popcount(h);
                int mbpc = __builtin_popcount(m);

                if(hbpc + mbpc == turnedOn)
                {
                    string temp = "";
                    
                    if(h < 10)
                    {
                        temp += (char) ('0' + h);
                    }
                    else
                    {
                        int val = h / 10;
                        int v2 = h % 10;
                        temp += (char) ('0' + val);
                        temp += (char) ('0' + v2);
                    }

                    temp += ':';

                    if(m < 10)
                    {
                        temp += '0';
                        temp += (char) ('0' + m);
                    }
                    else
                    {
                        int val = m / 10;
                        int v2 = m % 10;
                        temp += (char) ('0' + val);
                        temp += (char) ('0' + v2);
                    }

                    res.push_back(temp);
                }
            }
        }

        return res;
    }
};