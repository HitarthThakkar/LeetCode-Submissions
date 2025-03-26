class Solution
{
public:
    int getSum(int a, int b)
    {
        // xor is same as addition when
        // any bit is not common b/w a and b.
        // what to do when a bit is common ?
        // 1 in a and 1 in b should not be 0 
        // in case of addition, but xor 
        // will make them 0 cuz they are same.
        int carry = -1, sum;
        while(carry != 0)
        {
            sum = a ^ b;
            carry = ((a & b) << 1);
            a = sum;
            b = carry;
        }
        return sum;
    }
};