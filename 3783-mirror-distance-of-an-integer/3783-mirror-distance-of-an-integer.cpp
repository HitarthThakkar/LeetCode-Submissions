class Solution {
public:
    int mirrorDistance(int n) {
        int ncp = n, rev = 0;
        while(ncp) {
            rev = (rev * 10) + (ncp % 10);
            ncp /= 10;
        }
        return abs(rev - n);
    }
};