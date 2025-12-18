class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0)
        {
            return false;
        }
        
        int n = x;
        
        int arr[11];
        int i = 10;
        while(n != 0)
        {
            arr[i] = n % 10;
            n /= 10;
            i--;
        }
        i++;

        long long int k = 0;
        long long int mul = 1;
        for(int j = i; j < 11; j++)
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