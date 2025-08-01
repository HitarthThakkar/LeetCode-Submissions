/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    // Pointer to an array of pointers each having an address to an array
    int** triangle = (int**) malloc(numRows * sizeof(int*));

    // Pointer to an array of ints each having row length of i'th row
    *returnColumnSizes = (int*) malloc(numRows * sizeof(int));

    for(int i = 0; i < numRows; i++)
    {
        // Each row having (i + 1) length integers
        triangle[i] = (int*) malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        triangle[i][0] = 1, triangle[i][i] = 1;

        for(int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    *returnSize = numRows;

    return triangle;
}