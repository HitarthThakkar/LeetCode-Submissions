class Solution
{
private:
    int getMaxBouquetsAtMidDay(int the_D_day, vector<int>& bloomDay, int k)
    {
        int maxBouquets = 0;
        int running_count = 0;

        for(int daysToBloom : bloomDay)
        {
            if(daysToBloom <= the_D_day) running_count++;
            else running_count = 0;

            if(running_count == k) maxBouquets++, running_count = 0;
        }

        return maxBouquets;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int min_days = 0;
        int max_days = 0;

        for(int day : bloomDay) max_days = max(max_days, day);

        int minimum_Days = -1;

        while(min_days <= max_days)
        {
            int mid_day = (min_days + max_days) / 2;

            if(getMaxBouquetsAtMidDay(mid_day, bloomDay, k) >= m)
            {
                minimum_Days = mid_day;
                max_days = mid_day - 1;
            }
            else
            {
                min_days = mid_day + 1;
            }
        }

        return minimum_Days;
    }
};