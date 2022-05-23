#include <stdio.h>
#include <stdlib.h>

void PrintArray(int A[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void QuickSort(int A[], int left, int right)
{
    if(left<right)
    {
        int PivotValue = A[left];
        int l = left + 1; 
        int r = right; 
        int temp;
        
        while(l <= r){
            while(l <= right && A[l] < PivotValue) l++;
            while(r > left && A[r] >= PivotValue) r--;
            // in the case where the above two while loops exit when a partition
            // HAS NOT BEEN FORMED we swap the integers and reenter the loop again
            if(l < r){
                temp = A[l];
                A[l] = A[r];
                A[r] = temp;
            }
        }
        // swap left and r, a[r] being the pivot forming the partition
        A[left] = A[r];
        A[r] = PivotValue;
        // recursion across left and right sides of the pivot
        QuickSort(A, left, r-1);
        QuickSort(A, r+1, right);
    }
}

int main()
{
    int n, *a;
    printf("Input the number of integers:\n");
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int)*n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    QuickSort(a, 0, n-1);
    PrintArray(a, n);
    return 0;
}
