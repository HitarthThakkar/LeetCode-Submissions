class Solution
{
public:
    int countCollisions(string directions)
    {
        // was thinking about the question like 2-3 hrs
        // over complicated the question, never thought about what's needed.

        // Let's define 'outlier' first :
        // those who won't collide are outliers.
        // they are leftmost lefts, rightmost rights.
        
        // now as per the problem definition,
        // when 2 moving cars collide they add 2 points
        // [let's say each moving car added 1 point and thus total addition of 2 points]
        // when 1 moving and 1 stationary collide they add 1 point
        // [let's say the moving one added that point, and stationary added nothing]

        // so basically when a 'L' or 'R' type car collides it adds 1 point in answer.
        // this above is simplified rule of those both combined.

        // now from all the 'L' and 'R' cars we have to subtract all the 'outliers'.
        // the ones which collide will add 1 point (1 point by all those cars collectively)

        // and finding this answer is easy af.

        // so if I had shifted my mind
        // from how to simulate the whole thing and which car will collide which one and all that
        // i might would've reached the solution by understanding this simple fact.
        // ALWAYS TRY TO SIMPLIFY THE PROBLEM.

        int n = directions.length();

        int l = 0;
        while(l < n && directions[l] == 'L') l++;   // removing leftmost lefts

        int r = n - 1;
        while(r >= 0 && directions[r] == 'R') r--;   // removing rightmost rights

        // now in l to r all cars will collide.
        // but the ones which are moving will add point, not the stationary ones.

        int res = 0;

        for(int i = l; i <= r; i++)
        {
            if(directions[i] == 'S') continue;
            else res++;
        }
        
        return res;
    }
};