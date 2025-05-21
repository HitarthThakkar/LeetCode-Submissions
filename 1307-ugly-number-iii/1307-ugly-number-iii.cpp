class Solution
{
public:
    /*
        We HAVE to write our own LCM and GCD functions for long long handling.
        Predefined are fine for int but not for this case cuz,
        a and b canbe in range of int only but lcm(a, b) canbe outside of int range.
    */
    long long int gcd(long long int a, long long int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long int lcm(long long int a, long long int b) {
        return (a / gcd(a, b)) * b;
    }

    long long int f(long long int k, long long int a, long long int b, long long int c)
    {
        long long int result = (k / a);
        result += (k / b);
        result += (k / c);
        result -= (k / lcm(a, b));
        result -= (k / lcm(b, c));
        result -= (k / lcm(a, c));
        result += (k / lcm(lcm(a, b), c));
        return result;
    }

    int nthUglyNumber(int n, int a, int b, int c)
    {
        /*
            F(k) = ∣ {x ≤ k ∣ x ≡ 0(moda) or x ≡ 0(modb) or x ≡ 0(modc)} ∣
            F(k) -> count of numbers from [1, k] which are divisible by a, b or c.
            So, all x's from 1 to k which are divisible by a, b or c are counted.
            Set theory
            Think that we do not have b or c, just a.
            Count of all x's from 1 to k which are divisible by a;
            = [k / a], where [] denotes floor function.
            But overcounting will happen if a number is divisible by more than one person.
            like by (a and b) OR (b and c) OR (a and c) OR (a and b and c).
            SET THEORY
        */

        /*
            Let’s define three sets:
            A = multiples of a ≤ k
            B = multiples of b ≤ k
            C = multiples of c ≤ k
            We want to compute: ∣\U0001d434 ∪ \U0001d435 ∪ \U0001d436∣
        */

        long long int lo = 1;
        long long int hi = 2e9;
        long long int ans = hi;

        while(lo <= hi)
        {
            long long int mid = (lo + hi) / 2;

            long long int ctUglies = f(mid, 1LL * a, 1LL * b, 1LL * c);   // get me f(k)

            if(ctUglies >= n)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};