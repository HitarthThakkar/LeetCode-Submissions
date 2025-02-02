class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int ans = 0;

        for(char hor : {'E', 'W'})
        {
            for(char ver : {'N', 'S'})
            {

                // We have to change 'hor' and 'ver'.
                // We are opposing them, not supporting.

                int remainingK = k;
                int netX = 0;
                int netY = 0;

                for(char ch : s)
                {
                    if(ch == hor && remainingK)
                    {
                        ch = (ch == 'W') ? 'E' : 'W';
                        remainingK--;
                    }
                    else if(ch == ver && remainingK)
                    {
                        ch = (ch == 'N') ? 'S' : 'N';
                        remainingK--;
                    }

                    netX += (ch == 'E');
                    netX -= (ch == 'W');
                    netY += (ch == 'N');
                    netY -= (ch == 'S');

                    ans = max(ans, abs(netX) + abs(netY));
                }

            }
        }

        return ans;
    }
};