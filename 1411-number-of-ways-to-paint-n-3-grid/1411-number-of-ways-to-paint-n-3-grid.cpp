class Solution {
public:
    int numOfWays(int n) {
        long long int typeAcount = 6;
        long long int typeBcount = 6;
        long long int m = 1e9 + 7;

        for(int i = 2; i <= n; i++)
        {
            typeAcount %= m;
            typeBcount %= m;

            long long int bFromTypeB = (typeBcount * 2) % m;
            long long int aFromTypeB = (typeBcount * 2) % m;

            long long int bFromTypeA = (typeAcount * 2) % m;
            long long int aFromTypeA = (typeAcount * 3) % m;

            typeAcount = ((aFromTypeA % m) + (aFromTypeB % m)) % m;
            typeBcount = ((bFromTypeA % m) + (bFromTypeB % m)) % m;
        }

        return (((typeAcount % m) + (typeBcount % m)) % m);
    }
};