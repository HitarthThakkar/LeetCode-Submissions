class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int xcp = x;
        vector<int> v;
        while(xcp != 0) {
            v.push_back(xcp % 10);
            xcp /= 10;
        }

        long long int revx = 0;
        long long int mul = 1;
        for(int j = v.size() - 1; j >= 0; j--) {
            revx += (v[j] * mul);
            mul *= 10;
        }

        return (x == revx);
    }
};