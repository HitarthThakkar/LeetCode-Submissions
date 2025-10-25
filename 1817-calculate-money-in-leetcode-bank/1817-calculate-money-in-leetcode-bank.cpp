class Solution {
public:
    int totalMoney(int n) {
        int s = 1; int res = 0;

        if(n > 7) {
            res = 28;
            n -= 7;
            s++;

            int first = res;

            while(n > 7) {
                s++;
                n -= 7;
                first += 7;
                res += first;
            }
        }

        int l = s + n - 1;
        int one_to_l = (l * (l + 1) / 2);
        int one_to_s_minus_one = (s * (s - 1) / 2);
        res += (one_to_l - one_to_s_minus_one);
        
        return res;
    }
};