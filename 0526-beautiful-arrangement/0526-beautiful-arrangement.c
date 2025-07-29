int recur(int index, int n, int* choices)
{
    if(index == n + 1) return 1;

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        int num = i + 1;
        if(choices[i] == 1 && (num % index == 0 || index % num == 0))
        {
            choices[i] = 0;
            res += recur(index + 1, n, choices);
            choices[i] = 1;
        }
    }

    return res;
}

int countArrangement(int n)
{
    int choices[n];
    for(int i = 0; i < n; i++) choices[i] = 1;
    return recur(1, n, choices);
}