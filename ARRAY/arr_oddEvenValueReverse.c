#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter number of integers:");
    scanf("%d",&n);
    int a[n],i,j,temp,p;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%101;
        printf("%d  ",a[i]);
    }
    for(p=0;p<2;p++)
    {
        j=n-1;
        i=0;
        while(i < j)
        {
            if(((a[j]%2 == p))&&((a[i]%2==p)))
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                j--;
                i++;
            }
            if(a[i]%2 != p)
                i++;
            if(a[j]%2 != p)
                j--;
        }
    }
    printf("\nFinal array:\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    return 0;
}