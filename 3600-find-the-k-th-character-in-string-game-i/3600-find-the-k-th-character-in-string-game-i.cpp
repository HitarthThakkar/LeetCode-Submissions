class Solution
{
public:
    char kthCharacter(int k)
    {
        string str = "a";
        while(k >= str.length())
        {
            int sz = str.length();
            for(int i = 0; i < sz; i++)
            {
                char ch = str[i];
                if(ch == 'z') str += 'a';
                else str += ((char) ch + 1);
            }
        }
        return str[k - 1];
    }
};