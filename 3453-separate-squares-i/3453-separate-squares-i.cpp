class Solution
{
public:
    double areaBelowMid(double mid, vector<vector<int>>& squares)
    {
        double answer = 0.00;
        for(const auto &square : squares)
        {
            double y = square[1], l = square[2];
            if(y < mid)
            {
                double mini = min(mid, y + l);
                answer += ((mini - y) * l);
            }
        }
        return answer;
    }
    double separateSquares(vector<vector<int>>& squares)
    {
        double totalArea = 0.00;
        for(auto s : squares) { double l = s[2]; totalArea += (l * l); }
        double desiredArea = (totalArea / 2.00);
        double l = 0.00;
        double r = 2000000000.00;
        double preci = 1e-5;
        while(r - l > preci)
        {
            double mid = ((l + r) / 2);
            if(areaBelowMid(mid, squares) < desiredArea) l = mid;
            else r = mid;
        }
        return l;
    }
};