class Solution
{
private:
    bool recur(int n, int p)
    {
        if(n == 0) return true;
        if(n < 0) return false;
        int val = pow(3, p);
        if(n < val) return false;
        return (recur(n, p + 1) || recur(n - val, p + 1));
    }
public:
    bool checkPowersOfThree(int n)
    {
        return recur(n, 0);
    }
};