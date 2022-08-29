#include<stdio.h>
int found=0; 
void sort(int a[],int ele,int n)
{ int i;

for(i=0;i<n;i++)
{
if(ele==a[i])
{
printf("the searched element at %d  position",i);
found=1;
break;
}
}
if(found==0)
printf("\n search is unsuccessful ");
}
int main()
{
int a[50],i,n,ele;
printf("\n enter no.of elemets in an array ");
scanf("%d",&n);
printf("\n enter elemets in an array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\n enter the elements u want to search");
scanf("%d",&ele);
sort(a,ele,n);

return 0;
}
