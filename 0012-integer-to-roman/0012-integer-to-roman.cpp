class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> v(4, 0); int i = 3;
        while(num) { v[i] = (num % 10); i--; num /= 10; }
        string result = "";
        if(v[0] != 0)
        {
            if(v[0] == 1) result += "M";
            else if(v[0] == 2) result += "MM";
            else result += "MMM";
        }
        if(v[1] != 0)
        {
            if(v[1] == 1) result += "C";
            else if(v[1] == 2) result += "CC";
            else if(v[1] == 3) result += "CCC";
            else if(v[1] == 4) result += "CD";
            else if(v[1] == 5) result += "D";
            else if(v[1] == 6) result += "DC";
            else if(v[1] == 7) result += "DCC";
            else if(v[1] == 8) result += "DCCC";
            else result += "CM";
        }
        if(v[2] != 0)
        {
            if(v[2] == 1) result += "X";
            else if(v[2] == 2) result += "XX";
            else if(v[2] == 3) result += "XXX";
            else if(v[2] == 4) result += "XL";
            else if(v[2] == 5) result += "L";
            else if(v[2] == 6) result += "LX";
            else if(v[2] == 7) result += "LXX";
            else if(v[2] == 8) result += "LXXX";
            else result += "XC";
        }
        if(v[3] != 0)
        {
            if(v[3] == 1) result += "I";
            else if(v[3] == 2) result += "II";
            else if(v[3] == 3) result += "III";
            else if(v[3] == 4) result += "IV";
            else if(v[3] == 5) result += "V";
            else if(v[3] == 6) result += "VI";
            else if(v[3] == 7) result += "VII";
            else if(v[3] == 8) result += "VIII";
            else result += "IX";
        }
        return result;
    }
};