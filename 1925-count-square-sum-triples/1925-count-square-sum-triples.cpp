class Solution
{
public:
    int countTriples(int n)
    {
        int count = 0;
        for(int a = 1; a <= n; a++)
        {
            for(int b = 1; b <= n; b++)
            {
                double cSquare = (a * a) + (b * b);
                double c = sqrt(cSquare);
                int cInt = c;
                if(((cInt * cInt) == cSquare) && cInt <= n) count++;
            }
        }
        return count;
    }
};