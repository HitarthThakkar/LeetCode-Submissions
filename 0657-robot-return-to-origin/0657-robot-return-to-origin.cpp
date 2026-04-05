class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for(auto ch : moves) {
            if(ch == 'L') h--;
            else if(ch == 'R') h++;
            else if(ch == 'U') v++;
            else v--;
        }
        return (h == 0 && v == 0);
    }
};