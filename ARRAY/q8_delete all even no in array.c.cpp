#include<stdio.h>
#define max 10
int main()
{
int i,n,a[max];
printf("Enter the array size :");
scanf("%d",&n);
printf("Enter the array  :");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
if(a[i]%2==0)
{
a[i]=-1;
}
else
printf("%d  ",a[i]);
}
return(0);
}

