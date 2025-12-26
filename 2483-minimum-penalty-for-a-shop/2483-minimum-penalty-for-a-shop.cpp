class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int nTillNow = 0;
        int yLeftInRight = 0;
        for(auto c : customers) if(c == 'Y') yLeftInRight++;

        int minPenaltyTillNow = 1e9;
        int minPenaltyIndex = -1;
        
        for(int i = 0; i < customers.length(); i++)
        {
            int curPenalty = yLeftInRight + nTillNow;

            if(curPenalty < minPenaltyTillNow) {
                minPenaltyTillNow = curPenalty;
                minPenaltyIndex = i;
            }

            if(customers[i] == 'N') nTillNow++;
            else yLeftInRight--;
        }

        int curPenalty = yLeftInRight + nTillNow;

        if(curPenalty < minPenaltyTillNow) {
            minPenaltyTillNow = curPenalty;
            minPenaltyIndex = customers.length();
        }

        return minPenaltyIndex;
    }
};