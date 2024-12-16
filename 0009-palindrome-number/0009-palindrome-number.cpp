class Solution {
public:
    bool isPalindrome(int x) {

        if(x <= -2147483648 || x >= 2147483647)
        {
            return false;
        }
        
        int n = x;

        if(n < 0)
        {
            n *= -1;
        }
        
        int arr[32];
        int i = 31;
        while(n != 0)
        {
            arr[i] = n % 10;
            n /= 10;
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

        if(x == k)
        {
            return true;
        }
        return false;
    }
};