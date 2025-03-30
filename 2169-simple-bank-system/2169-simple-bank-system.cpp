class Bank
{
public:
    int n; vector<long long> bal;
    Bank(vector<long long>& balance) { bal = balance; n = bal.size(); }
    bool transfer(int account1, int account2, long long money)
    {
        if(account1 > n || account2 > n || bal[account1 - 1] < money) return false;
        bal[account1 - 1] -= money; bal[account2 - 1] += money; return true;
    }
    bool deposit(int account, long long money)
    {
        if(account > n) return false;
        bal[account - 1] += money; return true;
    }
    bool withdraw(int account, long long money)
    {
        if(account > n || bal[account - 1] < money) return false;
        bal[account - 1] -= money; return true;
    }
};