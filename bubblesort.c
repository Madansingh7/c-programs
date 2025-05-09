#include<stdio.h>
void bubblesort(int * , int size);
void main()
{
    int size,res,i;
    printf("Enter size of array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements\n",size);
    for(i=0; i<size; i++)
    {
        scanf("%d",arr+i);
    }

    bubblesort(arr,size);

    for(i=0; i<size; i++)
    {
    printf(" arr[%d] = %d\n",i,*(arr+i));
    }
}
void bubblesort(int *arr, int size)
{
    int temp,i,j;

    for (i=0; i<size-1; i++)
    {
        for ( j=0; j<size-i-1; j++)
        {
            if (*(arr+j)>*(arr+j+1))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;  
            }
           
        }
        
    }
    
}