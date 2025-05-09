#include<stdio.h>
void insertionsort(int *a, int n);
int main()
{
    int i, n;

    printf("Enter number of elements\n");
    scanf("%d",&n);

    int a[n];

    printf("Enter %d elements\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }

    insertionsort(a,n);

    for ( i = 0; i < n; i++)
    {
        printf("%5d",a[i]);
    }

    return 0;
}
void insertionsort(int *a, int n)
{
    int i,j,temp;

    for(i=1; i<n; i++)
    {
        temp=a[i];
        j=i-1;
        while (j>=0 && *(a+j)>temp)
        {
            *(a+j+1)=*(a+j);
            j--;
        }
        *(a+j+1)=temp;
    }
}