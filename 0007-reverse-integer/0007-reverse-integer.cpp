class Solution
{
public:
    int reverse(int x)
    {
        /*
            Intended Approach

            To "pop" and "push" digits without the help of some auxiliary stack/array,
            we can use math.

            # pop operation
            pop = x % 10;
            x /= 10;

            # push operation:
            temp = rev * 10 + pop;
            rev = temp;

            # However, this approach is dangerous, because the statement 
            temp = rev * 10 + pop can cause overflow.

            Luckily, it is easy to check beforehand whether or this statement 
            would cause an overflow.

            To explain, lets assume that rev is positive.

            If temp = rev * 10 + pop causes overflow, then it must be that
            rev /geq 10 * INTMAX

            If rev greater than 10 * INTMAX, then we are guarenteed to overflow.
            BUT WHAT IF rev == 10 * INTMAX ??

            Analyze :
            We know INTMAX = 2147483647
            INTMAX / 10 = 214748364 {We do floor here its integer division}
            so now, 
            IF rev < 214748364, you're safe no matter the pop (0–9).
            IF rev > 214748364, you'll definitely overflow.
            Now the critical case:
            If rev == 214748364, then the next digit pop must be carefully checked.
            temp = 214748364 * 10 + pop

            Now, what is the maximum digit we can add without exceeding INT_MAX?
            2147483640 + pop ≤ 2147483647 ⇒ pop ≤ 7
            So if pop > 7, the total exceeds INT_MAX, and overflow occurs.

            SAME WE CAN DO FOR NEGATIVE BOUNDARY IN WHICH IF POP IS LESS THAN -8 WE
            WILL OVERFLOW.
        */

        int rev = 0;

        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;

            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;

            rev = rev * 10 + pop;
        }
        
        return rev;
    }
};