#include<string.h> 
#include<stdio.h>

void read(int, char (*)[50]); 
void SortNames(int, char (*)[50]); 
void display(int, char (*)[50]); 

void main() 
{ 
int n; 
printf("Enter the no. of strings: "); 
scanf("%d", &n); 
char names[n][50];

printf("Enter %d names: \n", n); 
read(n, names); 

printf("\nNames before sorting:\n"); 
display (n, names); 

SortNames(n, names); 

printf("\nNames after sorting:\n"); 
display(n, names); 
} 
void read(int n, char (*a)[50])
{ 
int i; 
for (i = 0; i < n; i++) 
scanf("%s", *(a + i));
} 
void display(int n, char (*a)[50]) 
{ 
int i; 
for(i=0; i < n; i++) 
printf("%s\n", *(a + i));
} 
void SortNames(int n, char (*a)[50]) 
{ 
 int i, j; 
 char temp[50]; 
 for (i = 0; i < n-1; i++) 

     for (j = 0; j < n-i-1; j++)
     { 
        if (strcmp(*(a + j), *(a + j + 1)) > 0)
        {
          strcpy(temp, *(a + j)); 
          strcpy(*(a + j), *(a + j + 1)); 
          strcpy(*(a + j + 1), temp); 
        }
     } 
}