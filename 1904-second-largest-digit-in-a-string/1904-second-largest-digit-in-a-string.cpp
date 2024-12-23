class Solution
{
public:
    int secondHighest(string s)
    {
        int largest = -1; int second_largest = -1;
        for(auto ch : s)
        {
            if(ch >= '0' && ch <= '9')
            {
                int chVal = ((int) ch - 48);
                if(chVal > largest) second_largest = largest, largest = chVal;
                else if(chVal < largest && chVal > second_largest) second_largest = chVal;
            }
        }
        return second_largest;
    }
};