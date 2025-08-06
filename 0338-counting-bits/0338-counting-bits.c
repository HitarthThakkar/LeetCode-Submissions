int* countBits(int n, int* returnSize)
{
    int* arr = (int*) malloc((n + 1) * sizeof(int));
    arr[0] = 0;

    for(int i = 1; i < n + 1; i++)
    {
        if(i & 1) arr[i] = arr[i / 2] + 1;
        else arr[i] = arr[i / 2];
    }

    *returnSize = n + 1;

    return arr;
}