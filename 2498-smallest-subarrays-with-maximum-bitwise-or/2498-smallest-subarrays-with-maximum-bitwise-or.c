#define max(a, b) ((a) > (b) ? (a) : (b))

void addNum(int* vec, int number, int* curOR)
{
    *curOR |= number;

    int i = 0;

    while(number)
    {
        if(number & 1) vec[i]++;
        i++;
        number = number >> 1;
    }
}

void removeNum(int* vec, int number, int* curOR)
{
    int i = 0;

    while(number)
    {
        if(number & 1) vec[i]--;
        i++;
        number = number >> 1;
    }

    *curOR = 0;
    long long int x = 1;

    for(int i = 0; i < 32; i++)
    {
        if(vec[i] > 0)
        {
            *curOR |= x;
        }
        x *= 2;
    }
}

int* smallestSubarrays(int* nums, int n, int* returnSize)
{
    int left = 0;
    int right = 0;

    int* expectation = (int*) calloc(n, sizeof(int));
    int otn = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        otn |= nums[i];
        expectation[i] = otn;
    }

    int curOR = 0;

    int *res = (int*) malloc(sizeof (int) * n);

    if(res == NULL)
    {
        free(expectation);
        * returnSize = n;
        return res;
    }

    int vec[32] = {0};

    int *p = &curOR;

    while(right < n)
    {
        addNum(vec, nums[right], p);

        while(left < n && expectation[left] == curOR)
        {
            removeNum(vec, nums[left], p);
            res[left] = max(1, right - left + 1);
            left++;
        }

        right++;
    }

    free(expectation);

    * returnSize = n;
    return res;
}