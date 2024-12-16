class Solution {
public:
    int reverse(int x) {
        
        if(x > 2147483647 || x <= -2147483648)
        {
            return 0;
        }

        bool neg = false;
        if(x < 0)
        {
            neg = true;
            x *= -1;
        }
        
        int arr[32];
        int i = 31;
        while(x != 0)
        {
            arr[i] = x % 10;
            x /= 10;
            i--;
        }
        i++;

        long long int k = 0;
        long long int mul = 1;
        for(int j = i; j < 32; j++)
        {
            k += (arr[j] * mul);
            mul *= 10;
        }

        if(k > 2147483647)
        {
            return 0;
        }

        if(neg)
        {
            return (k * -1);
        }
        else
        {
            return k;
        }
    }
};