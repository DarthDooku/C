#include<stdio.h>
#include<stdlib.h>
int main() //main function
{
    int n;
    printf("Enter no.of integers:"); //inputting
    scanf("%d",&n);
    int a[n],i,j,temp1,temp2,p,val;
    for(i=0;i<n-3;i++)
    {
        a[i]=rand()%101;
    }

    for(i=0;i<n-3;i++)
    {
      printf("%d  ",a[i]);
    }
    
    printf("\nEnter position to be deleted:");
    scanf("%d",&p);

    for(i=p;i<n;i++)
    {
        a[i]=a[i+1];
    }
    printf("\nFinal array:\n");
    for(i=0;i<n-4;i++)
    {
      printf("%d  ",a[i]);
    }
    return 0;
}
