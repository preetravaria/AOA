#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partion(int A[], int low, int high)
{

    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] < pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (j > i)
        {
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int low, int high)
{
    int partitionindex;

    if (low < high)
    {
        partitionindex = partion(A, low, high);
        quicksort(A, low, partitionindex);
        quicksort(A, partitionindex + 1, high);
    }
}

void main(){
    
    int A[]= {7,3,1,6,2,4};
    printArray(A,6);
    quicksort(A,0,5);
    printArray(A,6);
    

}