#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter no.of integers:");
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
    
    printf("\nEnter position to be inserted:");
    scanf("%d",&p);
    printf("\nEnter value to be inserted:");
    scanf("%d",&val);
    temp1=val;
    for(i=p;i<n;i++)
    {
        temp2=a[i];
        a[i]=temp1;
        temp1=temp2;
    }
    printf("\nFinal array:\n");
    for(i=0;i<n-2;i++)
    {
      printf("%d  ",a[i]);
    }
    return 0;
}