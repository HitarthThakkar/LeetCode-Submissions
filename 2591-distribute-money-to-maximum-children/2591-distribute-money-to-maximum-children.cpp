class Solution
{
public:
    int distMoney(int money, int children)
    {
        // Nasty Question

        // Simple base case, not enough money to give 1$ to each
        if(money < children) return -1;

        // gave 1$ to each, now cannot give 3$ and want to give 7$
        money -= children;

        int whole = money / 7;  // ct of "bunches" of 7
        int rem = money % 7;    // remaining after making "bunches"

        // we have more bunches than no of children
        // strat : can give last children all extras  [7, 7, ..., 7+EXTRAs]
        if(whole > children) return children - 1;

        // best case, no of bunches as no of chilren and no remainders
        if(whole == children && rem == 0) return children;

        // here there are some remainders we have to give to the last one [7, 7, ..., 7+rem]
        if(whole == children) return children - 1;

        // only one case (whole < children) left, in best case we can make 'whole' no of children happy
        // but if whole = n - 1 and rem = 3 then we would have to give 4 to last, not possible so in that case 2 children unhappy
        if(whole == children - 1 && rem == 3) return children - 2;

        // else we can give 'whole' no of children 7 candies and others get rem candies
        return whole;
    }
};