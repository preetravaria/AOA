#include <stdio.h>

int n = 5;
int weight[10] = {12, 1, 2, 1, 4};
int profit[10] = {4, 2, 2, 1, 10};
int W = 15;
int lastwei;

void knapsack()
{
    int cur_w;
    float tot_p = 0;
    int i, bestfit;
    int used[5] = {0,0,0,0,0};
    float lastprofit,finalprofit;

    cur_w = W;
    while (cur_w > 0)
    {
        bestfit = -1;
        for (i = 0; i < n; ++i)
        {
            if ((used[i] == 0) &&((bestfit == -1) || ((float)profit[i] / weight[i] > (float)profit[bestfit] / weight[bestfit])))
            {
                bestfit = i;
            }
        }

        used[bestfit] = 1;
        cur_w -= weight[bestfit];
        tot_p += profit[bestfit];

        if (cur_w >= 0)
        {
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", bestfit + 1, profit[bestfit], weight[bestfit], cur_w);

            lastwei = cur_w;
             finalprofit = tot_p;


        }
        else
        {
            printf("Added %d from (%d$, %dKg) of object %d in the bag.\n", lastwei, profit[bestfit], weight[bestfit], bestfit + 1);
            
             lastprofit =  (float)lastwei*profit[bestfit]/weight[bestfit];
             
            // tot_p -= profit[bestfit];
           // tot_p += (1 + (float)cur_w / weight[bestfit]) * profit[bestfit];
        }
    }

    
    printf("Filled the bag with objects worth %.2f$.\n", finalprofit+lastprofit);
}

int main(int argc, char *argv[])
{
    knapsack();

    return 0;
}
