class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int opening = 0;
        int extraopening = 0;

        for(auto c : s)
        {
            if(c == '(') opening++;
            else {
                if(opening > 0) opening--;
                else extraopening++;
            }
        }

        return (extraopening + opening);
    }
};