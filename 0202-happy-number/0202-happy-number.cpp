class Solution
{
public:
    // Cycle detection algo
    // We can also use map to detect all previous 'n' and when we visit smth
    // previously visited then we say got cycle and false
    // that is good in the runtime way but requires memory
    // here memory is nothing, maybe require some time more than that.
    int digitSquareSum(int n)
    {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
            if(fast == 1) return true;
        } while(slow != fast);
        return false;
    }
};