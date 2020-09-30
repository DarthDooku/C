#include <stdio.h>
#include <limits.h> //Used for INT_MAX
  
#define MAX_SIZE 1000 //Maximum size of the array
  
  
/*
 * Functions used in this program
 */
void arrange(int arr[], int len, int pivot);
void sort(int arr[], int start, int end);
void print(int arr[], int len);
  
  
  
int main()
{
    int arr[MAX_SIZE], i, n;
    int p, evenCount, oddCount;
  
    p = 0;
    evenCount = oddCount = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter elements in the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
 
        if(arr[i] & 1)
            oddCount++;
        else
            evenCount++;
    } 
    p = (evenCount > oddCount) ? evenCount : oddCount;
  
    print(arr, n);
  
    arrange(arr, n, p);

    printf("\nElements after arranging even and odd elements separately\n");
    print(arr, n);
    sort(arr, p, n);
  
    sort(arr, 0, p);
 
    printf("\nFinal array after sorting even and odd elements separately\n");
    print(arr, n);
  
    return 0;
}
void arrange(int arr[], int len, int p)
{
    int i, j, temp;
  
    for(i=0; i<p; i++)
    {
        if(arr[i] & 1)
        {
            for(j=p; j<len; j++)
            {
                if(!(arr[j] & 1))
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    break;
                }
            }
        }
    }
}
void sort(int arr[], int start, int end)
{
    int i, j, temp;
    int len = start + end;
  
    for(i=start; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void print(int arr[], int len)
{
    int i;
    printf("Elements in the array: ");
    for(i=0; i<len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
