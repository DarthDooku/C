#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter no.of integers:");
    scanf("%d",&n);
    int a[n],j,temp;
    int i=0;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%101;
    }

    for(i=0;i<n;i++)
    {
      printf("%d  ",a[i]);
    }
    j=n-1;
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j--;
    }
    printf("\nReversed array:\n");
    for(i=0;i<n;i++)
    {
      printf("%d  ",a[i]);
    }

    return 0;
}
