int countHillValley(int* nums, int n)
{
    int left[n];
    for(int i = 0; i < n; i++) left[i] = -1;

    int vec[n];
    int ind = -1;

    for(int i = 0; i < n; i++)
    {
        int tind = ind;

        while(tind >= 0)
        {
            if(vec[tind] != nums[i])
            {
                left[i] = vec[tind];
                break;
            }
            tind--;
        }

        if(ind == -1 || vec[ind] != nums[i]) vec[++ind] = nums[i];
    }

    // for(int i = 0; i < n; i++) printf("%d ", left[i]);
    // printf("\n");

    int right[n];
    for(int i = 0; i < n; i++) right[i] = -1;

    ind = n;

    for(int i = n - 1; i >= 0; i--)
    {
        int tind = ind;

        while(tind < n)
        {
            if(vec[tind] != nums[i])
            {
                right[i] = vec[tind];
                break;
            }
            tind++;
        }

        if(ind == n || vec[ind] != nums[i]) vec[--ind] = nums[i];
    }

    // for(int i = 0; i < n; i++) printf("%d ", right[i]);

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(left[i] == -1 || right[i] == -1) continue;
        if(i > 0 && nums[i - 1] == nums[i]) continue;

        if(left[i] < nums[i] && nums[i] > right[i]) count++;
        if(left[i] > nums[i] && nums[i] < right[i]) count++;
    }

    return count;
}