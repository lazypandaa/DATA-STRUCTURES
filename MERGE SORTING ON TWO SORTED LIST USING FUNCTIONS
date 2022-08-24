#include<stdio.h>
int a[10],b[10],c[10];
void sort(int m,int n)
{
int i=0,j=0,k=0;
while(i<m &&j<n)
{
if(a[i]<b[j])
{
c[k++]=a[i++];
}
else
{
c[k++]=b[j++];
}
}
while(i<m)
{
c[k++]=a[i++];
}
while(j<n)
{
c[k++]=b[j++];
}
}
int main()
{
int i,j,m,n,k=0;
printf("enter no.of first array elements");
scanf("%d",&m);
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
}
printf("enter no.of elements into 2nd array");
scanf("%d",&n);
 for(j=0;j<n;j++)
 {
scanf("%d",&b[j]);
}
sort(m,n);
for(i=0;i<m+n;i++)
{
printf("\n%d",c[i]);
}
return 0;
}
