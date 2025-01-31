class Solution
{
private:
    bool isOne(double x)
    {
        double one = 1.000000000000000;
        x -= one;
        return (-0.00000000000001 < x && x < 0.000000000000001);
    }
    bool isNegOne(double x)
    {
        double one = 1.000000000000000;
        x += one;
        return (-0.00000000000001 < x && x < 0.000000000000001);
    }
public:
    double myPow(double x, int n)
    {
        // Remember the past (submissions).
        double xx = 1.00000000;
        long long int nn = n; nn = abs(nn);
        if(isOne(x)) return x;
        if(isNegOne(x)) { if(n & 1) return x; return xx; }
        if(n == -2147483648) return (0.00000);
        while(nn) {
            if(nn & 1) { xx *= x; nn--; }
            x *= x; nn /= 2;
        }
        if(n < 0) return (1.0 / xx); return xx;
    }
};