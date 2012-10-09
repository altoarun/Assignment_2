//Program to implement merge sort technique

//Input to program : An array of unsorted elements
//Output : Sorted array

#include <stdio.h>

void merge_sort(int,int);
void merge(int,int,int);

int arr[40],i,n,mid;

void main()
{

  printf("\nEnter no of elements ?");
  scanf("%d",&n);

  printf("\nEnter elements to array....\n");

  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);

  printf("\nArray before sorting...\n");

  for(i=0;i<n;i++)
  printf("%d\t",arr[i]);

  merge_sort(0,n-1); //calling the merge sort function

  printf("\n Sorted array \n");
  for(i=0;i<n;i++)
  printf("%d\t",arr[i]);

}

void merge_sort(int low, int high)
{
    int tp;

    if(low<high)
    {
        tp=(low+high)/2;
        merge_sort(low,tp); //the divide step....divides the array in to two and sorts seperately
        merge_sort(tp+1,high);
        merge(low,tp,high); //merges the sorted arrays
    }
}

void merge(int low, int mid, int high)
{
    int temp[40];
    int i=low,l=low, m= mid+1,k;

    while((l<=mid)&&(m<=high)) //(l-mid) is considered the first array and (m- high) the second one
    {
        if(arr[l]<=arr[m])
        {
            temp[i] = arr[l]; //if element of first array is less than that of the second one... arr[l] is added to the sorted(temp) array
            l++; //first arrays index pointer is incremented
        }
        else
        {
            temp[i]=arr[m]; //if element of second array is less than that of the first one... arr[m] is added to the sorted(temp) array
            m++; //second arrays index pointer is incremented
        }
        i++;

    }

    if(l>mid) //checks if first array has been fully emptied
    {
        for(k=m;k<=high;k++) //there could be elements left back in the second array...copies them to temp
        {
            temp[i]=arr[k];
            i++;
        }
    }
    else //second array has been fully emptied
    {
        for(k=l;k<=mid;k++) //elements , if any left back in the first array will be copied to temp
        {
            temp[i]=arr[k];
            i++;
        }
    }

    for(k=low;k<=high;k++) //printing the sorted array
    arr[k]=temp[k];
}

