//program to implement bubble sort technique
//Input : An array of unsorted element
//Output : sorted array

#include <stdio.h>

void main()
{
    int a[10],n,temp=0,i,j;

    printf("\nEnter number of elements ?");
    scanf("%d",&n); //get the number of elements into n

    printf("\nEnter elements into array...\n");

    for(i=1;i<=n;i++)
    scanf("%d",&a[i]); //get elements into array a

    printf("\nElements in array \n");
    for(i=1;i<=n;i++)
    printf("%d\t",a[i]); //printing unsorted elements

    for(i=0;i<(n-1);i++) //outer for loop executes n-1 times
    {
        for(j=1;j<=(n-i);j++) //inner one executes n-i times...iteration reduces by 1, each time the outer loop iterates
        {
            if(a[j-1]>a[j])
            {
                temp = a[j];
                a[j] = a[j-1]; //interchanges if a[j] is less than a[j-1]
                a[j-1]=temp;
            }
        }
    }

    printf("\n\nPrinting sorted array...\n");

    for(i=0;i<n;i++)
    printf("%d\t",a[i]); //printing the sorted array

}
