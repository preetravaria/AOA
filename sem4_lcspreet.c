#include <stdio.h>
#include <string.h>
// #include <conio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char S1[20], char S2[20], char S3[20])
{
    int m = strlen(S1);
    int n = strlen(S2);
    int db[30][30];
    int i, j, index;

    for (i = 0; i <= m; i++)
        db[i][0] = 0;

    for (j = 0; j <= n; j++)
        db[0][j] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                db[i][j] = db[i - 1][j - 1] + 1;
            }
            else
            {
                db[i][j] = max(db[i - 1][j], db[i][j - 1]);
            }
        }
    }
    // printing the lcs
    index = db[m][n];
    S3[index] = '\0'; // setting the terminating character
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            S3[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (db[i - 1][j] > db[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Sequence is: %s\n", S3);
    return db[m][n];
}

int main()
{
    char S3[20];
    char S1[20] = "algorithm";
    char S2[20] = "arithmetic";

    printf("\nThe Longest Common Subsequence is %d", lcs(S1, S2, S3));
    return 0;
}
