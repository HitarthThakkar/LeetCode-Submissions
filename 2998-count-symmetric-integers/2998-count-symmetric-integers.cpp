class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int result = 0;
        for (int number = low; number <= high; number++)
        {
            if (number < 100 && number % 11 == 0)
            {
                result++;
            }
            else if (1000 <= number && number < 10000)
            {
                int left = number / 1000 + (number % 1000) / 100;
                int right = (number % 100) / 10 + number % 10;
                result += ((left == right) ? 1 : 0);
            }
        }
        return result;
    }
};