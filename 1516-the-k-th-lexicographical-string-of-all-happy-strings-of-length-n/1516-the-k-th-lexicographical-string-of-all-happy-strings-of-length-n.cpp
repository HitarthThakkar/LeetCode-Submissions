class Solution
{
private:
    bool recur(int ci, string &temp, int n, int &k)
    {
        if(ci == n)
        {
            k--;
            return (k == 0);
        }

        char npc = 'd';
        if(temp.length() > 0) npc = temp.back();

        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(ch != npc)
            {
                temp += ch;
                if(recur(ci + 1, temp, n, k)) return true;
                temp.pop_back();
            }
        }

        return false;
    }
public:
    string getHappyString(int n, int k)
    {
        string temp = "";
        if(recur(0, temp, n, k)) return temp;
        return "";
    }
};