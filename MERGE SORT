#include <stdio.h>
int b[10],a[10];
int main() 
{ 
   int i,n;
   printf("enter the size\n");
   scanf("%d",&n);
   printf("\nList before sorting\n");
   for(i =0;i<=n;i++)
      scanf("%d",&a[i]);
   sort(0, n);
   printf("\nList after sorting\n");
      for(i = 0; i <=n; i++)
      printf("%d ",a[i]);
      return 0;
}
void sort(int low, int high)
{
   int mid;
   
   if(low < high)
   {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   }
}
void merging(int low, int mid, int high) 
{
   int i,j,k;
i=low;
j=mid+1;
   for( k = low; i <= mid && j <= high; k++) {
      if(a[i] <= a[j])
         b[k] = a[i++];
      else
         b[k] = a[j++];
   }
   
   while(i <= mid)    
      b[k++] = a[i++];

   while(j <= high)   
      b[k++] = a[j++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}
