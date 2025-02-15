class Solution
{
public:
    bool recur(int number, int square, int running_number, int mul)
    {
        if (mul == 0) return false;
        if (number < 0 || running_number > number) return false;
        if (number == running_number && square == 0) return true;
        if (square == 0) return false;
        int valtoadd = ((square % 10) * mul);
        if (running_number + valtoadd <= number)
        {
            bool one = recur(number, (square / 10), running_number + valtoadd, mul * 10);
            if (one) return true;
        }
        return recur(number - running_number, square / 10, (square % 10), 10);
    }
    int punishmentNumber(int n)
    {
        int answer = 0;
        for (int i = 1; i <= n; i++) if (recur(i, (i * i), 0, 1)) answer += (i * i);
        return answer;
    }
};