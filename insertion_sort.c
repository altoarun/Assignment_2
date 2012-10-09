// Program to sort a given array of elements...using the technique of insertion sort

//Program Input : An array of n elements
//Program output : Sorted array

# include <stdio.h>

void main()
{
    int arr[20],n,i,j,k,temp;

    printf("\nEnter number of elements ?");
    scanf("%d",&n); //getting the no of elements to n

    printf("\nEnter elements in to array....\n");

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]); //getting elements to array

    printf("\nPrinting array elements \n");

    for(i=0;i<n;i++)
    printf("\t%d",arr[i]); //printing array elements

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {

            if(arr[j]>arr[i]) //checks if jth element is greater than ith element (j<i)
            {
                temp=arr[j];
                arr[j]=arr[i]; //copies ith element to jth position

                for(k=i;k>j;k--)
                arr[k]=arr[k-1];
                /*since the ith position becomes vacant when arr[j] > arr[i], elements btw j and i-1 (including j) has to be shifted by 1 position
                which is the key technique in insertion sort....the above for loop does the same*/
                arr[k+1]=temp; //shifting of the jth element
            }
        }
    }

    printf("\nSorted array...\n");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]); // prints the sorted array

}
