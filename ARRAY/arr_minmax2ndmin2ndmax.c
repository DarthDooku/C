#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int main()
{
    int n;
    printf("Enter no.of integers:");
    scanf("%d",&n);
    int a[n],i,max,min,smax,smin;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%101;
      //scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    min=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }

    smax=a[0];
    for(i=0;i<n;i++)
    {
        if((a[i]>smax)&&(a[i]<max))
        {
            smax=a[i];
        }
    }

    smin=a[0];
    for(i=0;i<n;i++)
    {
        if((a[i]<smin)&&(a[i]>min))
        {
            smin=a[i];
        }
    }
    printf("\nMaximum value:%d\nMinimum value:%d\n",max,min);
    printf("\nSecond Maximum value:%d\nSecond Minimum value:%d\n",smax,smin);
    
    return 0;
}
/*#include<stdio.h>
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
    j=n-1;
    i=0;
    while(i != j)
    {
        while(a[j]%2 != 0)
        {
            j--;
        }
        while(a[i]%2 != 0)
        {
            i++;
        }
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j--;
        i++;
    }
    int k=n-1;
    int l=0;
    while(l != k)
    {
        wh(k,a,n);
        wh(l,a,n);
        temp=a[l];
        a[l]=a[k];
        a[k]=temp;
        k--;
        l++;
    }
    printf("\nFinal array:\n");
    for(i=0;i<n;i++)
    {
      printf("%d  ",a[i]);
    }

    return 0;
}
int whp(int i,int a[],int n)
{
    while(a[i]%2 != 1)
        {
            i++;
        }
    return i;
}
int whn(int i,int a[],int n)
{
    while(a[i]%2 != 1)
        {
            i--;
        }
            return i;
}*/
