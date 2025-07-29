void fill(int* mapping)
{
    char* firstRow = "qwertyuiop";
    char* secondRow = "asdfghjkl";
    char* thirdRow = "zxcvbnm";

    for(int i = 0; i < strlen(firstRow); i++)
    {
        int charint = (int) firstRow[i];
        mapping[charint - 97] = 1;
    }

    for(int i = 0; i < strlen(secondRow); i++)
    {
        int charint = (int) secondRow[i];
        mapping[charint - 97] = 2;
    }

    for(int i = 0; i < strlen(thirdRow); i++)
    {
        int charint = (int) thirdRow[i];
        mapping[charint - 97] = 3;
    }
}

char** findWords(char** words, int n, int* returnSize)
{
    int mapping[26];
    fill(mapping);

    char** returnWords = NULL;
    *returnSize = 0;
    int returnCapacity = 4;

    returnWords = malloc(returnCapacity * sizeof(char *));

    for(int i = 0; i < n; i++)
    {
        int len = strlen(words[i]);
        int good = 1;

        int charint = (int) (tolower(words[i][0]));
        int prev = mapping[charint - 97];

        for(int j = 1; j < len; j++)
        {
            int charint = (int) (tolower(words[i][j]));
            int cur = mapping[charint - 97];

            if(cur != prev)
            {
                good = 0;
                break;
            }

            prev = cur;
        }

        if(good)
        {
            if(*returnSize == returnCapacity)
            {
                returnCapacity *= 2;
                returnWords = realloc(returnWords, returnCapacity * sizeof(char *));
            }

            returnWords[*returnSize] = malloc(strlen(words[i]) + 1);
            strcpy(returnWords[*returnSize], words[i]);
            (*returnSize)++;    // GOD \U0001f6d0\U0001f64f\U0001f3fb\U0001f64f\U0001f3fb\U0001f64f\U0001f3fb
        }
    }

    return returnWords;
}