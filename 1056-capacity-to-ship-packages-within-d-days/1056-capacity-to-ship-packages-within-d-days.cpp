class Solution
{
private:
    int MinDaysForMidCapacity(int capacity, vector<int>& weights)
    {
        int days = 1;
        int cur_weight = 0;

        for(auto weight : weights)
        {
            if(weight > capacity)
            {
                return 1e9;
            }

            if(cur_weight + weight > capacity)
            {
                days++;
                cur_weight = weight;
            }
            else
            {
                cur_weight += weight;
            }
        }

        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int min_capacity = *max_element(weights.begin(), weights.end());
        int max_capacity = 0;
        for(int weight : weights) max_capacity += weight;

        int optimal_capacity = max_capacity;

        while(min_capacity <= max_capacity)
        {
            int mid_capacity = (min_capacity + max_capacity) / 2;

            if(MinDaysForMidCapacity(mid_capacity, weights) <= days)
            {
                optimal_capacity = min(optimal_capacity, mid_capacity);
                max_capacity = mid_capacity - 1;
            }
            else
            {
                min_capacity = mid_capacity + 1;
            }
        }
        return optimal_capacity;
    }
};