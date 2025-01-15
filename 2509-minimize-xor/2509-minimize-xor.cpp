class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int one = __builtin_popcount(num1), two = __builtin_popcount(num2);
        cout << one << " " << two << endl;
        if(one > two)
        {
            int till = one - two;
            int ans = 0;
            int mul = 1;

            while(num1)
            {
                int bit = (num1 & 1);
                if(bit && till > 0)
                {
                    till--;
                }
                else
                {
                    if(bit)
                    {
                        ans += mul;
                    }
                }
                num1 /= 2;
                mul *= 2;
            }

            return ans;

        }
        else if(two > one)
        {
            int left = two - one;
            int ans = 0;
            int mul = 1;

            while(num1)
            {
                int bit = (num1 & 1);
                if(bit)
                {
                    ans += mul;
                }
                else
                {
                    if(left > 0)
                    {
                        ans += mul;
                        left--;
                    }
                }
                num1 /= 2;
                mul *= 2;
            }

            while(left > 0)
            {
                ans += mul;
                mul *= 2;
                left--;
            }

            return ans;
        }
        else
        {
            return num1;
        }
    }
};