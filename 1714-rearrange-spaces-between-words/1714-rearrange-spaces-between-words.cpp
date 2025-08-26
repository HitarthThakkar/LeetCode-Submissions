class Solution
{
public:
    string reorderSpaces(string text)
    {
        int n = text.length();
        int spc = 0, gap = 0;

        for(int i = 0; i < n; i++)
        {
            if(text[i] == ' ')
            {
                spc++;
                if(i > 0 && text[i - 1] != ' ') gap++;
            }
        }

        if(text.back() == ' ') gap--;

        string result;

        if(gap == 0)
        {
            for(int i = 0; i < n; i++) {
                if(text[i] != ' ') result += text[i];
            }
            while(spc--) result += ' ';

            return result;
        }

        int tp = (spc / gap), i = 0;

        // cout << spc << " " << gap  << " " << tp << endl;

        while(i < n)
        {
            if(i > 0 && text[i - 1] != ' ' && text[i] == ' ' && spc >= tp)
            {
                while(text[i] == ' ') i++;
                for(int j = 0; j < tp; j++) result += ' ';
                spc -= tp;
            }
            else if(text[i] != ' ')
            {
                result += text[i];
                i++;
            }
            else i++;
        }

        // int leftover = spc - (gap * tp);

        // cout << leftover << endl;

        for(int i = 0; i < spc; i++) result += ' ';

        return result;
    }
};