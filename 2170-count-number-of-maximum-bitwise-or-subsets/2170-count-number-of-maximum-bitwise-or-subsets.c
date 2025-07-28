int recur(int i, long long int cur, long long int target, int* nums, int n)
{
    if(i == n)
    {
        if(cur == target) return 1;
        return 0;
    }

    int res = 0;

    res += recur(i + 1, cur | nums[i], target, nums, n);
    res += recur(i + 1, cur, target, nums, n);

    return res;
}

int countMaxOrSubsets(int* nums, int n)
{
    long long int target = 0;
    for(int i = 0; i < n; i++) target |= nums[i];
    return recur(0, 0, target, nums, n);
}