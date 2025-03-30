#define ll long long int
#define pai pair<int, int>

ll gcd(ll a, ll b) { if(b == 0) return 0; else return gcd(b, a % b); }

class Solution
{
public:
    long long numberOfSubsequences(vector<int>& nums)
    {
        // 2025 Hiring Prep Sprint Week_3 Q6
        ll n = nums.size();
        map<pai, int> freq; // Double has precision issues, so 3/4 = {3, 4} and not 0.75.
        // BUT 6/8 = 3/4 = 0.75, so we have to SIMPLIFY "EVERY" fraction 'before storing' into map.
        // SIMPLIFY means divide by their GCD.

        // Building initial freq map
        for(ll r = 4; r < n; r++)
        {
            for(ll s = r + 2; s < n; s++)
            {
                ll d = gcd(nums[r], nums[s]);
                freq[{nums[s] / d, nums[r] / d}]++;
            }
        }

        ll answer = 0;

        for(ll q = 2; q + 4 < n; q++)
        {
            // Adding matching r,s pairs to this particular p,q
            for(ll p = q - 2; p >= 0; p--)
            {
                ll d = gcd(nums[p], nums[q]);
                pai fraction = {nums[p] / d, nums[q] / d};
                answer += freq[fraction];
            }

            // As q will move forward in next iteration,
            // some r,s pairs which were in map will be haved to remove.
            // Doing exactly that.

            // (DRY_RUN) {or} (TLE_ELIMINATIORS_Video)

            ll r = q + 2;

            for(ll s = r + 2; s < n; s++)
            {
                ll d = gcd(nums[r], nums[s]);
                freq[{nums[s] / d, nums[r] / d}]--;
            }
        }

        return answer;
    }
};