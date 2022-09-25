#include<iostream>

using namespace std;

void Insert (int H[], int n)
{
    int i = n, temp;
    temp = H[i];
    while(i>1 && temp> H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}

int Delete(int A[], int n)
{
    int i,j,x,val;
    x = A[n];
    val = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i*2;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
        {
            j = j+1;
            if(A[i]<A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;
                j = 2*j;

            }
            else
            {
                break;
            }
        }
    }

    return val;

}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};  // 0 is not included in heap.
    // Heap order will be: 40,25,35, 10,5,20,30
    int size = sizeof(H)/sizeof(int);
    for(int i = 2; i<=7; i++)
    {
        Insert(H,i);
    }

    // Heap sort: 
    // for(int i = 7; i>1; i--)
    // {
    //     Delete(H,i);
    // }

    
    for(int j = 1; j<=7; j++)
    {
        cout<<H[j]<<" ";
    }


   // Direction of adjustment in Heap insert is from the last element of the complete binary tree to the root and in delete, it is from the root the leaf elements. This difference is essential in knowing heapify method.
   // In heapify there a lot less adjustments then the normal method as it from bottom to the root like in delete method. It's order of time is O(n)


    return 0;
}