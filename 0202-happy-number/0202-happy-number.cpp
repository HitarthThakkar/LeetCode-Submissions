class Solution
{
public:
    // Cycle detection algo
    // We can also use map/set to detect all previous 'n' and when we visit smth
    // previously visited then we say got cycle and false
    // that is good in the runtime way but requires memory
    // here memory is nothing, maybe require some time more than that.

    /*
        Let’s say \U0001d45b has \U0001d451 digits. Then the maximum value of \U0001d453(\U0001d45b) occurs when each digit is 9.
        The square of 9 is 81 so, with \U0001d451 digits:
            \U0001d453(\U0001d45b) ≤ (81 * \U0001d451)
        But:
            The number of digits \U0001d451 is at most log_10(\U0001d45b) + 1.

        So \U0001d453(\U0001d45b) ≤ 81⋅(log_10(\U0001d45b) + 1)

        This grows much more slowly than \U0001d45b. So as \U0001d45b → ∞, \U0001d453(\U0001d45b) ≪ \U0001d45b.

        Conclusion: Large values of \U0001d45b are immediately reduced to much smaller values
                    after a few iterations.

    */

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