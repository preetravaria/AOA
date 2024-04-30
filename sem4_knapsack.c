#include <stdio.h>

int n = 5;
int profit[10] = {4, 2, 2, 1, 10};
int weight[10] = {12, 1, 2, 1, 4};
int W = 15;

void knapsack()
{
    int used[5] = {0, 0, 0, 0, 0};
    float totalprofit, lastprofit, secondlastprofit;
    int weileft, secondlastweight, i, bestfit;

    weileft = W;

    while (weileft > 0)
    {
        bestfit = -1;
        for (int i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((bestfit == -1) || ((float)profit[i] / weight[i] > (float)profit[bestfit] / weight[bestfit])))
            {
                bestfit = i;
            }
        }
        used[bestfit] = 1;
        weileft -= weight[bestfit];
        totalprofit += profit[bestfit];

        if (weileft >= 0)
        {
            printf("added object %d ($%d , %dkg) P/W = %f to the knapsack weight left is %.2d. \n", bestfit + 1, profit[bestfit], weight[bestfit], (float)profit[bestfit] / weight[bestfit], weileft);
            secondlastprofit = totalprofit;
            secondlastweight = weileft;
        }
        else
        {

            lastprofit = (float)profit[bestfit] * secondlastweight / weight[bestfit];
            printf("partially added %d ($%d , %dkg) P/W = %f ; profit added  = %f to the knapsack. \n", bestfit + 1, profit[bestfit], weight[bestfit], (float)profit[bestfit] / weight[bestfit], lastprofit);
        }
    }

    printf("final profit= %f", lastprofit+secondlastprofit);
}

int main()
{
    knapsack();

    return 0;
}
