#define min(a, b) (a) < (b) ? (a) : (b)
int minMoves(int* nums, int n)
{
    int res = 0;
    int mini = 1e9 + 1;
    for(int i = 0; i < n; i++) mini = min(mini, nums[i]);
    for(int i = 0; i < n; i++) res += (nums[i] - mini);
    return res;
}