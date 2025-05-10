#include<stdio.h>
void maxmin(int *arr[][50], int n1, int n2, int *max, int *min);
void main()
{
    int i,j,n1,n2,min,max;

    printf("Enter no of students\n");
    scanf("%d",&n1);

    printf("Enter no of subjects\n");
    scanf("%d",&n2);

    int arr[n1][n2];

    printf("Enter %d students X %d subjects\n",n1,n2);
    for(i=0; i<n1; i++)
    {
        printf("Enter student number: %d, marks\n",i+1);
        for(j=0; j<n2; j++)
        {
            printf("Subject %d: ",j+1);
            scanf("%d",(arr+i)+j);
        }
    }







    
    maxmin(arr,n1,n2,&max,&min);
}
void maxmin(int *arr[][50], int n1, int n2, int *max, int *min)
{
    int i,j,std;

    printf("Enter rol no of student from 1 to %d\n",n1);
    scanf("%d",std); 
    while(i=std)
    {
        for (j=0; j <n2; j++)
        {
            printf("subject %d: %d",j+1,*(*(arr+std)+j));
        } 
        i++;
    }
    
}