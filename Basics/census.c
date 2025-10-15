/*Define a structure, name, census, and a character array city to store names, and a long integer to store population of the city, a float member to store the literacy level, write a C program to do the following.
1. To read details of five cities randomly using array variables. 
2. Sort the list alphabetically. 
3. Sort list based on literacy level. 4. Sort the list based on population. 
5. Display the sorted list of each.*/

#include<stdio.h>
#include<string.h>
struct census
{
    char city[15];
    long int population;
    float literacy;
} c[5], temp;

int n=5;

struct census readstruct()
{
printf("Enter city : population : literacy rate Accordingly\n");
for(int i=0; i<n; i++)
{
printf("Enter name of city %d : \n",i+1);
scanf("%s",&c[i].city);

printf("Enter population of city %d :\n",i+1);
scanf("%ld",&c[i].population);

printf("Enter literacy of city %d :\n",i+1);
scanf("%f",&c[i].literacy);
}
};

struct census sortnames()
{

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(strcmp(c[j].city, c[j+1].city) > 0) {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
   
};

struct census sortpopulation()
{

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(c[j].population > c[j+1].population) {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
   
};

struct census sortlit()
{

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(c[j].literacy > c[j+1].literacy) {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }

};

int main()
{  
    readstruct();

    //printing cities in alphabetical order
    sortnames();
     printf("Names       population      literacy\n");
    for(int i=0; i<n; i++)
    {
    printf("%s           %ld             %.3f \n",c[i].city,c[i].population,c[i].literacy);
    }
    printf("\n");

    //printing cities in population order
    sortpopulation();
     printf("Names       population      literacy\n");
    for(int i=0; i<n; i++)
    {
    printf("%s           %ld             %.3f \n",c[i].city,c[i].population,c[i].literacy);
    }
    printf("\n");

    //printing cities in literacy order
    sortlit();
    printf("Names       population      literacy\n");
    for(int i=0; i<n; i++)
    {
    printf("%s           %ld             %.3f \n",c[i].city,c[i].population,c[i].literacy);
    }
   return 0;
}
