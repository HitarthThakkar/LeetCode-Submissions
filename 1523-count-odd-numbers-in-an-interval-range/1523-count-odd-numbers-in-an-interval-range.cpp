class Solution {
public:
    int countOdds(int low, int high) {
        if(high & 1) high++;
        if(low % 2 == 0) low++;
        return ((high - low + 1) / 2);
    }
};