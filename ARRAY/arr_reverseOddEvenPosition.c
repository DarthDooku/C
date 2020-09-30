#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter no.of integers:");
    scanf("%d",&n);
    int a[n],i,j,temp;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%101;
    }

    for(i=0;i<n;i++)
    {
      printf("%d  ",a[i]);
    }
    if(n%2==1)
    j=n-1;
    else
    {
        j=n-2;
    }
    
    for(i=0;i<n/2;i=i+2)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j=j-2;
    }
    if(n%2==0)
    j=n-1;
    else
    {
        j=n-2;
    }
    for(i=1;i<n/2;i=i+2)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j=j-2;
    }
    printf("\nReversed array:\n");
    for(i=0;i<n;i++)
    {
      printf("%d  ",a[i]);
    }

    return 0;
}